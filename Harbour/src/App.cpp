/*
* The basis for the App::init(), App::run(), and App::shutdown() came from ChatGPT, but pieces of it have been modified by me (ThatCodingFrog)
*/


#include "App.h"
#include <iostream>

#include "utils/LoadImage.h"

Harbour::App::App()
{
	this->init();
    this->constructLibraryFromJSON(m_library, "library/myGames.json");
    this->constructLibraryFromJSON(m_allGames, "library/allGames.json");

    for (size_t i = 0; i < m_allGames.size(); i++) {
        std::cout << "m_allGames " << m_allGames[i].getName() << " " << m_allGames[i].getVersion();
    }
    
    m_fileManager.checkLatestVersions();
}

Harbour::App::~App()
{
    this->shutdown();
}

void Harbour::App::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow("Harbour of Harkinian",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_GLContext gl_context = SDL_GL_CreateContext(m_window);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("./assets/Fonts/montserrat/Montserrat-Regular.otf", 16.0f);

    ImGui_ImplSDL2_InitForOpenGL(m_window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 150");
}

void Harbour::App::shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Harbour::App::run()
{
    SDL_Event event;
    while (m_isRunning) {
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT) m_isRunning = false;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();      

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
        
        ImGui::Begin("MainOverlay", nullptr,
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_NoBackground |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_MenuBar
        );
        //for directly into the window

        if (ImGui::BeginMenuBar()) {
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            HarbourGUI::screenID next = {};
            if (ImGui::Button("My Library")) {
                next = HarbourGUI::MyLibrary;
                this->switchScreens(next);
            }
            if (ImGui::Button("All Games")) {
                next = HarbourGUI::AllGames;
                this->switchScreens(next);
            }
            if (ImGui::Button("Settings")) {
                next = HarbourGUI::Settings;
                this->switchScreens(next);
            }
            if (ImGui::Button("Help Center")) {
                next = HarbourGUI::HelpCenter;
                this->switchScreens(next);
            }
            ImGui::PopStyleColor();
            
            ImGui::EndMenuBar();
        }

        this->drawCurrentScreen();

        ImGui::End();


        ImGui::Render();
        glViewport(0, 0, 1280, 720);
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(m_window);
    }
}

void Harbour::App::switchScreens(HarbourGUI::screenID& id)
{
    m_screenID = id;
}

void Harbour::App::drawCurrentScreen()
{
    switch (m_screenID) {
    case HarbourGUI::MyLibrary:
    {
        HarbourGUI::MyLibraryScreen(m_library);
        break;
    }
    case HarbourGUI::AllGames:
    {
        HarbourGUI::downloadsScreen(m_allGames);
        break;
    }
    case HarbourGUI::Settings:
    {
        HarbourGUI::settingsScreen();
        break;
    }
    case HarbourGUI::HelpCenter:
    {
        HarbourGUI::helpScreen();
        break;
    }
    default:
        HarbourGUI::MyLibraryScreen(m_library);
    }
}

void Harbour::App::constructLibraryFromJSON(std::vector<GameCard>& output, std::string lib)
{
    auto res = m_fileManager.readJSON(lib);

    for (size_t i = 0; i < res.size(); i++) {
        std::cout << res[i].at("name") << std::endl << res[i].at("version") << std::endl;
        output.emplace_back(res[i].at("name"), res[i].at("version"));
    }
}


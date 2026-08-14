#include "App.h"
#include <iostream>

#include <glad/glad.h>
#include "utils/LoadImage.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "misc/freetype/imgui_freetype.h"

#include "utils/FileManager.h"
#include "utils/NetworkManager.h"
#include "utils/LibraryManager.h"

#include <SDL.h>
#include "utils/LoadImage.h"

Harbour::App::App()
{
    this->init();
    m_initThread = std::thread(&Harbour::App::initAppClasses, this);
}

Harbour::App::~App()
{
    if (m_initThread.joinable())
    {
        m_initThread.join();
    }

    this->shutdown();
}

void Harbour::App::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow("Harbour Ports",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                1280, 720, SDL_WINDOW_OPENGL); // Allow SDL_WINDOW_RESIZABLE?

    SDL_GLContext gl_context = SDL_GL_CreateContext(m_window);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
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
    while (m_isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                m_isRunning = false;
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
                         ImGuiWindowFlags_MenuBar);
        // for directly into the window

        if (ImGui::BeginMenuBar())
        {
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            HarbourGUI::screenID next = {};
            if (ImGui::Button("My Library"))
                m_screenID = HarbourGUI::MyLibrary;
            if (ImGui::Button("All Games"))
                m_screenID = HarbourGUI::AllGames;
            if (ImGui::Button("Settings"))
                m_screenID = HarbourGUI::Settings;
            if (ImGui::Button("Help Center"))
                m_screenID = HarbourGUI::HelpCenter;

            ImGui::PopStyleColor();

            ImGui::EndMenuBar();
        }

        // Main content
        if (!m_initComplete.load()) // Check whether the init is complete, otherwise show the main screen
        // Can probably be expanded to have the splash screen shown at other times if necessary
        {
            this->drawSplashScreen();
        }
        else
        {
            this->drawCurrentScreen();
        }

        ImGui::End();

        this->drawFooter();

        ImGui::Render();
        glViewport(0, 0, 1280, 720);
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(m_window);
    }
}

void Harbour::App::drawCurrentScreen()
{
    switch (m_screenID)
    {
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

void Harbour::App::drawSplashScreen()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

    ImGui::Begin("SplashScreen", nullptr,
                 ImGuiWindowFlags_NoDecoration |
                     ImGuiWindowFlags_NoMove);

    if (!m_splashImg)
    {
        int width = 0, height = 0;
        LoadTextureFromFile("assets/GameCard/UnknownTitle.png", &m_splashImg, &width, &height);
    }

    ImGui::Image((ImTextureID)(intptr_t)m_splashImg, ImVec2(256, 256));

    ImGui::End();
}

void Harbour::App::drawFooter()
{
    const float footerHeight = ImGui::GetFrameHeight();

    ImGuiViewport *vp = ImGui::GetMainViewport();

    ImGui::SetNextWindowPos(
        ImVec2(vp->Pos.x, vp->Pos.y + vp->Size.y - footerHeight));
    ImGui::SetNextWindowSize(
        ImVec2(vp->Size.x, footerHeight));

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

    ImGui::Begin("Footer", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);

    ImGui::ProgressBar(m_progress, ImVec2(-FLT_MIN, ImGui::GetFrameHeight()), this->updateMessage().c_str());

    ImGui::End();

    ImGui::PopStyleVar();
}

std::string Harbour::App::updateMessage()
{
    std::string message = "";
    if (m_progress == 0.0f)
    {
        message = "No Downloads";
    }
    else if (m_progress == 1.0f)
    {
        message = "Download Complete!";
    }
    else
    {
        message = "Download In Progress...";
    }
    return message;
}

void Harbour::App::initAppClasses()
{
    m_fileManager = std::make_unique<HarbourUtils::FileManager>();
    m_networkManager = std::make_unique<HarbourUtils::NetworkManager>(m_fileManager.get());
    m_libraryManager = std::make_unique<HarbourUtils::LibraryManager>(m_fileManager.get());

    m_allGames = m_libraryManager->constructLibraryFromJSON("cache/manifest.json");
    m_initComplete.store(true);
}

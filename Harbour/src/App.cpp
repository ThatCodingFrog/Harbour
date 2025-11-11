#include "App.h"

Harbour::App::App()
{
	this->init();
}

Harbour::App::~App()
{
    this->shutdown();
}

void Harbour::App::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow("Harbour",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_GLContext gl_context = SDL_GL_CreateContext(m_window);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("../../external/imgui/misc/fonts/Karla-Regular.ttf", 14.0f);

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

        // --- Your first UI ---
        ImGui::Begin("Harbour Test");
        ImGui::Text("If you can see this, Dear ImGui works!");
        ImGui::Button("Play Now");
        ImGui::End();

        ImGui::Render();
        glViewport(0, 0, 1280, 720);
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(m_window);
    }
}

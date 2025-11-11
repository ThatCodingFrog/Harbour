#include <SDL.h>
#include <glad/glad.h>
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "misc/freetype/imgui_freetype.h"


namespace Harbour {
	class App {
	public:
		App();
		~App();

	private:
		void init();
		void shutdown();

	public:
		void run();
		
	private:
		SDL_Window* m_window = nullptr;
		bool m_isRunning = true;
	};
}
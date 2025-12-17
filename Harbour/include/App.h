#pragma once

#include <SDL.h>
#include <glad/glad.h>
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "misc/freetype/imgui_freetype.h"
#include <string>
#include <vector>

#include "GameCard.h"
#include "utils/FileManager.h"
#include "utils/ColorManager.h"
#include "MenuScreen.h"

namespace Harbour {
	class App {
	public:
		App();
		~App();

	private:
		void init();
		void shutdown();
		void drawCurrentScreen();

	public:
		void run();
		void switchScreens(HarbourGUI::screenID& id);

	private:
		SDL_Window* m_window = nullptr;
		bool m_isRunning = true;
		std::vector<GameCard> m_library = {};
		std::vector<GameCard> m_allGames = {};

		int m_screenID = 0;

	private:
		HarbourUtils::FileManager m_fileManager = {};
		HarbourUtils::ColorManager m_colorManager = {};

		void constructLibraryFromJSON(std::vector<GameCard>& output, std::string lib);

	};
}

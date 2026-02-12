#pragma once

#include <SDL.h>

#include <string>
#include <vector>

#include "GameCard.h"
#include "utils/FileManager.h"
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

		float m_progress = 0.0f;
		std::string updateMessage();

	};
}

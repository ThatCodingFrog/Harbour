#pragma once

#include <string>
#include <vector>
#include <memory>
#include <atomic>
#include <thread>

#include "GameCard.h"
#include "MenuScreen.h"

struct SDL_Window;

namespace HarbourUtils
{
	class FileManager;
	class NetworkManager;
	class LibraryManager;
}

namespace Harbour
{
	class App
	{
	public:
		App();
		~App();

	private:
		void init();
		void shutdown();
		void drawCurrentScreen();
		void drawSplashScreen();
		void drawFooter();

	public:
		void run();

	private:
		SDL_Window *m_window = nullptr;
		bool m_isRunning = true;
		std::vector<GameCard> m_library = {};
		std::vector<GameCard> m_allGames = {};

		int m_screenID = 0;

	private:
		std::unique_ptr<HarbourUtils::FileManager> m_fileManager;
		std::unique_ptr<HarbourUtils::NetworkManager> m_networkManager;
		std::unique_ptr<HarbourUtils::LibraryManager> m_libraryManager;

		float m_progress = 0.0f;
		std::string updateMessage();

		GLuint m_splashImg = 0;

	private:
		std::thread m_initThread;
		std::atomic<bool> m_initComplete = false;
		void initAppClasses();
	};
}

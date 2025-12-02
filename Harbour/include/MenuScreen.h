#pragma once

#include "imgui.h"
#include "App.h"

namespace Harbour {
	class App;
}

namespace HarbourGUI {
	enum screenID {
		MyLibrary,
		AllGames,
		Settings,
		HelpCenter,
	};

	void MyLibraryScreen(Harbour::App& instance);
	void downloadsScreen();
	void settingsScreen();
	void helpScreen();
}
#pragma once

#include "imgui.h"


namespace HarbourGUI {
	enum screenID {
		MyLibrary,
		AllGames,
		Settings,
		HelpCenter,
	};

	void MyLibaryScreen();
	void downloadsScreen();
	void settingsScreen();
	void helpScreen();
}
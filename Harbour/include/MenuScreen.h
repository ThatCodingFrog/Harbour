#pragma once

#include "imgui.h"
#include <vector>
#include "GameCard.h"


namespace HarbourGUI {
	enum screenID {
		MyLibrary,
		AllGames,
		Settings,
		HelpCenter,
	};

	void MyLibraryScreen(std::vector<Harbour::GameCard>& myLibrary);
	void downloadsScreen(std::vector<Harbour::GameCard>& downloads);
	void settingsScreen();
	void helpScreen();
}

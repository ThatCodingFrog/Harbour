#pragma once

#include <vector>
#include "GameCard.h"

namespace HarbourGUI
{
	enum screenID
	{
		MyLibrary,
		AllGames,
		Settings,
		HelpCenter,
	};

	enum RenderStates
	{
		Grid,
		List
	};

	void MyLibraryScreen(std::vector<Harbour::GameCard> &myLibrary);
	void downloadsScreen(std::vector<Harbour::GameCard> &downloads);
	void settingsScreen();
	void helpScreen();
}

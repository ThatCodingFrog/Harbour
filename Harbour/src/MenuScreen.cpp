#include "MenuScreen.h"
#include "GameCard.h"

void HarbourGUI::MyLibraryScreen(std::vector<Harbour::GameCard> &myLibrary)
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("My Library");

	if (myLibrary.size() > 0)
	{
		for (size_t i = 0; i < myLibrary.size(); i++)
		{
			myLibrary[i].draw();
		}
	}
	else
		ImGui::Text("No games installed yet.");
	ImGui::PopFont();
}

void HarbourGUI::downloadsScreen(std::vector<Harbour::GameCard> &downloads)
{

	if (downloads.size() == 0)
	{
		ImGui::PushFont(NULL, 24.0f);
		ImGui::Text("No games found, either in cache or online.  Check your internet connection.");
		ImGui::PopFont();
		return; //*Should* never be called, but better to have a failsafe
	}

	// Create downloads vector here so it doesn't have to be passed as a param
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("All Games");

	for (size_t i = 0; i < downloads.size(); i++)
	{
		downloads[i].draw();
	}

	ImGui::PopFont();

	// Read data from allGames.json, then run loop based on results to draw thumbnails w/ download buttons
}

void HarbourGUI::settingsScreen()
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("Settings");
	ImGui::PopFont();

	ImGui::Text("Coming soon...");
}

void HarbourGUI::helpScreen()
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("Help Center");
	ImGui::PopFont();

	ImGui::Text("Coming soon...");
}

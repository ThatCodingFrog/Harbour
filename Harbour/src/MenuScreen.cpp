#include "MenuScreen.h"
#include "GameCard.h"

//MyLibraryScreen helped by AI in deciding the parameters after
//ThatCodingFrog thought of the idea of how to pass data
void HarbourGUI::MyLibraryScreen(std::vector<Harbour::GameCard>& myLibrary)
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("My Library");

	for (size_t i = 0; i < myLibrary.size(); i++) {
		myLibrary[i].drawThumbnail();
	}
	ImGui::PopFont();

}

void HarbourGUI::downloadsScreen()
{
	ImGui::Text("All Games");

	//Read data from allGames.json, then run loop based on results to draw thumbnails w/ download buttons
}

void HarbourGUI::settingsScreen()
{
	ImGui::Text("Settings");
}

void HarbourGUI::helpScreen()
{
	ImGui::Text("Help Center");
}

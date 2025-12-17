#include <imgui.h>
#include "MenuScreen.h"
#include "GameCard.h"

#include <iostream>

//MyLibraryScreen helped by AI in deciding the parameters after
//ThatCodingFrog thought of the idea of how to pass data
void HarbourGUI::MyLibraryScreen(std::vector<Harbour::GameCard>& myLibrary)
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("My Library");

	if (myLibrary.size() > 0) {
		for (size_t i = 0; i < myLibrary.size(); i++) {
			myLibrary[i].draw();
		}
	}
	else
		ImGui::Text("No games installed yet.");
	ImGui::PopFont();

}

void HarbourGUI::downloadsScreen(std::vector<Harbour::GameCard>& downloads)
{
	//Create downloads vector here so it doesn't have to be passed as a param
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("All Games");

	if (downloads.size() == 0) return; //*Should* never be called, but better to have a failsafe

	for (size_t i = 0; i < downloads.size(); i++) {
		downloads[i].draw();
	}

	ImGui::PopFont();

	//Read data from allGames.json, then run loop based on results to draw thumbnails w/ download buttons
}

void HarbourGUI::settingsScreen(HarbourUtils::ColorManager& colorManager)
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("Settings");
	ImGui::PopFont();

	const char* schemes[] = { "Blue Gray", "Dark Blue" };
	int current = colorManager.getThemeColor();

	if ( ImGui::Combo("Color Schemes", &current, "Blue Gray\0Dark Blue\0Light Blue", 4)) {
		std::cout << current;
		colorManager.setThemeColor(current);
	}

	ImGui::Text("Coming soon...");
}

void HarbourGUI::helpScreen()
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("Help Center");
	ImGui::PopFont();

	ImGui::Text("Coming soon...");
}

//ImVec4 HarbourGUI::getColor(Colors color)
//{
//	ImVec4 i = {};
//	switch (color) {
//	case BlueGray:
//		i = ImVec4(0.1f, 0.1f, 0.15f, 1.0f);
//		break;
//	default:
//		i = ImVec4(0.1f, 0.1f, 0.15f, 1.0f);
//	}
//	return i;
//}

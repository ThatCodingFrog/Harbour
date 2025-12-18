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

	const char* schemes[] = { 
		"Blue Gray", "Dark Blue", "Light Blue",
		"Green", "Teal", "Dark Red", "Light Red", "Dark Gray"
		//Currently needs to follow order of Colors enum or it will break
	};

	int current = colorManager.getThemeColor();

	//ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(0.8f, 0.0f, 0.0f, 1.0f));

	if ( ImGui::Combo("Background Color", &current, schemes, IM_ARRAYSIZE(schemes)) ) {
		std::cout << current;
		colorManager.setThemeColor(current);
	}

	//ImGui::PopStyleColor();

	ImGui::Text("Coming soon...");
}

void HarbourGUI::helpScreen()
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("Help Center");
	ImGui::PopFont();

	ImGui::Text("Coming soon...");
}

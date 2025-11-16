#include "MenuScreen.h"

void HarbourGUI::MyLibaryScreen()
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("My Library");
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

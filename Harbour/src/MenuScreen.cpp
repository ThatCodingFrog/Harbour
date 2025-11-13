#include "MenuScreen.h"
#include "App.h"

void HarbourGUI::MyLibaryScreen()
{
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("My Library");
	ImGui::PopFont();

}

void HarbourGUI::downloadsScreen()
{
	ImGui::Text("All Games");
}

void HarbourGUI::settingsScreen()
{
	ImGui::Text("Settings");
}

void HarbourGUI::helpScreen()
{

}

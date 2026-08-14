#include "MenuScreen.h"
#include "GameCard.h"
#include "imgui.h"

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

	int columns = 3;
	ImGui::PushFont(NULL, 24.0f);
	ImGui::Text("All Games");

	// Placeholder for a search bar

	ImGui::Indent(20.0f);
	if (ImGui::BeginTable("Downloads", columns, ImGuiTableFlags_SizingStretchSame | ImGuiTableFlags_PadOuterX))
	{
		for (int i = 0; i < downloads.size(); i++)
		{
			ImGui::TableNextColumn();
			downloads[i].draw();
		}

		ImGui::EndTable();
	}

	ImGui::Unindent(20.0f);
	ImGui::PopFont();
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

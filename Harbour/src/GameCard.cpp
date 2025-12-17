#include "GameCard.h"

#include "utils/LoadImage.h"

#include <iostream>
#include <imgui.h>

Harbour::GameCard::GameCard()
{
	std::cout << "A new Game Card was created!" << std::endl;
	this->setName("Unknown Card");
	this->setVersion("1.0.0");
	this->setFilePath();
}

Harbour::GameCard::GameCard(std::string name, std::string version)
{
	std::cout << "A new Game Card was created!" << std::endl;
	this->setName(name);
	this->setVersion(version);
	this->setFilePath();
}

Harbour::GameCard::~GameCard()
{
	if (m_texture != 0) {
		glDeleteTextures(1, &m_texture);
	}
}

void Harbour::GameCard::setName(std::string name)
{
	m_name = name;
}

void Harbour::GameCard::setVersion(std::string version)
{
	m_version = version;
}

void Harbour::GameCard::setFilePath()
{
	//Later, this can be cleaned up and dependent on data from JSON
	if (m_name == "Ship of Harkinian") {
		m_thumbnailFilePath = "./assets/GameCard/ShipTitleResized.png";
	}
	else if(m_name == "2 Ship 2 Harkinian") {
		m_thumbnailFilePath = "./assets/GameCard/2ShipTitleResized.png";
	}
	else if (m_name == "Starship") {
		m_thumbnailFilePath = "./assets/GameCard/StarShipTitleResized.png";
	}
	else if(m_name == "Spaghetti Kart") {
		m_thumbnailFilePath = "./assets/GameCard/SpaghettiKartTitleResized.png";
	}
	else {
		m_thumbnailFilePath = "./assets/GameCard/UnknownTitle.png";
	}
}

std::string Harbour::GameCard::getName()
{
	return m_name;
}
std::string Harbour::GameCard::getVersion()
{
	return m_version;
}

void Harbour::GameCard::draw()
{
	ImGui::SetNextWindowSize(ImVec2(300, 300));
	ImGui::BeginChild(m_name.c_str(), ImVec2(0, 0),
		ImGuiChildFlags_ResizeX | ImGuiChildFlags_ResizeY | ImGuiChildFlags_Border,
		ImGuiWindowFlags_NoMove
	);

	this->drawThumbnail();
	ImGui::Text(m_name.c_str());

	ImGui::EndChild();
}

void Harbour::GameCard::drawThumbnail()
{	
	if (!m_texture) {
		//From ImGui docs by ocornut
		int my_image_width = 0;
		int my_image_height = 0;
		bool ret = LoadTextureFromFile(m_thumbnailFilePath, &m_texture, &my_image_width, &my_image_height);
		IM_ASSERT(ret);
	}

	ImGui::Image((ImTextureID)(intptr_t)m_texture, ImVec2(256, 256)); //ImVec2(my_image_width, my_image_height)
}

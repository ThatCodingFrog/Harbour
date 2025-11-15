#include "GameCard.h"
#include <iostream>


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
	if (m_name == "Ship of Harkinian") {
		m_thumbnailFilePath = "../../assets/ShipTitle.png";
	}
	else if(m_name == "2 Ship 2 Harkinian") {
		m_thumbnailFilePath = "../../assets/2ShipTitle.png";
	}
	else if (m_name == "Starship") {
		m_thumbnailFilePath = "../../assets/StarShipTitle.png";
	}
	else {
		m_thumbnailFilePath = "";
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

void Harbour::GameCard::drawThumbnail()
{
	int my_image_width = 0;
	int my_image_height = 0;
	GLuint my_image_texture = 0;
	bool ret = LoadTextureFromFile(m_thumbnailFilePath, &my_image_texture, &my_image_width, &my_image_height);
	IM_ASSERT(ret);
	ImGui::Image((ImTextureID)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
}

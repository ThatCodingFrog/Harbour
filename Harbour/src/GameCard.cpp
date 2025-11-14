#include "GameCard.h"
#include <iostream>


Harbour::GameCard::GameCard()
{
	std::cout << "A new Game Card was created!" << std::endl;
	this->setName("Ship of Harkinian");
	this->setVersion("9.1.0");
}

void Harbour::GameCard::setName(std::string name)
{
	m_name = name;
}

void Harbour::GameCard::setVersion(std::string version)
{
	m_version = version;
}

std::string Harbour::GameCard::getName()
{
	return m_name;
}
std::string Harbour::GameCard::getVersion()
{
	return m_version;
}

void Harbour::GameCard::drawThumbnail(const char* filename)
{
	int my_image_width = 0;
	int my_image_height = 0;
	GLuint my_image_texture = 0;
	bool ret = LoadTextureFromFile("../../assets/shiptitle.darkmode.png", &my_image_texture, &my_image_width, &my_image_height);
	IM_ASSERT(ret);
	ImGui::Image((ImTextureID)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
}

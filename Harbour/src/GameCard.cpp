#include "GameCard.h"
#include <iostream>

Harbour::GameCard::GameCard()
{
	std::cout << "A new Game Card was created!" << std::endl;
	this->setName("Unknown Card");
	this->setVersion("1.0.0");
	this->setThumbnailImg("assets/GameCard/UnknownTitle.png");
}

Harbour::GameCard::GameCard(std::string name, std::string version)
{
	std::cout << "A new Game Card was created!" << std::endl;
	this->setName(name);
	this->setVersion(version);
}

Harbour::GameCard::~GameCard()
{
	if (m_texture != 0)
	{
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
}

void Harbour::GameCard::setThumbnailImg(std::string path)
{
	m_thumbnailFilePath = path;
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
					  ImGuiWindowFlags_NoMove);

	this->drawThumbnail();
	ImGui::Text(m_name.c_str());
	ImGui::Text(m_version.c_str());

	ImGui::EndChild();
}

void Harbour::GameCard::drawThumbnail()
{
	if (!m_texture)
	{
		// From ImGui docs by ocornut
		int my_image_width = 0;
		int my_image_height = 0;
		bool ret = LoadTextureFromFile(m_thumbnailFilePath.c_str(), &m_texture, &my_image_width, &my_image_height);
		IM_ASSERT(ret);
	}

	ImGui::Image((ImTextureID)(intptr_t)m_texture, ImVec2(256, 256)); // ImVec2(my_image_width, my_image_height)
}

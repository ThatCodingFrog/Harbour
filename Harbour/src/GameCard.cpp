#include "GameCard.h"
#include <iostream>
#include "utils/FileManager.h"

Harbour::GameCard::GameCard()
{
}

Harbour::GameCard::GameCard(std::string name, std::string version)
{
	std::cout << "A new Game Card was created!" << std::endl;
	this->setName(name);
	this->setVersion(version);
	auto rThumbnailDefaultPath = HarbourUtils::resolvePath(m_thumbnailFilePath);
	m_thumbnailFilePath = rThumbnailDefaultPath.string();
}

Harbour::GameCard::~GameCard()
{
	if (m_texture != 0)
	{
		glDeleteTextures(1, &m_texture);
	}
}

void Harbour::GameCard::setName(const std::string &name)
{
	m_name = name;
}

void Harbour::GameCard::setVersion(const std::string &version)
{
	m_version = version;
}

void Harbour::GameCard::setLongDesc(const std::string &desc)
{
	m_longDesc = desc;
}

void Harbour::GameCard::setFilePath(const std::string &path)
{
	auto rPath = HarbourUtils::resolvePath(path);
	m_executablePath = rPath.string();
}

void Harbour::GameCard::setThumbnailImg(const std::string &path)
{
	auto rPath = HarbourUtils::resolvePath(path);
	std::cout << "GameCard with name " << m_name << " just had its thumbnail path set to " << rPath << std::endl;
	m_thumbnailFilePath = rPath.string();
}

bool Harbour::GameCard::startGame()
{
	// Platform-specific
	// Launch process based on m_executablePath
	return false;
}

void Harbour::GameCard::draw()
{
	ImGui::SetNextWindowSize(m_size);
	ImGui::BeginChild(m_name.c_str(), ImVec2(0, 0),
					  ImGuiChildFlags_ResizeX | ImGuiChildFlags_ResizeY | ImGuiChildFlags_Border,
					  ImGuiWindowFlags_NoMove);

	this->drawThumbnail();
	ImGui::Text("%s", m_name.c_str());
	ImGui::SameLine();
	ImGui::PushFont(NULL, 16.0f);
	ImGui::Text("%s", m_version.c_str());
	ImGui::PopFont();

	ImGui::Separator();

	if (ImGui::Button("Details"))
	{
	}

	ImGui::SameLine();

	if (ImGui::Button(m_owned ? "Play" : "Download"))
	{
	}

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

	float widthOffset = ImGui::GetCursorPosX() + (m_size.x - m_thumbnailSize.x) / 2;
	ImGui::SetCursorPos(ImVec2(widthOffset, ImGui::GetCursorPosY()));

	ImGui::Image((ImTextureID)(intptr_t)m_texture, m_thumbnailSize); // ImVec2(my_image_width, my_image_height)
}

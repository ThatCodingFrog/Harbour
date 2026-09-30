#pragma once

#include "utils/LoadImage.h"
#include <string>
#include "imgui.h"

namespace Harbour
{
	class GameCard
	{
	public:
		GameCard();
		GameCard(std::string name, std::string version);
		~GameCard();

		void draw();

		void setName(const std::string &name);
		void setVersion(const std::string &version);
		void setLongDesc(const std::string &desc);
		void setFilePath(const std::string &path);
		void setThumbnailImg(const std::string &path);

		bool startGame();

	private:
		void drawThumbnail();

		std::string m_name = "Unknown Card";
		std::string m_version = "1.0.0";

		std::string m_longDesc = "";

		std::string m_thumbnailFilePath = "assets/GameCard/UnknownTitle.png";
		std::string m_executablePath = "";
		bool m_owned = false;

	private:
		GLuint m_texture = 0;
		ImVec2 m_size = {300, 350};
		ImVec2 m_thumbnailSize = {256, 256};
	};

}
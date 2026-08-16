#pragma once

#include "utils/LoadImage.h"
#include <string>

namespace Harbour
{
	class GameCard
	{
	public:
		GameCard();
		GameCard(std::string name, std::string version);
		~GameCard();

		std::string getName();
		std::string getVersion();

		void draw();

		void setName(std::string name);
		void setVersion(std::string version);
		void setFilePath(std::string path);
		void setThumbnailImg(std::string path);

	private:
		void drawThumbnail();

		std::string m_name = "";
		std::string m_version = "";
		std::string m_thumbnailFilePath = "";
		std::string m_executablePath = "";
		bool m_owned = false;

		GLuint m_texture = 0;
	};

}
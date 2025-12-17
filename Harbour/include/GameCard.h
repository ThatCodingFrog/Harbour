#pragma once

#include <string>

namespace Harbour {
	class GameCard {
	public:
		GameCard();
		GameCard(std::string name, std::string version);
		~GameCard();

		std::string getName();
		std::string getVersion();

		void draw();
		
	private:
		void setName(std::string name);
		void setVersion(std::string version);
		void setFilePath();

		void drawThumbnail();

		std::string m_name;
		std::string m_version;
		const char* m_thumbnailFilePath = nullptr;

		unsigned int m_texture = 0; //GLuint equivalent
	};

}
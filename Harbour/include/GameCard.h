#pragma once

#include <string>

namespace Harbour {
	class GameCard {
	public:
		GameCard();
		
		void setName(std::string name);
		void setVersion(std::string version);

		std::string getName();
		std::string getVersion();

	private:
		std::string m_name;
		std::string m_version;

	};

}
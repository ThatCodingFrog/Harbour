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
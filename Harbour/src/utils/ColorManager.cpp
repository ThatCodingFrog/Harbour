#include <imgui.h>
#include <glad/glad.h>

#include "utils/ColorManager.h"

HarbourUtils::ColorManager::ColorManager()
{
	//Load theme from user settings and change accordingly
	m_currentColorTheme = BlueGray;
	this->setBackgroundColor();
}

ImVec4 HarbourUtils::ColorManager::getBackground() const
{
	return m_backgroundColor;
}

int HarbourUtils::ColorManager::getThemeColor() const
{
	return m_currentColorTheme;
}

void HarbourUtils::ColorManager::drawBackground() const
{
	glViewport(0, 0, 1280, 720);
	glClearColor(
		m_backgroundColor.x,
		m_backgroundColor.y,
		m_backgroundColor.z,
		m_backgroundColor.w
	);
	glClear(GL_COLOR_BUFFER_BIT);

}

void HarbourUtils::ColorManager::setThemeColor(int colorTheme)
{
	m_currentColorTheme = (Colors)colorTheme;
	this->setBackgroundColor();
}

void HarbourUtils::ColorManager::setBackgroundColor()
{
	switch (m_currentColorTheme) {
	case BlueGray:
		m_backgroundColor = ImVec4(0.1f, 0.1f, 0.15f, 1.0f);
		break;
	case DarkBlue:
		m_backgroundColor = ImVec4(0.0f, 0.0f, 0.25f, 1.0f);
		break;
	case LightBlue:
		m_backgroundColor = ImVec4(0.43f, 0.52f, 0.89f, 1.0f);
		break;
	case Green:
		m_backgroundColor = ImVec4(0.05f, 0.2f, 0.05f, 1.0f);
		break;
	case Teal:
		m_backgroundColor = ImVec4(0.05f, 0.25f, 0.25f, 1.0f);
		break;
	case DarkRed:
		m_backgroundColor = ImVec4(0.2f, 0.05f, 0.05f, 1.0f);
		break;
	case LightRed:
		m_backgroundColor = ImVec4(0.85f, 0.25f, 0.25f, 1.0f);
		break;
	case DarkGray:
		m_backgroundColor = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
		break;
	default:
		m_backgroundColor = ImVec4(0.1f, 0.1f, 0.15f, 1.0f);
	}
}


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

ImVec4 HarbourUtils::ColorManager::getThemeColor()
{
	return ImVec4();
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
	default:
		m_backgroundColor = ImVec4(0.1f, 0.1f, 0.15f, 1.0f);
	}
}


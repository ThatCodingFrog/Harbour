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
	this->setMenuBarColor();
	this->setAccentColor();
	this->setHoverColor();
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

void HarbourUtils::ColorManager::setAccentColor()
{
	//Build off of StyleColorsDark() in imgui_draw.cpp
	float alpha = 0.94f;

	switch (m_currentColorTheme) {
	case BlueGray:
		m_accentColor = ImVec4(0.1f, 0.1f, 0.15f, alpha);
		break;
	case DarkBlue:
		m_accentColor = ImVec4(0.0f, 0.0f, 0.25f, alpha);
		break;
	case LightBlue:
		m_accentColor = ImVec4(0.43f, 0.52f, 0.89f, alpha);
		break;
	case Green:
		m_accentColor = ImVec4(0.05f, 0.2f, 0.05f, alpha);
		break;
	case Teal:
		m_accentColor = ImVec4(0.05f, 0.25f, 0.25f, alpha);
		break;
	case DarkRed:
		m_accentColor = ImVec4(0.2f, 0.05f, 0.05f, alpha);
		break;
	case LightRed:
		m_accentColor = ImVec4(0.55f, 0.15f, 0.15f, alpha);
		break;
	case DarkGray:
		m_accentColor = ImVec4(0.15f, 0.15f, 0.15f, alpha);
		break;
	default:
		m_accentColor = ImVec4(0.1f, 0.1f, 0.15f, alpha);
	}

	ImGui::GetStyle().Colors[ImGuiCol_PopupBg] = m_accentColor;
	ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = m_accentColor;

}

void HarbourUtils::ColorManager::setHoverColor()
{
	switch (m_currentColorTheme) {
	case BlueGray:
		m_hoverColor = ImVec4(0.1f, 0.1f, 0.15f, 1.0f);
		break;
	case DarkBlue:
		m_hoverColor = ImVec4(0.0f, 0.0f, 0.25f, 1.0f);
		break;
	case LightBlue:
		m_hoverColor = ImVec4(0.43f, 0.52f, 0.89f, 1.0f);
		break;
	case Green:
		m_hoverColor = ImVec4(0.05f, 0.2f, 0.05f, 1.0f);
		break;
	case Teal:
		m_hoverColor = ImVec4(0.05f, 0.25f, 0.25f, 1.0f);
		break;
	case DarkRed:
		m_hoverColor = ImVec4(0.2f, 0.05f, 0.05f, 1.0f);
		break;
	case LightRed:
		m_menuBarColor = ImVec4(0.55f, 0.15f, 0.15f, 1.0f);
		break;
	case DarkGray:
		m_hoverColor = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
		break;
	default:
		m_hoverColor = ImVec4(0.1f, 0.1f, 0.15f, 1.0f);
	}
}

void HarbourUtils::ColorManager::setMenuBarColor()
{
	switch (m_currentColorTheme)
	{
	/*case HarbourUtils::BlueGray:
		break;
	case HarbourUtils::DarkBlue:
		break;
	case HarbourUtils::LightBlue:
		break;
	case HarbourUtils::Green:
		break;
	case HarbourUtils::Teal:
		break;
	case HarbourUtils::DarkRed:
		break;
	case HarbourUtils::DarkGray:
		break;*/
	case LightRed:
		m_menuBarColor = ImVec4(0.55f, 0.15f, 0.15f, 1.0f);
		break;
	default:
		m_menuBarColor = ImVec4(0.14f, 0.14f, 0.14f, 1.0f);
	}
	ImGui::GetStyle().Colors[ImGuiCol_MenuBarBg] = m_menuBarColor;
}

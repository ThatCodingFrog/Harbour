#pragma once

struct ImVec4;

namespace HarbourUtils {
	const enum Colors {
		BlueGray, //Default
		DarkBlue, //0.0, 0.0, 0.25, 1.0
		LightBlue, //0.43 0.52 0.89
		Green,
		Teal,
		Red,
		Gray
	};

	class ColorManager {
	public:
		ColorManager();

	public:
		//Getters/setters
		ImVec4 getBackground() const;
		int getThemeColor() const;
		void drawBackground() const;
		void setThemeColor(int colorTheme);

	private:
		void setBackgroundColor();

		Colors m_currentColorTheme = {};

		ImVec4 m_backgroundColor = {};

	};
}

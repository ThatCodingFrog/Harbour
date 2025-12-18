#pragma once

struct ImVec4;

namespace HarbourUtils {
	const enum Colors {
		BlueGray, //Default
		DarkBlue, //0.0, 0.0, 0.25, 1.0
		LightBlue, //0.43 0.52 0.89
		Green, //0.05, 0.2, 0.05
		Teal, //0.05, 0.25, 0.25	
		DarkRed, //0.2, 0.05, 0.05
		LightRed, //0.85, 0.25, 0.25
		DarkGray, //0.15, 0.15, 0.15
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

		Colors m_currentColorTheme = {}; //Doesn't do much yet, add load by file

		ImVec4 m_backgroundColor = {}; //Set by setBackgroundColor() and m_currentColorTheme

	};
}

#pragma once

namespace HarbourUtils {
	class ColorManager {
	public:
		ColorManager();

	public:
		//Getters/setters

	private:
		const enum Colors {
			BlueGray,
			DarkBlue,
			LightBlue,
			Green,
			Teal,
			Red,
			Gray
		};

		ImVec4 m_backgroundColor = {};

	};
}

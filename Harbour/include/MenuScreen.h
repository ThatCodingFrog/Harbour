#pragma once

#include "imgui.h"
#include <vector>
#include "GameCard.h"


namespace HarbourGUI {
	const enum screenID {
		MyLibrary,
		AllGames,
		Settings,
		HelpCenter,
	};

	void MyLibraryScreen(std::vector<Harbour::GameCard>& myLibrary);
	void downloadsScreen(std::vector<Harbour::GameCard>& downloads);
	void settingsScreen();
	void helpScreen();

	const enum Colors {
		BlueGray,
		DarkBlue,
		LightBlue,
		Green,
		Teal,
		Red,
		Gray
	};

	ImVec4 getColor(Colors color);
	ImVec4 userColorProf = {};
}

/*
Nice, you found it! `0.1, 0.1, 0.15, 1.0` is a nice dark bluish-gray — easy on the eyes and doesn’t clash with ImGui’s default colors.

Here are some suggestions for alternative color schemes and the general “feel” they give:

---

### **1. Green-themed**

* `0.05, 0.1, 0.05, 1.0` ? very dark forest green, calm and natural
* Works well with beige/tan or light green accent buttons
* Gives a “terminal + nature” vibe

---

### **2. Red-themed**

* `0.15, 0.05, 0.05, 1.0` ? dark maroon / burgundy
* Good for alert-heavy UI or if you want a warm, energetic feel
* Red can be tiring if the UI is used a lot, so best for accents

---

### **3. Gray-themed / Neutral**

* `0.1, 0.1, 0.1, 1.0` ? almost black, very neutral
* `0.15, 0.15, 0.15, 1.0` ? slightly lighter, good for soft contrast
* Easy on eyes, very professional, works well with any highlight color (green/red/blue/yellow)

---

### **4. Blue / Nautical**

* `0.05, 0.05, 0.2, 1.0` ? navy, classic dark blue
* Fits your “nautical” theme perfectly
* Works with white, teal, or gold highlights

---

### **5. Teal / Sci-Fi**

* `0.05, 0.15, 0.15, 1.0` ? dark teal
* Gives a techy, slightly futuristic look
* Accent with cyan or orange

---

**Tips for choosing a scheme:**

* Keep background darker than your text for readability.
* Use 1–2 accent colors for highlights/buttons to avoid visual clutter.
* If you plan to make this customizable, consider saving the RGBA in a JSON settings file so users can pick a color in the UI.

---

If you want, I can mock up a **few ready-to-use RGBA palettes** for Harbour/SoH that would look good with ImGui’s default widgets — could save you time experimenting. Do you want me to do that?

*/

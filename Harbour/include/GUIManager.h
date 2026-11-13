#pragma once

namespace Harbour
{
    enum class ScreenID
    {
        MyLibrary,
        AllGames,
        Settings,
        HelpCenter,
    };

    class GUIManager
    {
        GUIManager();
        ~GUIManager();

        void drawSplashScreen();
        void drawCurrentScreen();
        void drawFooter();

    private:
        ScreenID m_screenID = ScreenID::MyLibrary;

    private:
    };
}
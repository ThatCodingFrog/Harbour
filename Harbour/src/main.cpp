/*main file.  Program starts and ends here*/

// main.cpp
#define SDL_MAIN_HANDLED

#include "App.h"

int main(int argc, char **argv)
{
    Harbour::App app = {};

    app.run();

    return 0;
}

#include "SDL.h"

#include "globals.h"

#include "Game.h"

int main(int argc, char* argv[])
{
    Game_Initialize();

#ifndef __EMSCRIPTEN__
    Game_Run();
#else
    Game_Run_Emscripten();
#endif

    Game_Quit();

    return 0;
}
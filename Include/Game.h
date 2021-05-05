#ifndef GAME_H
#define GAME_H

#include "SDL.h"

#include "Renderer.h"

typedef struct
{
	int isRunning;
} Game;

extern Game game;

void Game_Initialize();
void Game_Run();
void Game_Run_Emscripten();
void Game_Loop();
void Game_Quit();

#endif
#ifndef GAME_H
#define GAME_H

#include <time.h>

typedef struct
{
	int isRunning;

	clock_t previousTime;
	float timestep;
	float stackedTime;
} Game;

extern Game game;

void Game_Initialize();
void Game_Run();
void Game_Run_Emscripten();
void Game_Loop();
void Game_Quit();

#endif
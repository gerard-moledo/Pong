#include "Game.h"

#include <stdio.h>

#include "emscripten.h"

#include "globals.h"

Game game = { 0 };

void Game_Initialize()
{
	SDL_Init(SDL_INIT_VIDEO);
	
	Renderer_Initialize();
	World_Initialize();

	game.isRunning = 1;
	game.timestep = 0.005f;
}

void Game_Run()
{
	while (game.isRunning)
	{
		Game_Loop();
	}
}

void Game_Run_Emscripten()
{
#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(Game_Loop, 0, 1);
#endif
}

void Game_Loop()
{
	clock_t currentTime = clock();
	float dt = (float) (currentTime - game.previousTime) / CLOCKS_PER_SEC;
	game.previousTime = currentTime;
	game.stackedTime += dt;

	Input_PollEvents();

	while (game.stackedTime > game.timestep)
	{
		game.stackedTime -= game.timestep;

		World_Update();
		World_PhysicsUpdate();
	}

	renderer.lag = game.stackedTime / game.timestep;
	Renderer_Render();
}

void Game_Quit()
{
	Renderer_Quit();

	SDL_Quit();
}

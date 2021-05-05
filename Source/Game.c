#include "Game.h"

Game game = { 0 };

void Game_Initialize()
{
	SDL_Init(SDL_INIT_VIDEO);
	
	Renderer_Initialize();

	game.isRunning = 1;
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
	emscripten_run_main_loop()
#endif
}

void Game_Loop()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			game.isRunning = 0;
		}
	}

	Renderer_Render();
}

void Game_Quit()
{
	Renderer_Quit();

	SDL_Quit();
}

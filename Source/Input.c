#include "Input.h"

#include "globals.h"

Input input = { 0 };

void Input_PollEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			game.isRunning = 0;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			Input_HandleKey(e.key);
			break;
		}
	}
}

void Input_HandleKey(SDL_KeyboardEvent e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.keysym.sym == SDLK_w) input.up = 1;
		if (e.keysym.sym == SDLK_s) input.down = 1;
	}
	if (e.type == SDL_KEYUP)
	{
		if (e.keysym.sym == SDLK_w) input.up = 0;
		if (e.keysym.sym == SDLK_s) input.down = 0;
	}
}
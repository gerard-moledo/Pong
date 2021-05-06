#include "Renderer.h"

#include "globals.h"

Renderer renderer = { 0 };

void Renderer_Initialize()
{
	renderer.window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
	renderer.rendererSDL = SDL_CreateRenderer(renderer.window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderer_Render()
{
	SDL_SetRenderDrawColor(renderer.rendererSDL, 0, 0, 0, 255);
	SDL_RenderClear(renderer.rendererSDL);

	Paddle_Render(&world.player1);
	Paddle_Render(&world.player2);

	Ball_Render(&world.ball);

	SDL_RenderPresent(renderer.rendererSDL);
}

void Renderer_Quit()
{
	SDL_DestroyRenderer(renderer.rendererSDL);
	SDL_DestroyWindow(renderer.window);
}
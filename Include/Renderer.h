#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"

typedef struct
{
	SDL_Window* window;
	SDL_Renderer* rendererSDL;

	float lag;
} Renderer;

extern Renderer renderer;

void Renderer_Initialize();
void Renderer_Render();
void Renderer_Quit();

#endif

#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"

typedef struct
{
	int up;
	int down;
} Input;

extern Input input;

void Input_PollEvents();
void Input_HandleKey(SDL_KeyboardEvent e);
#endif

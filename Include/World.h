#ifndef WORLD_H
#define WORLD_H

#include "Paddle.h"

typedef struct
{
	Paddle player1;
} World;

extern World world;

void World_Initialize();
void World_Update();

#endif 
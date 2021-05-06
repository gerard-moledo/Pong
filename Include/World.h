#ifndef WORLD_H
#define WORLD_H

#include "Paddle.h"
#include "Ball.h"

typedef struct
{
	Paddle player1;
	Ball ball;
} World;

extern World world;

void World_Initialize();
void World_Update();
void World_PhysicsUpdate();

#endif 
#include "World.h"

#include "globals.h"

World world = { 0 };

void World_Initialize()
{
	world.player1 = Paddle_Initialize(actor_player1);
}

void World_Update()
{
	Paddle_Update(&world.player1);
}
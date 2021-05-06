#include "World.h"

#include <stdio.h>

#include "globals.h"

World world = { 0 };

void World_Initialize()
{
	world.player1 = Paddle_Initialize(actor_player1);
	world.ball = Ball_Initialize(-200, 200);
}

void World_Update()
{
	Paddle_Update(&world.player1);

	Ball_Update(&world.ball);
}

void World_PhysicsUpdate()
{
	CollisionData hit = Handle_AABB_Collision(world.ball.body, world.player1.body);
	
	if (hit.collided)
	{
		Ball_PhysicsUpdate(&world.ball, hit);
	}
}
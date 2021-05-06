#include "World.h"

#include <stdio.h>

#include "globals.h"

World world = { 0 };

void World_Initialize()
{
	world.player1 = Paddle_Initialize(actor_player1);
	world.player2 = Paddle_Initialize(actor_player2);

	world.ball = Ball_Initialize(-200, 200);
}

void World_Update()
{
	Paddle_Update(&world.player1);
	Paddle_Update(&world.player2);

	Ball_Update(&world.ball);
}

void World_PhysicsUpdate()
{
	CollisionData hitPlayer1 = Handle_AABB_Collision(world.ball.body, world.player1.body);
	if (hitPlayer1.collided)
	{
		Ball_PhysicsUpdate(&world.ball, hitPlayer1, world.player1.transform);
	}

	CollisionData hitPlayer2 = Handle_AABB_Collision(world.ball.body, world.player2.body);
	if (hitPlayer2.collided)
	{
		Ball_PhysicsUpdate(&world.ball, hitPlayer2, world.player2.transform);
	}
}
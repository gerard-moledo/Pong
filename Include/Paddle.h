#ifndef PADDLE_H
#define PADDLE_H

#include "Util.h"

typedef enum { actor_player1, actor_player2, actor_computer } Actor;

typedef struct
{
	Actor actor;

	Transform transform;

	float xPrev;
	float yPrev;

	AABB body;
} Paddle;

Paddle Paddle_Initialize(Actor actor);
void Paddle_Update(Paddle* paddle);
void Paddle_Render(Paddle* paddle);

void Paddle_UpdateBody(Paddle* paddle);

#endif
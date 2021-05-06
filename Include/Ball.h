#ifndef BALL_H
#define BALL_H

#include "Util.h"

typedef struct
{
	Transform transform;

	float xPrev;
	float yPrev;

	float xVelocity;
	float yVelocity;

	AABB body;
} Ball;

Ball Ball_Initialize(float xVelocity, float yVelocity);
void Ball_Update(Ball* ball);
void Ball_PhysicsUpdate(Ball* ball, CollisionData hit, Transform other);
void Ball_Render(Ball* ball);

void Ball_UpdateBody(Ball* ball);

#endif
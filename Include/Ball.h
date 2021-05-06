#ifndef BALL_H
#define BALL_H

#include "Util.h"

typedef struct
{
	float x;
	float y;
	float xPrev;
	float yPrev;

	float xVelocity;
	float yVelocity;

	float xExtents;
	float yExtents;

	AABB body;
} Ball;

Ball Ball_Initialize(float xVelocity, float yVelocity);
void Ball_Update(Ball* ball);
void Ball_PhysicsUpdate(Ball* ball, CollisionData hit);
void Ball_Render(Ball* ball);

void Ball_UpdateBody(Ball* ball);

#endif
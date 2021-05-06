#include "Ball.h"

#include <math.h>

#include "globals.h"

Ball Ball_Initialize(float xVelocity, float yVelocity)
{
	Ball ball = { 0 };
	ball.transform.x = 400;
	ball.transform.y = 300;
	ball.xPrev = ball.transform.x;
	ball.yPrev = ball.transform.y;

	ball.xVelocity = xVelocity;
	ball.yVelocity = yVelocity;

	ball.transform.xExtents = 4.f;
	ball.transform.yExtents = 4.f;

	Ball_UpdateBody(&ball);

	return ball;
}

void Ball_Update(Ball* ball)
{
	ball->xPrev = ball->transform.x;
	ball->yPrev = ball->transform.y;
	ball->transform.x += ball->xVelocity * game.timestep;
	ball->transform.y += ball->yVelocity * game.timestep;

	if (fabsf(ball->transform.x - 400) > 400)
	{
		ball->transform.x = 400.f;
		ball->transform.y = 300.f;
		ball->xPrev = ball->transform.x;
		ball->yPrev = ball->transform.y;
		ball->xVelocity = -200.f;
	}
	if (fabsf(ball->transform.y - 300) > 300)
	{
		ball->yVelocity *= -1;
	}

	Ball_UpdateBody(ball);
}

void Ball_PhysicsUpdate(Ball* ball, CollisionData hit, Transform other)
{
	if (hit.side == side_right && ball->xVelocity < 0 || hit.side == side_left && ball->xVelocity > 0)
	{
		ball->xVelocity *= -1;
		ball->yVelocity = (ball->transform.y - other.y) / (other.yExtents) * 300.f;
	}
	if (hit.side == side_top && ball->yVelocity > 0 || hit.side == side_bottom && ball->yVelocity < 0)
	{
		ball->yVelocity *= -1.4f;
		ball->xVelocity *= -2;
	}
}

void Ball_Render(Ball* ball)
{
	float xInterpolated = ball->xPrev + renderer.lag * (ball->transform.x - ball->xPrev);
	float yInterpolated = ball->yPrev + renderer.lag * (ball->transform.y - ball->yPrev);

	SDL_SetRenderDrawColor(renderer.rendererSDL, 255, 255, 255, 255);
	SDL_Rect renderRect;
	renderRect.x = (int) (xInterpolated - ball->transform.xExtents);
	renderRect.y = (int) (yInterpolated - ball->transform.yExtents);
	renderRect.w = (int) ball->transform.xExtents * 2;
	renderRect.h = (int) ball->transform.yExtents * 2;
	SDL_RenderFillRect(renderer.rendererSDL, &renderRect);
}

void Ball_UpdateBody(Ball* ball)
{
	ball->body.top = ball->transform.y - ball->transform.yExtents;
	ball->body.left = ball->transform.x - ball->transform.xExtents;
	ball->body.bottom = ball->transform.y + ball->transform.yExtents;
	ball->body.right = ball->transform.x + ball->transform.xExtents;
}
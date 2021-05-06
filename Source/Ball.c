#include "Ball.h"

#include <math.h>

#include "globals.h"

Ball Ball_Initialize(float xVelocity, float yVelocity)
{
	Ball ball = { 0 };
	ball.x = 400;
	ball.y = 300;
	ball.xPrev = ball.x;
	ball.yPrev = ball.y;

	ball.xVelocity = xVelocity;
	ball.yVelocity = yVelocity;

	ball.xExtents = 4.f;
	ball.yExtents = 4.f;

	Ball_UpdateBody(&ball);

	return ball;
}

void Ball_Update(Ball* ball)
{
	ball->xPrev = ball->x;
	ball->yPrev = ball->y;
	ball->x += ball->xVelocity * game.timestep;
	ball->y += ball->yVelocity * game.timestep;

	if (fabsf(ball->x - 400) > 400)
	{
		ball->x = 400.f;
		ball->y = 300.f;
		ball->xPrev = ball->x;
		ball->yPrev = ball->y;
		ball->xVelocity = -200.f;
	}
	if (fabsf(ball->y - 300) > 300)
	{
		ball->yVelocity *= -1;
	}

	Ball_UpdateBody(ball);
}

void Ball_PhysicsUpdate(Ball* ball, CollisionData hit)
{
	if (hit.side == side_right && ball->xVelocity < 0)
	{
		world.ball.xVelocity *= -1;
	}
	if (hit.side == side_top && ball->yVelocity > 0 || hit.side == side_bottom && ball->yVelocity < 0)
	{
		world.ball.yVelocity *= -1;
		world.ball.xVelocity *= -2;
	}
}

void Ball_Render(Ball* ball)
{
	float xInterpolated = ball->xPrev + renderer.lag * (ball->x - ball->xPrev);
	float yInterpolated = ball->yPrev + renderer.lag * (ball->y - ball->yPrev);

	SDL_SetRenderDrawColor(renderer.rendererSDL, 255, 255, 255, 255);
	SDL_Rect renderRect;
	renderRect.x = (int) (xInterpolated - ball->xExtents);
	renderRect.y = (int) (yInterpolated - ball->yExtents);
	renderRect.w = (int) ball->xExtents * 2;
	renderRect.h = (int) ball->yExtents * 2;
	SDL_RenderFillRect(renderer.rendererSDL, &renderRect);
}

void Ball_UpdateBody(Ball* ball)
{
	ball->body.top = ball->y - ball->yExtents;
	ball->body.left = ball->x - ball->xExtents;
	ball->body.bottom = ball->y + ball->yExtents;
	ball->body.right = ball->x + ball->xExtents;
}
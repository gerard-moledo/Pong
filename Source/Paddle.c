#include "Paddle.h"

#include "globals.h"

Paddle Paddle_Initialize(Actor actor)
{
	Paddle paddle = { 0 };

	if (actor == actor_player1)
	{
		paddle.x = 20.f;
		paddle.y = 300.f;
	}

	return paddle;
}

void Paddle_Update(Paddle* paddle)
{
	paddle->xPrev = paddle->x;
	paddle->yPrev = paddle->y;

	if (input.up)
	{
		paddle->y -= game.timestep * 500;
	}
	if (input.down)
	{
		paddle->y += game.timestep * 500;
	}
}

void Paddle_Render(Paddle* paddle)
{
	float xInterpolated = paddle->xPrev + renderer.lag * (paddle->x - paddle->xPrev);
	float yInterpolated = paddle->yPrev + renderer.lag * (paddle->y - paddle->yPrev);

	SDL_SetRenderDrawColor(renderer.rendererSDL, 255, 255, 255, 255);
	SDL_Rect renderRect;
	renderRect.x = (int) xInterpolated;
	renderRect.y = (int) yInterpolated;
	renderRect.w = 20;
	renderRect.h = 150;
	SDL_RenderFillRect(renderer.rendererSDL, &renderRect);
}
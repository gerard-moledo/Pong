#include "Paddle.h"

#include "globals.h"

Paddle Paddle_Initialize(Actor actor)
{
	Paddle paddle = { 0 };

	if (actor == actor_player1)
	{
		paddle.x = 20.f;
		paddle.y = 300.f;
		paddle.width = 10.f;
		paddle.height = 100.f;
	}

	Paddle_UpdateBody(&paddle);

	return paddle;
}

void Paddle_Update(Paddle* paddle)
{
	paddle->xPrev = paddle->x;
	paddle->yPrev = paddle->y;

	if (input.up)
	{
		paddle->y -= game.timestep * 500;
		if (paddle->y < 0) paddle->y = 0;
	}
	if (input.down)
	{
		paddle->y += game.timestep * 500;
		if (paddle->y > 600 - paddle->height) paddle->y = 600 - paddle->height;
	}

	Paddle_UpdateBody(paddle);
}

void Paddle_Render(Paddle* paddle)
{
	float xInterpolated = paddle->xPrev + renderer.lag * (paddle->x - paddle->xPrev);
	float yInterpolated = paddle->yPrev + renderer.lag * (paddle->y - paddle->yPrev);

	SDL_SetRenderDrawColor(renderer.rendererSDL, 255, 255, 255, 255);
	SDL_Rect renderRect;
	renderRect.x = (int) xInterpolated;
	renderRect.y = (int) yInterpolated;
	renderRect.w = (int) paddle->width;
	renderRect.h = (int) paddle->height;
	SDL_RenderFillRect(renderer.rendererSDL, &renderRect);
}

void Paddle_UpdateBody(Paddle* paddle)
{
	paddle->body.top = paddle->y;
	paddle->body.left = paddle->x;
	paddle->body.bottom = paddle->y + paddle->height;
	paddle->body.right = paddle->x + paddle->width;
}
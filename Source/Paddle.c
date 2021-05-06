#include "Paddle.h"

#include "globals.h"

Paddle Paddle_Initialize(Actor actor)
{
	Paddle paddle = { 0 };

	if (actor == actor_player1)
	{
		paddle.actor = actor_player1;
		paddle.transform.x = 25.f;
		paddle.transform.y = 350.f;
		paddle.transform.xExtents = 5.f;
		paddle.transform.yExtents = 50.f;
	}

	if (actor == actor_player2)
	{
		paddle.actor = actor_player2;
		paddle.transform.x = 800.f - 25.f;
		paddle.transform.y = 350.f;
		paddle.transform.xExtents = 5.f;
		paddle.transform.yExtents = 50.f;
	}

	Paddle_UpdateBody(&paddle);

	return paddle;
}

void Paddle_Update(Paddle* paddle)
{
	paddle->xPrev = paddle->transform.x;
	paddle->yPrev = paddle->transform.y;

	if (input.up && paddle->actor == actor_player1 || input.up2 && paddle->actor == actor_player2)
	{
		paddle->transform.y -= game.timestep * 500;
		if (paddle->transform.y < 0) paddle->transform.y = 0;
	}
	if (input.down && paddle->actor == actor_player1 || input.down2 && paddle->actor == actor_player2)
	{
		paddle->transform.y += game.timestep * 500;
		if (paddle->transform.y > 600 - paddle->transform.yExtents) paddle->transform.y = 600 - paddle->transform.yExtents;
	}

	Paddle_UpdateBody(paddle);
}

void Paddle_Render(Paddle* paddle)
{
	float xInterpolated = paddle->xPrev + renderer.lag * (paddle->transform.x - paddle->xPrev);
	float yInterpolated = paddle->yPrev + renderer.lag * (paddle->transform.y - paddle->yPrev);

	SDL_SetRenderDrawColor(renderer.rendererSDL, 255, 255, 255, 255);
	SDL_Rect renderRect;
	renderRect.x = (int) xInterpolated - paddle->transform.xExtents;
	renderRect.y = (int) yInterpolated - paddle->transform.yExtents;
	renderRect.w = (int) paddle->transform.xExtents * 2;
	renderRect.h = (int) paddle->transform.yExtents * 2;
	SDL_RenderFillRect(renderer.rendererSDL, &renderRect);
}

void Paddle_UpdateBody(Paddle* paddle)
{
	paddle->body.top = paddle->transform.y - paddle->transform.yExtents;
	paddle->body.left = paddle->transform.x - paddle->transform.xExtents;
	paddle->body.bottom = paddle->transform.y + paddle->transform.yExtents;
	paddle->body.right = paddle->transform.x + paddle->transform.xExtents;
}
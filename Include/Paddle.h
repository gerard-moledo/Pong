#ifndef PADDLE_H
#define PADDLE_H

typedef enum { actor_player1, actor_player2, actor_computer } Actor;

typedef struct
{
	float x;
	float y;
	float xPrev;
	float yPrev;
} Paddle;

Paddle Paddle_Initialize(Actor actor);
void Paddle_Update(Paddle* paddle);
void Paddle_Render(Paddle* paddle);

#endif
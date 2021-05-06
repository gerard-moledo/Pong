#ifndef UTIL_H
#define UTIL_H

typedef enum { false = 0, true = 1 } bool;

typedef struct
{
	float x;
	float y;
	float xExtents;
	float yExtents;
} Transform;

typedef struct
{
	float top;
	float left;
	float bottom;
	float right;
} AABB;

typedef enum { side_none = 0, side_top, side_left, side_bottom, side_right  } Side;

typedef struct
{
	bool collided;
	Side side;
	float xDepth;
	float yDepth;
} CollisionData;

CollisionData Handle_AABB_Collision(AABB body1, AABB body2);

#endif

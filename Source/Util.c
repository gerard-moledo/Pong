#include "Util.h"

#include <math.h>

CollisionData Handle_AABB_Collision(AABB dynamicBody, AABB staticBody)
{
	CollisionData data = { 0 };

	Side xSide = side_none;
	Side ySide = side_none;
	if (dynamicBody.left < staticBody.right && dynamicBody.right > staticBody.left)
	{
		float rightDepth = staticBody.right - dynamicBody.left;
		float leftDepth = dynamicBody.right - staticBody.left;
		data.xDepth = fminf(rightDepth, leftDepth);
		xSide = data.xDepth == rightDepth ? side_right : side_left;
	}
	if (dynamicBody.top < staticBody.bottom && dynamicBody.bottom > staticBody.top)
	{
		float bottomDepth = staticBody.bottom - dynamicBody.top;
		float topDepth = dynamicBody.bottom - staticBody.top;
		data.yDepth = fminf(bottomDepth, topDepth);
		ySide = data.yDepth == bottomDepth ? side_bottom : side_top;
	}

	if (data.xDepth != 0.f && data.yDepth != 0.f)
	{
		data.collided = true;
		data.side = data.xDepth < data.yDepth ? xSide : ySide;
	}
	else
	{
		data.collided = false;
		data.side = side_none;
	}

	return data;
}
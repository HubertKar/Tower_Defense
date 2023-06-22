#include "NBullet.h"

NBullet::NBullet(float x, float y, int Index, float Speed, int Damage, double Range, float Height, float Width, float Rotation)
	:Bullet( x,  y, Index, Speed, Damage, Range, Height, Width, Rotation)
{
}

NBullet::~NBullet()
{
}

void NBullet::move()
{
	double distance = sqrt(powf(position.x - start_position.x, 2) + powf(position.y - start_position.y, 2));

	if (distance >= range)
		reach_range_limit = 1;
	else
	{
		position.x += speed * cos(rotation / 180 * M_PI);
		position.y += speed * sin(rotation / 180 * M_PI);
	}
}

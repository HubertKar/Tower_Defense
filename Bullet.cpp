#include "Bullet.h"



Bullet::Bullet(float x, float y, int Index, float Speed, int Damage, double Range,float Height, float Width, float Rotation)
	:MovingObject(x, y, Index, Speed, Height, Width, Rotation)
{
	damage = Damage;
	range = Range;

	start_position.x = x;
	start_position.y = y;
}

Bullet::~Bullet()
{
}

void Bullet::move()
{
}

bool Bullet::get_reached_range_limit()
{
	return reach_range_limit;
}

double Bullet::get_damage()
{
	return damage;
}

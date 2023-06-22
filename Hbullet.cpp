#include "Hbullet.h"

Hbullet::Hbullet(float x, float y, int Index, float Speed, int Damage, double Range, float Height, float Width, float Rotation, Enemy* Target)
	:Bullet(x, y, Index, Speed, Damage, Range, Height, Width, Rotation)
{
	target = Target;
}

Hbullet::~Hbullet()
{
}

void Hbullet::move()
{
	double distance = sqrt(powf(position.x - start_position.x, 2) + powf(position.y - start_position.y, 2));

	if (distance >= range)
		reach_range_limit = 1;
	else
	{

		if (target->get_died() == true)
		{
			target_gone = 1;
		}

		if (target_gone == 0)
		{
			float deltaX = target->get_position().x - position.x;
			float deltaY = target->get_position().y - position.y;

			rotation = atan2(deltaY, deltaX) * 180 / M_PI;;
		}

		position.x += speed * cos(rotation / 180 * M_PI);
		position.y += speed * sin(rotation / 180 * M_PI);
	}
}

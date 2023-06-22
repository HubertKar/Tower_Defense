#include "Tower1.h"

Tower1::Tower1(float x, float y, int Index, float Range, float Rate_of_fire, int Price, float Height, float Width, int Bullet_Type)
	:Tower(x, y, Index, Range, Rate_of_fire, Price, Height, Width, Bullet_Type)
{
}

Tower1::~Tower1()
{
}

Bullet* Tower1::shoot(std::vector<Enemy*> enemy_list)
{
	for (int i = 0; i < enemy_list.size(); i++)
	{
		if (intersects(enemy_list[i]->get_hitbox(), enemy_list[i]->get_position()))
		{
			return create_bullet(enemy_list[i]);
			break;
		}
	}

	return nullptr;
}



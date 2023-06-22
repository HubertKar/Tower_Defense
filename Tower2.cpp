#include "Tower2.h"


Tower2::Tower2(float x, float y, int Index, float Range, float Rate_of_fire, int Price, float Height, float Width, int Bullet_Type)
	:Tower(x, y, Index, Range, Rate_of_fire, Price, Height, Width, Bullet_Type)
{
}

Tower2::~Tower2()
{
}

Bullet* Tower2::shoot(std::vector<Enemy*> enemy_list)
{
	int maxHP = 0;
	if (enemy_list.size() > 0)
		maxHP = enemy_list[0]->get_hp();
	int x = 0;
	bool is_in_range = 0;
	for (int i = 0; i < enemy_list.size(); i++)
	{
		if (intersects(enemy_list[i]->get_hitbox(), enemy_list[i]->get_position()))
		{
			is_in_range = 1;
			if (enemy_list[i]->get_hp() > maxHP)
			{
				maxHP = enemy_list[i]->get_hp();
				x = i;
			}

		}
	}

	if (is_in_range == 1)
		return create_bullet(enemy_list[x]);
	else
		return nullptr;
}
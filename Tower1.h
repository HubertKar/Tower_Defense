#pragma once
#include "Tower.h"

class Tower1 :public Tower
{
public:
	Tower1(float x, float y, int Index, float Range, float Rate_of_fire, int Price, float Height, float Width, int Bullet_Type);
	~Tower1();
	Bullet* shoot(std::vector<Enemy*> enemy_list);

};


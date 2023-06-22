#pragma once

#include "Bullet.h"

class NBullet :public Bullet
{

public:
	NBullet(float x, float y, int Index, float Speed, int Damage, double Range, float Height, float Width, float Rotation);
	~NBullet();

	void move();

};


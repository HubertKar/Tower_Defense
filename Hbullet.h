#pragma once
#include "Bullet.h"
#include "Enemy.h"

class Hbullet :public Bullet
{
private:
	Enemy* target;
	bool target_gone = 0;
public:
	Hbullet(float x, float y, int Index, float Speed, int Damage, double Range, float Height, float Width, float Rotation, Enemy* Target);
	~Hbullet();

	void move();
};


#include "MovingObject.h"

#include <cmath>
#define M_PI 3.14159265358979323846

#include <SFML/System.hpp>

#pragma once
class Bullet: public MovingObject
{
protected:
	int damage;
	double range;
	sf::Vector2f start_position;

	bool reached_target = 0;
	bool reach_range_limit = 0;

public:
	Bullet(float x, float y, int Index, float Speed, int Damage, double Range, float Height, float Width, float Rotation);
	virtual ~Bullet();

	virtual void move();

	bool get_reached_range_limit();
	double get_damage();
};


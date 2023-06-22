#include "MovingObject.h"
#include <cmath>
#define M_PI 3.14159265358979323846

using std::vector;

#pragma once
class Enemy: public MovingObject
{
protected:
	int hp;
	int speed;
	int value;
	int current_path = 0;
	bool died = 0;
	vector<sf::Vector2f> path;

	bool reached_base = 0;

public:
	Enemy(float x, float y, int Index, float Speed, int Hp, vector<sf::Vector2f> Path, float Height, float Width, int Value, float Rotation = 0);
	~Enemy();

	void move();
	bool get_reached_base();
	int get_hp();
	int get_value();

	void take_damage(int damage);
	void set_died(bool i);
	bool get_died();

};


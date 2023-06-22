#include "Enemy.h"

Enemy::Enemy(float x, float y, int Index, float Speed, int Hp, vector<sf::Vector2f> Path, float Height, float Width, int Value, float Rotation)
	:MovingObject(x, y, Index, Speed, Height, Width, Rotation)
{
	value = Value;
	hp = Hp;
	path = Path;
	speed = Speed;
}

Enemy::~Enemy()
{
	path.clear();
}

void Enemy::move()
{

	if (current_path == path.size() - 1)
	{
		reached_base = 1;
	}

	if (current_path < path.size() - 1)
	{
		float deltaX = path[current_path + 1].x - path[current_path].x;
		float deltaY = path[current_path + 1].y - path[current_path].y;

		float rotation_radians = atan2(deltaY, deltaX);
		rotation = rotation_radians *180 / M_PI;
		
		position.x += speed * cos(rotation_radians);
		position.y += speed * sin(rotation_radians);

		if (abs(position.x - path[current_path + 1].x) < 8 && abs(position.y - path[current_path + 1].y) < 8)
		{
			position = path[current_path + 1];
			current_path++;
		}
	}
}

bool Enemy::get_reached_base()
{
	return reached_base;
}

int Enemy::get_hp()
{
	return hp;
}

int Enemy::get_value()
{
	return value;
}

void Enemy::take_damage(int damage)
{
	hp = hp - damage;
}

void Enemy::set_died(bool i)
{
	died = i;
}

bool Enemy::get_died()
{
	return died;
}

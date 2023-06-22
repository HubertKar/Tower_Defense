#include "Tower.h"


Bullet* Tower::create_bullet(Enemy* target)
{
	float deltaX = target->get_position().x - position.x;
	float deltaY = target->get_position().y - position.y;

	float rotation_radians = atan2(deltaY, deltaX);
	float bullet_rotation = rotation_radians * 180 / M_PI;

	rotation = bullet_rotation;

	switch (bullet_type)
	{
		Bullet* bullet;
	case 0:
		bullet = new NBullet(position.x, position.y, 0, 20, 20, 500, 47, 24, bullet_rotation);
		return bullet;
		break;
	case 1:
		bullet = new NBullet(position.x, position.y, 1, 30, 20, 500, 47, 24, bullet_rotation);
		return bullet;
		break;
	case 2:
		 bullet = new NBullet(position.x, position.y, 2, 50, 5, 500, 47, 24, bullet_rotation);
		return bullet;
		break;
	case 3:
		bullet = new Hbullet(position.x, position.y, 3, 20, 150, 3000, 47, 24, bullet_rotation, target);
		return bullet;
		break;
	}
}

bool Tower::intersects(sf::FloatRect enemy_hitbox, sf::Vector2f enemy_position)
{
	float circleDistanceX = abs(position.x - enemy_position.x);
	float circleDistanceY = abs(position.y - enemy_position.y);

	if (circleDistanceX > (enemy_hitbox.width / 2 + range)) { return false; }
	if (circleDistanceY > (enemy_hitbox.height / 2 + range)) { return false; }

	if (circleDistanceX <= (enemy_hitbox.width / 2)) { return true; }
	if (circleDistanceY <= (enemy_hitbox.height / 2)) { return true; }

	float c = circleDistanceX - enemy_hitbox.width / 2;
	float d = circleDistanceY - enemy_hitbox.height / 2;
	float cornerDistance_sq = powf(c, 2) + powf(d , 2);

	return (cornerDistance_sq <= powf(range,2));
}

Tower::Tower(float x, float y, int Index, float Range, float Rate_of_fire, int Price, float Height, float Width, int Bullet_Type):
	Object(x, y, Index, Height, Width)
{
	range = Range;
	rate_of_fire = Rate_of_fire;
	price = Price;
	bullet_type = Bullet_Type;
}

Tower::~Tower()
{
}

int Tower::get_price()
{
	return price;
}

int Tower::get_range()
{
	return range;
}

Bullet* Tower::shoot(std::vector<Enemy*> enemy_list)
{
}

double Tower::get_last_shoot_time()
{
	return last_shoot_time;
}

void Tower::set_last_shoot_time(double time)
{
	last_shoot_time = time;
}

double Tower::get_rof()
{
	return rate_of_fire;
}

void Tower::change_index(int i)
{
	index = i;
}

void Tower::change_position(sf::Vector2f new_position)
{
	position = new_position;
}




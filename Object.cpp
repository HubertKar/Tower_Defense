#include "Object.h"

void Object::set_index(int i)
{
	index = i;
}

int Object::get_index()
{
	return index;
}

sf::Vector2f Object::get_position()
{
	return position;
}

float Object::get_rotation()
{
	return rotation;
}

sf::FloatRect Object::get_hitbox()
{
	return hitbox;
}

std::vector<sf::Vector2f> Object::get_hitbox_points()
{
	return hitbox_points;
}

Object::Object(float x, float y, int Index, float Height, float Width)
{
	sf::Vector2f p(x, y);
	position = p;

	hitbox.width = Width;
	hitbox.height = Height;
	hitbox.top = position.y - hitbox.height / 2;
	hitbox.left = position.x - hitbox.width / 2;

	index = Index;

	sf::Vector2f p1, p2, p3, p4;

	p1.x = x - Width / 2;
	p1.y = y - Height / 2;

	p2.x = x + Width / 2;
	p2.y = y - Height / 2;

	p3.x = x + Width / 2;
	p3.y = y + Height / 2;

	p3.x = x - Width / 2;
	p3.y = y + Height / 2;

	hitbox_points.push_back(p1);
	hitbox_points.push_back(p2);
	hitbox_points.push_back(p3);
	hitbox_points.push_back(p4);

}

Object::~Object()
{
}


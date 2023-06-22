#include "MovingObject.h"

MovingObject::MovingObject(float x, float y, int Index, float Speed, float Height, float Width, float Rotation):
	Object(x, y, Index, Height, Width)
{
	speed = Speed;
	rotation = Rotation;

	float rotation_radians = Rotation * M_PI / 180;

	sf::Vector2f p1, p2, p3, p4;

	//p1.x = lines[i].x + path_width / 2 * sin(rotation_radians);
	//p1.y = lines[i].y + path_width / 2 * cos(rotation_radians);

	//p2.x = lines[i].x - path_width / 2 * sin(rotation_radians);
	//p2.y = lines[i].y - path_width / 2 * cos(rotation_radians);

	//p3.x = lines[i + 1].x - path_width / 2 * sin(rotation_radians);
	//p3.y = lines[i + 1].y - path_width / 2 * cos(rotation_radians);

	//p4.x = lines[i + 1].x + path_width / 2 * sin(rotation_radians);
	//p4.y = lines[i + 1].y + path_width / 2 * cos(rotation_radians);

	
}

MovingObject::~MovingObject()
{
}


void MovingObject::move()
{
}

void MovingObject::rotate()
{
}

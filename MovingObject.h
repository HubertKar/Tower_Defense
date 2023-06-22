#pragma once
#include "Object.h"
#define M_PI 3.14159265358979323846

class MovingObject:public Object
{
protected:
	
	float speed;

public:
	MovingObject(float x, float y, int Index, float Speed, float Height, float Width, float Rotation = 0);
	~MovingObject();

	virtual void move();
	void rotate();
};


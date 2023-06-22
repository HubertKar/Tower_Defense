#include "Object.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>  
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

#include "Bullet.h"
#include "NBullet.h"
#include "Hbullet.h"
#include "Enemy.h"

#pragma once
class Tower: public Object
{
protected:
	float range;
	double rate_of_fire; // iloœæ strza³ów na sekunde
	int price;
	int bullet_type;
	double last_shoot_time = 0;

	Bullet *create_bullet(Enemy* target);
	bool intersects(sf::FloatRect enemy_hitbox, sf::Vector2f enemy_position);


public:
	Tower(float x, float y, int Index, float Range, float Rate_of_fire, int Price, float Height, float Width, int Bullet_Type);
	virtual ~Tower();

	int get_price();
	int get_range();

	virtual Bullet* shoot(std::vector <Enemy*> enemy_list);

	double get_last_shoot_time();
	void set_last_shoot_time(double time);

	double get_rof();

	void change_index(int i);

	void change_position(sf::Vector2f new_position);
};


#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>

#pragma once
class Object
{
protected:
	int index;
	sf::Vector2f position;
	std::vector <sf::Vector2f> hitbox_points;
	sf::FloatRect hitbox;
	float rotation = 0;

public:
	Object(float x, float y, int Index, float Height, float Width);
	~Object();

	void set_index(int i);
	int get_index();
	float get_rotation();
	sf::Vector2f get_position();
	sf::FloatRect get_hitbox();
	std::vector <sf::Vector2f> get_hitbox_points();

};


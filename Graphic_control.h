#pragma once
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Map.h"
#include "Drawing.h"
#include "Object.h"


class Graphic_control
{
private:
	Drawing* drawing;
	Map* map;


public:
	Graphic_control(Drawing* Drawing, Map* Map);
	~Graphic_control();
	void add_to_sprite_vector(sf::Vector2f position, float rotaion, int vector_nb, int index);
	void remove_sprite_from_vector(int vector_nb, int index);
	void update_sprite(sf::Vector2f position, float rotaion, int vector_nb, int index, int id = -1);

	void update();
};


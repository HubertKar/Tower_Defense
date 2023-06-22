#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class path
{
private:
	std::vector<sf::Vector2f> lines;
	std::vector<std::vector<sf::Vector2f>> colision_rect;
	float path_width = 100; // szerokoœæ scie¿ki
	std::vector<std::vector <float>> hitbox_info;

	void import_lines(int map_number);
	void construct_colision_rect();
public:
	path(int map_number);
	~path();
	
	std::vector<sf::Vector2f> get_path();
	std::vector<std::vector<sf::Vector2f>> get_colision_rect();

};


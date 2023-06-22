#pragma once
#include <iostream>
#include <vector>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Map.h"
#include "Drawing.h"
#include "Game_control.h"
#include "Object_control.h"
#include "Graphic_control.h"
class Game
{
private:
	sf::RenderWindow* window = nullptr;
	sf::VideoMode videoMode;
	sf::Event event;

	int enemy_sprites_nb;
	int tower_sprites_nb;
	int bullet_sprites_nb;
	int start_map_number;
	int number_of_maps;
	int current_map;

	Map* map = nullptr;
	Drawing* drawing = nullptr;
	Game_control* game_control = nullptr;
	Object_control* object_control = nullptr;
	Graphic_control* graphic_control = nullptr;

	void initWindow();
	void initMap(int map_number);
	void initDrawing(int Enemy_sprites_nb, int Tower_sprites_nb, int Bullet_sprites_nb, int Map_number);
	void initGameControl();
	void initObjectControl();
	void initGraphicControl();

public:
	Game(int enemy_sprites_nb, int tower_sprites_nb, int bullet_sprites_nb, int map_number, int Number_of_map);
	~Game();

	void update();
	void draw();
	const bool running() const;
};




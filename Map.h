#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include <vector>
#include <fstream>

#include "Object.h"
#include "MovingObject.h"
#include "Bullet.h"
#include "Enemy.h"
#include "path.h"
#include "Tower.h"

#pragma once

class Map
{
private:
	int number;
	
	sf::Vector2f start_pos;
	sf::Vector2f end_pos;

	std::vector <std::string> wave_conf; // wektor przechowuj¹cy informacje o konfiguracji kolejnych fal

	std::vector <Enemy*> enemy_list;
	std::vector <Bullet*> bullet_list;
	std::vector <Tower*> tower_list;

	Tower* t_tower = nullptr;

	//Tower test_tower;

	path* Path = nullptr;

	float maxPlayerHp;
	float PlayerHp;
	int money;
	int wave = 0;
	int wave_timer = 0;

	void importData();

public:
	Map(int Number);
	~Map();

	int get_map_number();
	std::vector <Enemy*> &get_enemy_list();
	std::vector <Tower*> &get_tower_list();
	std::vector <Bullet*> &get_bullet_list();
	Tower* get_t_tower();

	sf::Vector2f get_start_postion();
	std::vector<sf::Vector2f> get_path();
	std::vector<std::vector<sf::Vector2f>> get_path_colision();

	float getHP();
	float getMaxHp();
	int getMoney();
	int getWave();
	int get_wave_timer();

	void set_t_tower(Tower* t);
	void reset_t_tower();
	void setHP(int HP);
	void change_money(int x);

	std::vector <std::string> get_wave_conf();
	void set_wave(int wave_nb);
	void set_wave_timer(int timer);
};


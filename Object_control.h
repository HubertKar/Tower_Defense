#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Map.h"
#include "Game_control.h"
#include "Object.h"
#include "path.h"
#include "MovingObject.h"
#include "Tower.h"
#include "Tower1.h"
#include "Tower2.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Graphic_control.h"

class Object_control
{
private:

	int Tower_choice = 0;
	bool test_tower_created = 0;
	double current_time = 0;
	double enemy_time_spawn = 0;
	double wave_delay = 0;
	int enemy_spawned = 0;
	bool map_finished = 0;
	int wave = 0;

	Map* map;
	Graphic_control* graphic_control;

	void spawnTower(std::vector <Tower*>& tower_list);
	void spawnEnemy(std::vector <Enemy*>& enemy_list, sf::Vector2f start_pos, vector<sf::Vector2f> path, int Index, float Speed, int Hp, int Value, float Height, float Width);

	void move(std::vector <Enemy*>& enemy_list);

	void towerControl(std::vector <Tower*>& tower_list, std::vector <Enemy*>& enemy_list, std::vector <Bullet*>& bullet_list);
	void bulletControl(std::vector <Bullet*>& bullet_list, std::vector <Enemy*>& enemy_list);
	void enemyControl(std::vector <Enemy*>& enemy_list, sf::Vector2f start_pos, vector<sf::Vector2f> path, int event_number, std::vector <std::string> wave_conf);

	void take_player_damage(int damage);

	void buy_tower(int tc, sf::Vector2f mouse_position, std::vector<std::vector<sf::Vector2f>> colision_rect, bool mouse_clicked);

	bool AABB_colision_detection(sf::Vector2f pos1, float h1, float w1, sf::Vector2f pos2, float h2, float w2);

public:
	Object_control(Map* Map, Graphic_control* Graphic_control);
	~Object_control();

	bool get_map_finish();

	void movingObjectControl(std::vector <Enemy*>& enemy_list, sf::Vector2f start_pos, vector<sf::Vector2f> path, int event_number, std::vector <std::string> wave_conf);

	void uiControl();

	bool check_tower_colison(Tower *tower_t, std::vector <Tower*>& Tower_list, std::vector<std::vector<sf::Vector2f>> regions, std::vector<std::vector<sf::Vector2f>> colision_rect);

	void update(int event_number, int tower_choice, sf::Vector2f mouse_position, bool mouse_cliked);

};


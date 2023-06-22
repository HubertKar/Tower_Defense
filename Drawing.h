#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Object.h"
#include "Enemy.h"
#include "Map.h"

class Drawing
{
private:
	sf::RenderWindow* window;
	Map* map = nullptr;

	std::vector <sf::Texture> Enemy_Texture_buffer;
	std::vector <sf::Texture> Bullet_Texture_buffer;
	std::vector <sf::Texture> Tower_Texture_buffer;
	sf::Texture Map_bg_buffer;

	std::vector <sf::Sprite*> Enemy_Sprite_list;
	std::vector <sf::Sprite*> Bullet_Sprite_list;
	std::vector <sf::Sprite*> Tower_Sprite_list;

	std::vector <sf::Sprite*> t_Tower_Sprite_list;


	sf::Sprite map_bg;

	sf::RectangleShape hpBar;
	sf::RectangleShape hpBarFill;

	std::vector <sf::Sprite> UI_sprites;
	sf::Font font;
	sf::Text hplevel;
	sf::Text money;
	sf::Text wave_number;
	sf::Text wave_timer;
	sf::Text End_text;


	void init_UI_sprites();
	void initUI();

	void import_sprites(int enemy_sprites_nb, int tower_sprites_nb, int bullet_sprites_nb);
	void import_map_bg(int maps_mb);

	void draw_sprites();
	void draw_bg();
	void draw_others();

public:
	Drawing(sf::RenderWindow* ren_window, Map* map, int enemy_sprites_nb, int tower_sprites_nb, int bullet_sprites_nb, int map_number);
	~Drawing();

	void update_other();

	std::vector <sf::Sprite>& get_sprite_list();
	void draw();

	std::vector <sf::Sprite*>& get_Enemy_Sprite_list();
	std::vector <sf::Sprite*>& get_Bullet_Sprite_list();
	std::vector <sf::Sprite*>& get_Tower_Sprite_list();
	std::vector <sf::Sprite*>& get_t_Tower_list();

	std::vector <sf::Texture>& get_Enemy_Texture_buffer();
	std::vector <sf::Texture>& get_Bullet_Texture_buffer();
	std::vector <sf::Texture>& get_Tower_Texture_buffer();
};


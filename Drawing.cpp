#include "Drawing.h"


void Drawing::import_sprites(int enemy_sprites_nb, int tower_sprites_nb, int bullet_sprites_nb)
{
	Enemy_Texture_buffer.resize(enemy_sprites_nb);
	Tower_Texture_buffer.resize(tower_sprites_nb);
	Bullet_Texture_buffer.resize(bullet_sprites_nb);

	for (int i = 0; i < enemy_sprites_nb; i++)
	{
		std::string FilePath = "Data/Images/Enemies/" + std::to_string(i) + ".png";
		Enemy_Texture_buffer[i].loadFromFile(FilePath);
	}

	for (int i = 0; i < tower_sprites_nb; i++)
	{
		std::string FilePath = "Data/Images/Towers/" + std::to_string(i) + ".png";
		Tower_Texture_buffer[i].loadFromFile(FilePath);
	}

	for (int i = 0; i < bullet_sprites_nb; i++)
	{
		std::string FilePath = "Data/Images/Bullets/" + std::to_string(i) + ".png";
		Bullet_Texture_buffer[i].loadFromFile(FilePath);
	}
}

void Drawing::import_map_bg(int map_number)
{
	std::string FilePath = "Data/Map_bg/" + std::to_string(map_number)  + ".png";
	Map_bg_buffer.loadFromFile(FilePath);
}


void  Drawing::update_other()
{
	float hp_level = (map->getHP() / map->getMaxHp()) * 210;

	this->hpBarFill.setSize(sf::Vector2f(hp_level, 50));
	this->hplevel.setString (std::to_string(int(map->getHP())));
	this->wave_timer.setString(std::to_string(map->get_wave_timer()));

	this->money.setString(std::to_string(int(map->getMoney())));
	this->wave_number.setString(std::to_string(int(map->getWave())));
}

void Drawing::draw_sprites()
{

	for (auto sprite : Enemy_Sprite_list)
	{
		this->window->draw(*sprite);
	}

	for (auto sprite : Tower_Sprite_list)
	{
		this->window->draw(*sprite);
	}

	for (auto sprite : Bullet_Sprite_list)
	{
		this->window->draw(*sprite);
	}

	for (int i = 0; i < UI_sprites.size(); i++)
	{
		this->window->draw(UI_sprites[i]);
	}

	for (int i = 0; i < t_Tower_Sprite_list.size(); i++)
	{
		this->window->draw(*t_Tower_Sprite_list[i]);
	}
}

void Drawing::initUI()
{

	this->font.loadFromFile("Data/Fonts/arial.ttf");

	hpBar.setSize(sf::Vector2f(210, 50));
	hpBar.setOutlineThickness(5);
	hpBar.setOutlineColor(sf::Color::Black);
	hpBar.setPosition(sf::Vector2f(1000, 50));

	this->hplevel.setFont(font);
	this->hplevel.setCharacterSize(40);
	this->hplevel.setFillColor(sf::Color::Black);
	this->hplevel.setPosition(950,50);
	this->hplevel.setString(std::to_string(int(map->getHP())));

	this->End_text.setFont(font);
	this->End_text.setCharacterSize(90);
	this->End_text.setFillColor(sf::Color::Red);
	this->End_text.setPosition(440, 260);
	this->End_text.setString("Koniec Gry");


	this->money.setFont(font);
	this->money.setCharacterSize(40);
	this->money.setFillColor(sf::Color::Black);
	this->money.setPosition(850, 50);
	this->money.setString(std::to_string(int(map->getMoney())));

	this->wave_number.setFont(font);
	this->wave_number.setCharacterSize(40);
	this->wave_number.setFillColor(sf::Color::Black);
	this->wave_number.setPosition(750, 50);
	this->wave_number.setString(std::to_string(int(map->getWave())));

	this->wave_timer.setFont(font);
	this->wave_timer.setCharacterSize(40);
	this->wave_timer.setFillColor(sf::Color::Black);
	this->wave_timer.setPosition(650, 50);
	this->wave_timer.setString(std::to_string(map->get_wave_timer()));

	hpBarFill.setSize(sf::Vector2f(200, 50));
	hpBarFill.setOutlineColor(sf::Color::Red);
	hpBarFill.setFillColor(sf::Color::Red);
	hpBarFill.setPosition(sf::Vector2f(1000, 50));

	init_UI_sprites();
}

void  Drawing::draw_bg()
{
	this->window->draw(map_bg);
}

void Drawing::draw_others()
{
	this->window->draw(hpBar);
	this->window->draw(hpBarFill);
	this->window->draw(hplevel);
	this->window->draw(money);
	this->window->draw(wave_number);
	this->window->draw(wave_timer);
	if(map->getHP() <= 0)
		this->window->draw(End_text);
}

Drawing::Drawing(sf::RenderWindow* ren_window, Map* Map, int enemy_sprites_nb, int tower_sprites_nb, int bullet_sprites_nb, int map_number)
{
	map = Map;
	window = ren_window;
	import_sprites(enemy_sprites_nb, tower_sprites_nb, bullet_sprites_nb);
	import_map_bg(map_number);
	map_bg.setTexture(Map_bg_buffer);
	initUI();
}

Drawing::~Drawing()
{
}

void Drawing::draw()
{
	this->window->clear();
	draw_bg();
	draw_sprites();
	draw_others();
	this->window->display();
}

void Drawing::init_UI_sprites()
{
	sf::Texture* t = new sf::Texture;
	t->loadFromFile("Data/UI_Sprites/coin.png");
	sf::Sprite coin;
	coin.setTexture(*t);
	coin.setPosition(790, 50);
	UI_sprites.push_back(coin);

	sf::Texture* t1 = new sf::Texture;
	t1->loadFromFile("Data/UI_Sprites/tower_menu.png");
	sf::Sprite menu;
	menu.setTexture(*t1);
	menu.setPosition(20, 20);
	UI_sprites.push_back(menu);

}

std::vector<sf::Sprite*>& Drawing::get_t_Tower_list()
{
	return t_Tower_Sprite_list;
}

std::vector<sf::Sprite*>& Drawing::get_Enemy_Sprite_list()
{
	return Enemy_Sprite_list;
}

std::vector<sf::Sprite*>& Drawing::get_Bullet_Sprite_list()
{
	return Bullet_Sprite_list;
}

std::vector<sf::Sprite*>& Drawing::get_Tower_Sprite_list()
{
	return Tower_Sprite_list;
}


std::vector<sf::Texture>& Drawing::get_Tower_Texture_buffer()
{
	return Tower_Texture_buffer;
}

std::vector<sf::Texture>& Drawing::get_Enemy_Texture_buffer()
{
	return Enemy_Texture_buffer;
}

std::vector<sf::Texture>& Drawing::get_Bullet_Texture_buffer()
{
	return Bullet_Texture_buffer;
}


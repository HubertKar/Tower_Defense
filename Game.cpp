#include "Game.h"


void Game::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;

	this->window = new sf::RenderWindow(this->videoMode, "Tower Defense", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initMap(int map_number)
{
	this->map = new Map(map_number);
}

void Game::initDrawing(int enemy_sprites_nb, int tower_sprites_nb, int bullet_sprites_nb, int map_number)
{
	this->drawing = new Drawing(window, map, enemy_sprites_nb, tower_sprites_nb, bullet_sprites_nb, map_number);
}

void Game::initGameControl()
{
	this->game_control = new Game_control(window);
}


void Game::initObjectControl()
{
	this->object_control = new Object_control(map, graphic_control);
}

void Game::initGraphicControl()
{
	this->graphic_control = new Graphic_control(drawing, map);
}

Game::Game(int Enemy_sprites_nb, int Tower_sprites_nb, int Bullet_sprites_nb, int Map_number, int Number_of_maps)
{

	this->enemy_sprites_nb = Enemy_sprites_nb;
	this->tower_sprites_nb = Tower_sprites_nb;
	this->bullet_sprites_nb = Bullet_sprites_nb;
	this->start_map_number = Map_number;
	this->number_of_maps = Number_of_maps;
	this->current_map = start_map_number;

	this->initWindow();
	this->initMap(start_map_number);
	this->initGameControl();
	this->initDrawing(enemy_sprites_nb, tower_sprites_nb, bullet_sprites_nb, start_map_number);
	this->initGraphicControl();
	this->initObjectControl();
}

Game::~Game()
{
	delete this->game_control;
	delete this->window;
	delete this->map;
	delete this->drawing;
	delete this->graphic_control;
	delete this->object_control;
}

void Game::update()
{
	if (this->object_control->get_map_finish() == true and current_map < number_of_maps + start_map_number)
	{
		current_map += 1;
		delete this->map;
		delete this->drawing;
		delete this->graphic_control;
		delete this->object_control;

		this->initMap(current_map);
		this->initDrawing(enemy_sprites_nb, tower_sprites_nb, bullet_sprites_nb, current_map);
		this->initGraphicControl();
		this->initObjectControl();
	}

	this->game_control->update();
	if(this->map->getHP() > 0)
	{
		this->object_control->update(this->game_control->get_Event_nm(), this->game_control->get_tower_choice(), this->game_control->getMousePos(), this->game_control->get_mouse_clicked());
	}
	this->graphic_control->update();
}

void  Game::draw()
{
	this->drawing->draw();
}

const bool Game::running() const
{
	return this->window->isOpen();
}
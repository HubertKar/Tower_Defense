#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <iostream>

class Game_control
{
private:
	sf::RenderWindow* window;
	int event_nm = 0;
	int tmp_tower_choice = 0;
	int tower_choice = 0;
	sf::Event event;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	bool mouse_clicked = 0;
	bool p_clik = 0;

	void poll_events();
	void updateMousePostion();
	void tower_choices();

public:
	Game_control(sf::RenderWindow* Window);
	~Game_control();

	void update();
	int get_Event_nm();
	int get_tower_choice();
	sf::Vector2f getMousePos();
	void reset_tower_choice();
	bool get_mouse_clicked();
};


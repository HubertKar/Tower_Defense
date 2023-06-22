#include "Game_control.h"

Game_control::Game_control(sf::RenderWindow* Window)
{
	window = Window;
}

Game_control::~Game_control()
{
}

void Game_control::poll_events()
{
	event_nm = 0;
	while (this->window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			if (event.key.code == sf::Keyboard::A)
			{
				event_nm = 1;
			}
			break;
		}
	}
}

void Game_control::updateMousePostion()
{
	mousePosWindow = sf::Mouse::getPosition(*this->window);
	mousePosView = window->mapPixelToCoords(mousePosWindow);
}

void Game_control::tower_choices()
{
	p_clik = mouse_clicked;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		mouse_clicked = 1;
		if (mousePosView.x > 20 && mousePosView.x < 145 && mousePosView.y >20 && mousePosView.y < 145)
		{
			tower_choice = 0;
			tmp_tower_choice = 1;
		}

		if (mousePosView.x > 145 && mousePosView.x < 270 && mousePosView.y >20 && mousePosView.y < 145)
		{
			tower_choice = 0;
			tmp_tower_choice = 2;
		}

		if (mousePosView.x > 270 && mousePosView.x < 395 && mousePosView.y >20 && mousePosView.y < 145)
		{
			tower_choice = 0;
			tmp_tower_choice = 3;
		}

		if (mousePosView.x > 395 && mousePosView.x < 520 && mousePosView.y >20 && mousePosView.y < 145)
		{
			tower_choice = 0;
			tmp_tower_choice = 4;
		}
	}
	else
	{
		mouse_clicked = 0;
	}

	if (mouse_clicked == 0 && p_clik == 1)
	{
		tower_choice = tmp_tower_choice;
		tmp_tower_choice = 0;
	}
	else
		tower_choice = 0;
}

void Game_control::update()
{
	poll_events();
	updateMousePostion();
	tower_choices();
}

int Game_control::get_Event_nm()
{
	return event_nm;
}

int Game_control::get_tower_choice()
{
	return tower_choice;
}

sf::Vector2f Game_control::getMousePos()
{
	return mousePosView;
}

void Game_control::reset_tower_choice()
{
	tower_choice = 0;
}

bool Game_control::get_mouse_clicked()
{
	return mouse_clicked;
}

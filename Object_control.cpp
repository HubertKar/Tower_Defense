#include "Object_control.h"


void Object_control::spawnTower(std::vector <Tower*>& tower_list)
{
}

void Object_control::spawnEnemy(std::vector <Enemy*>& enemy_list, sf::Vector2f start_pos, vector<sf::Vector2f> path, int Index, float Speed, int Hp, int Value, float Height, float Width)
{
	Enemy* enemy = new Enemy(map->get_start_postion().x, map->get_start_postion().y, Index, Speed, Hp, path, Height, Width, Value);
	enemy_list.push_back(enemy);
}

void Object_control::move(std::vector <Enemy*>& enemy_list)
{
	for(int i =0; i< enemy_list.size(); i++)
	{
		if (enemy_list[i]->get_died() == false)
		{
			enemy_list[i]->move();
		}
	}
}

void Object_control::bulletControl(std::vector<Bullet*>& bullet_list, std::vector <Enemy*>& enemy_list)
{
	for (int i = 0; i < bullet_list.size(); i++)
	{
		if (!bullet_list[i]->get_reached_range_limit())
		{
			/// Do poprawy //////////////////////////////////////////// zrobic tu normalna  detekcje kolizji
			for (int j = 0; j < enemy_list.size(); j++) 
			{
				double distance = sqrt(powf(bullet_list[i]->get_position().x - enemy_list[j]->get_position().x, 2) + powf(bullet_list[i]->get_position().y - enemy_list[j]->get_position().y, 2));
				if (distance < 30)
				{
					enemy_list[j]->take_damage(bullet_list[i]->get_damage());
					delete bullet_list[i];
					bullet_list.erase(bullet_list.begin() + i);
					this->graphic_control->remove_sprite_from_vector(2, i);
					break;
				}
			}
			bullet_list[i]->move();
		}
		if (bullet_list[i]->get_reached_range_limit())
		{
			delete bullet_list[i];
			bullet_list.erase(bullet_list.begin() + i);
			this->graphic_control->remove_sprite_from_vector(2, i);
		}
	}
}

void Object_control::enemyControl(std::vector <Enemy*>& enemy_list, sf::Vector2f start_pos, vector<sf::Vector2f> path, int event_number, std::vector <std::string> wave_conf)
{
	for (int i = 0; i < enemy_list.size(); i++)
	{
		if (enemy_list[i]->get_died() == true)
		{
			delete enemy_list[i];
			enemy_list[i] = nullptr;
			enemy_list.erase(enemy_list.begin() + i);
			this->graphic_control->remove_sprite_from_vector(1, i);
		}
	}
	switch (event_number)
	{
	case 1:
		spawnEnemy(enemy_list, start_pos, path, 0, 4.f, 100, 5, 62, 80);
		this->graphic_control->add_to_sprite_vector(start_pos, 0, 1, 0);
		break;
	default:
		break;
	}

	if (current_time - enemy_time_spawn > 0.7 && current_time - wave_delay > 20)
	{
		wave = this->map->getWave() + 1;
		if (wave < wave_conf.size())
		{
			char enemy_type = wave_conf[this->map->getWave() + 1][enemy_spawned];
			switch (enemy_type)
			{
			case '0':
				spawnEnemy(enemy_list, start_pos, path, 0, 3.f, 80, 5, 62, 80);
				this->graphic_control->add_to_sprite_vector(start_pos, 0, 1, 0);
				enemy_spawned += 1;
				break;

			case '1':
				spawnEnemy(enemy_list, start_pos, path, 1, 3.f, 120, 10, 62, 80);
				this->graphic_control->add_to_sprite_vector(start_pos, 0, 1, 1);
				enemy_spawned += 1;
				break;

			case '2':
				spawnEnemy(enemy_list, start_pos, path, 2, 3.f, 120, 20, 62, 80);
				this->graphic_control->add_to_sprite_vector(start_pos, 0, 1, 2);
				enemy_spawned += 1;
				break;

			case '3':
				spawnEnemy(enemy_list, start_pos, path, 3, 3.f, 200, 40, 62, 80);
				this->graphic_control->add_to_sprite_vector(start_pos, 0, 1, 3);
				enemy_spawned += 1;
				break;

			case 'k':
				enemy_spawned = 0;
				this->map->set_wave(this->map->getWave() + 1);
				wave_delay = current_time;
				break;

			default:
				break;
			}
			enemy_time_spawn = current_time;
		}
	}


	for (int i = 0; i < enemy_list.size(); i++)
	{
		if (enemy_list[i]->get_reached_base())
		{
			enemy_list[i]->set_died(true);
			take_player_damage(1);
		}
		if (enemy_list[i]->get_hp() <= 0)
		{
			enemy_list[i]->set_died(true);
			this->map->change_money(enemy_list[i]->get_value());
		}
	}
	
}

void Object_control::take_player_damage(int damage)
{
	if (map->getHP() - damage >= 0)
		map->setHP(map->getHP() - damage);
	else
		map->setHP(0);
}

void Object_control::buy_tower(int tc, sf::Vector2f mouse_position, std::vector<std::vector<sf::Vector2f>> colision_rect, bool mouse_clicked)
{

	switch (tc)
	{
	case 1:
		if (map->getMoney() >= 300)
			Tower_choice = 1;
		break;
	case 2:
		if (map->getMoney() >= 500)
			Tower_choice = 2;
		break;
	case 3:
		if (map->getMoney() >= 800)
			Tower_choice = 3;
		break;
	default:
		break;
	}
	
	if (Tower_choice != 0)
	{
		if (test_tower_created == 0)
		{
			Tower* tmp = nullptr;
			switch (Tower_choice)
			{
			case 1:
				tmp = new Tower1(mouse_position.x, mouse_position.y, Tower_choice - 1, 300, 3, 300, 70, 70, 1);
				break;

			case 2:
				tmp = new Tower1(mouse_position.x, mouse_position.y, Tower_choice - 1, 250, 10, 500, 70, 70, 2);
				break;

			case 3:
				tmp = new Tower2(mouse_position.x, mouse_position.y, Tower_choice - 1, 2000, 1, 800, 70, 70, 3);
				break;
			}
			map->set_t_tower(tmp);
			test_tower_created = 1;
			this->graphic_control->add_to_sprite_vector(mouse_position, 0 , 4, Tower_choice - 1);
		}

		map->get_t_tower()->change_position(mouse_position);

		bool colision = 0;
		colision = check_tower_colison(map->get_t_tower(), this->map->get_tower_list(), colision_rect, colision_rect);

		 if (colision == 1)
			 this->map->get_t_tower()->set_index(Tower_choice - 1 + 4);
		 else
			 this->map->get_t_tower()->set_index(Tower_choice - 1);

		 if (colision == 0 and mouse_clicked == 1)
		 {
			 this->map->get_tower_list().push_back(this->map->get_t_tower());
			 this->graphic_control->add_to_sprite_vector(map->get_t_tower()->get_position(), 0, 3, map->get_t_tower()->get_index());

			 this->map->change_money(-this->map->get_t_tower()->get_price());

			 this->map->reset_t_tower();
			 this->graphic_control->remove_sprite_from_vector(4, 0);

			 test_tower_created = 0;
			 Tower_choice = 0;
		 }
	}
}


bool Object_control::AABB_colision_detection(sf::Vector2f pos1, float h1, float w1, sf::Vector2f pos2, float h2, float w2)
{
	pos1.x = pos1.x - w1 / 2;
	pos1.y = pos1.y - h1 / 2;

	pos2.x = pos2.x - w2 / 2;
	pos2.y = pos2.y - h2 / 2;

	return (pos1.x < pos2.x + w2 &&
		pos1.x + w1 > pos2.x &&
		pos1.y < pos2.y + h2 &&
		h1 + pos1.y > pos2.y);
}

Object_control::Object_control(Map* Map, Graphic_control* Graphic_control)
{
	graphic_control = Graphic_control;
	map = Map;
	spawnTower(this->map->get_tower_list());
}

Object_control::~Object_control()
{
}

bool Object_control::get_map_finish()
{
	return map_finished;
}

void Object_control::movingObjectControl(std::vector <Enemy*>& enemy_list, sf::Vector2f start_pos, vector<sf::Vector2f> path, int event_number, std::vector <std::string> wave_conf)
{
	enemyControl(enemy_list, start_pos, path, event_number, wave_conf);
	bulletControl(map->get_bullet_list(), map->get_enemy_list());
	move(enemy_list);
}

void Object_control::uiControl()
{
	this->map->set_wave_timer(int(20 - current_time + wave_delay));
}

void Object_control::towerControl(std::vector <Tower*>& tower_list, std::vector <Enemy*>& enemy_list, std::vector <Bullet*>& bullet_list)
{
	for (int i = 0; i < tower_list.size(); i++)
	{
		if (current_time - tower_list[i]->get_last_shoot_time() > 1/tower_list[i]->get_rof())
		{
			Bullet* bullet = tower_list[i]->shoot(enemy_list);
			if (bullet != nullptr)
			{
				bullet_list.push_back(bullet);
				this->graphic_control->add_to_sprite_vector(bullet->get_position(), bullet->get_rotation(), 2, bullet->get_index());
				tower_list[i]->set_last_shoot_time(current_time);
			}

		}
	}
}


bool Object_control::check_tower_colison(Tower *tower_t, std::vector<Tower*>& Tower_list, std::vector<std::vector<sf::Vector2f>> regions, std::vector<std::vector<sf::Vector2f>> colision_rect)
{
	if (tower_t->get_position().x > 1245 or tower_t->get_position().x < 35 or tower_t->get_position().y > 685 or tower_t->get_position().y < 35)
		return 1;

	if (tower_t->get_position().y  < 140)
		return 1;

	for (int i = 0; i < colision_rect.size(); i++)
	{

		// AABB colision detection
		sf::Vector2f hitbox_center;
		hitbox_center.x = (colision_rect[i][0].x + colision_rect[i][1].x + colision_rect[i][2].x + colision_rect[i][3].x) / 4;
		hitbox_center.y = (colision_rect[i][0].y + colision_rect[i][1].y + colision_rect[i][2].y + colision_rect[i][3].y) / 4;

		float p_width;
		float p_height;

		if (abs(colision_rect[i][0].x - colision_rect[i][1].x) > abs(colision_rect[i][0].x - colision_rect[i][3].x))
			p_width = abs(colision_rect[i][0].x - colision_rect[i][1].x);
		else
			p_width = abs(colision_rect[i][0].x - colision_rect[i][3].x);

		if (abs(colision_rect[i][0].y - colision_rect[i][3].y) > abs(colision_rect[i][0].y - colision_rect[i][1].y))
			p_height = abs(colision_rect[i][0].y - colision_rect[i][3].y);
		else
			p_height = abs(colision_rect[i][0].y - colision_rect[i][1].y);

		hitbox_center.x = (colision_rect[i][0].x + colision_rect[i][1].x + colision_rect[i][2].x + colision_rect[i][3].x) / 4;
		hitbox_center.y = (colision_rect[i][0].y + colision_rect[i][1].y + colision_rect[i][2].y + colision_rect[i][3].y) / 4;

		if(AABB_colision_detection(tower_t->get_position(), tower_t->get_hitbox().height, tower_t->get_hitbox().width, hitbox_center, p_height, p_width))
			return 1;
	}

	for (int i = 0; i < Tower_list.size(); i++)
	{
		if (AABB_colision_detection(tower_t->get_position(), tower_t->get_hitbox().height, tower_t->get_hitbox().width, Tower_list[i]->get_position(), Tower_list[i]->get_hitbox().height, Tower_list[i]->get_hitbox().width))
			return 1;
	}

	return 0;
}

void Object_control::update(int event_number, int tower_choice, sf::Vector2f mouse_position, bool mouse_cliked)
{
	current_time = std::clock() / (double)CLOCKS_PER_SEC;
	movingObjectControl(map->get_enemy_list(), map->get_start_postion(), map->get_path(), event_number, map->get_wave_conf());
	towerControl(map->get_tower_list(), map->get_enemy_list(), map->get_bullet_list());
	buy_tower(tower_choice, mouse_position, map->get_path_colision(), mouse_cliked);
	uiControl();

	if (wave >= this->map->get_wave_conf().size() and map->getHP() > 0 and map->get_enemy_list().size() == 0)
		map_finished = 1;
}


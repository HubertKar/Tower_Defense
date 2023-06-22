#include "Map.h"

	void Map::importData()
	{
		std::string FilePath = "Data/Maps/Map" + std::to_string(number) + "/MapData.txt";
		std::ifstream plik(FilePath);
		
		if (plik.is_open())
		{
			plik >> maxPlayerHp;
			plik >> money;
			std::string wave_conf_line;
			while (std::getline(plik, wave_conf_line))
			{
				wave_conf.push_back(wave_conf_line);
			}
		}
		plik.close();
	}

	Map::Map(int Number)
	{
		number = Number;
		importData();

		PlayerHp = maxPlayerHp;

		this->Path = new path(number);
		std::vector<sf::Vector2f> tmp_path = Path->get_path();

		start_pos = tmp_path[0];
		end_pos = tmp_path[tmp_path.size() - 1];
	}

	Map::~Map()
	{
		delete this->Path;
		for (int i = 0; i < enemy_list.size(); i++)
		{
			delete enemy_list[i];
		}
		this->enemy_list.clear();

		for (int i = 0; i < bullet_list.size(); i++)
		{
			delete bullet_list[i];
		}
		this->bullet_list.clear();

		for (int i = 0; i < tower_list.size(); i++)
		{
			delete tower_list[i];
		}
		this->tower_list.clear();
	}

	std::vector<Enemy*>& Map::get_enemy_list()
	{
		return enemy_list;
	}

	std::vector <Tower*>& Map::get_tower_list()
	{
		return tower_list;
	}

	std::vector <Bullet*>& Map::get_bullet_list()
	{
		return bullet_list;
	}

	Tower* Map::get_t_tower()
	{
		return t_tower;
	}


	sf::Vector2f Map::get_start_postion()
	{
		return start_pos;
	}

	std::vector<sf::Vector2f> Map::get_path()
	{
		return this->Path->get_path();
	}

	std::vector<std::vector<sf::Vector2f>> Map::get_path_colision()
	{
		return this->Path->get_colision_rect();
	}


	void Map::set_t_tower(Tower* t)
	{
		t_tower = t;
	}

	void Map::reset_t_tower()
	{
		t_tower = nullptr;
	}

	void Map::setHP(int HP)
	{
		PlayerHp = HP;
	}

	float Map::getHP()
	{
		return PlayerHp;
	}

	float Map::getMaxHp()
	{
		return maxPlayerHp;
	}

	int Map::getMoney()
	{
		return money;
	}

	int Map::getWave()
	{
		return wave;
	}

	int Map::get_wave_timer()
	{
		return wave_timer;
	}

	void Map::change_money(int x)
	{
		money = money + x;
	}

	std::vector<std::string> Map::get_wave_conf()
	{
		return wave_conf;
	}

	void Map::set_wave(int wave_nb)
	{
		wave = wave_nb;
	}

	void Map::set_wave_timer(int timer)
	{	
		if (timer < 0)
			wave_timer = 0;
		else
			wave_timer = timer;
	}


	int Map::get_map_number()
	{
		return number;
	}



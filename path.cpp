#include "path.h"

void path::import_lines(int map_number)
{
	std::string FilePath = "Data/Maps/Map" + std::to_string(map_number) + "/lines.txt";
	std::ifstream plik(FilePath);

	if (plik.is_open())
	{
		while (!plik.eof())
		{
				float p1;
				float p2;

				plik >> p1;
				plik >> p2;
				sf::Vector2f T(p1, p2);
				lines.push_back(T);
		}
	}

	else {
	}

}

void path::construct_colision_rect()
{
	for (int i = 0; i < lines.size() - 1; i++)
	{
		float deltaX = lines[i + 1].x - lines[i].x;
		float deltaY = lines[i + 1].y - lines[i].y;

		float rotation_radians = atan2(deltaY, deltaX);

		sf::Vector2f p1, p2, p3, p4;

		p4.x = lines[i].x - path_width / 2 * sin(rotation_radians);
		p4.y = lines[i].y + path_width / 2 * cos(rotation_radians);

		p3.x = lines[i].x + path_width / 2 * sin(rotation_radians);
		p3.y = lines[i].y - path_width / 2 * cos(rotation_radians);
		 
		p2.x = lines[i + 1].x + path_width / 2 * sin(rotation_radians);
		p2.y = lines[i + 1].y - path_width / 2 * cos(rotation_radians);

		p1.x = lines[i + 1].x - path_width / 2 * sin(rotation_radians);
		p1.y = lines[i + 1].y + path_width / 2 * cos(rotation_radians);

		std::vector <sf::Vector2f> tmp_vect;
		tmp_vect.push_back(p1);
		tmp_vect.push_back(p2);
		tmp_vect.push_back(p3);
		tmp_vect.push_back(p4);

		colision_rect.push_back(tmp_vect);
	}

	//for (int i = 0; i < colision_rect.size(); i++)
	//{
	//	std::cout << "REC:" << i << std::endl;
	//	for (int j = 0; j < 4; j++)
	//	{
	//		std::cout << "x:" << colision_rect[i][j].x;
	//		std::cout << " y:" << colision_rect[i][j].y << std::endl;
	//	}

	//}

}

path::path(int map_number)
{
	import_lines(map_number);
	construct_colision_rect();
}

path::~path()
{
	lines.clear();
}

std::vector<sf::Vector2f> path::get_path()
{
	return lines;
}

std::vector<std::vector<sf::Vector2f>> path::get_colision_rect()
{
	return colision_rect;
}


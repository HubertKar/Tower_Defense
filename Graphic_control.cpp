#include "Graphic_control.h"

Graphic_control::Graphic_control(Drawing* Drawing, Map* Map)
{
	drawing = Drawing;
	map = Map;
}

Graphic_control::~Graphic_control()
{
}

void Graphic_control::add_to_sprite_vector(sf::Vector2f position, float rotaion, int vector_nb, int index)
{
	sf::Sprite* sprite = new sf::Sprite;
	sprite->setPosition(position);

	switch (vector_nb)
	{
	case 1:
		sprite->setTexture(this->drawing->get_Enemy_Texture_buffer()[index]);
		sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
		sprite->setRotation(0);
		this->drawing->get_Enemy_Sprite_list().push_back(sprite);
		break;

	case 2:
		sprite->setTexture(this->drawing->get_Bullet_Texture_buffer()[index]);
		sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
		sprite->setRotation(0);
		this->drawing->get_Bullet_Sprite_list().push_back(sprite);
		break;

	case 3:
		sprite->setTexture(this->drawing->get_Tower_Texture_buffer()[index]);
		sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
		sprite->setRotation(0);
		this->drawing->get_Tower_Sprite_list().push_back(sprite);
		break;

	case 4:
		sprite->setTexture(this->drawing->get_Tower_Texture_buffer()[index]);
		sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
		sprite->setRotation(0);
		this->drawing->get_t_Tower_list().push_back(sprite);
		break;
	}
}

void Graphic_control::remove_sprite_from_vector(int vector_nb, int index)
{

	switch (vector_nb)
	{
	case 1:
		delete this->drawing->get_Enemy_Sprite_list()[index];
		this->drawing->get_Enemy_Sprite_list().erase(drawing->get_Enemy_Sprite_list().begin() + index);
		break;

	case 2:
		delete this->drawing->get_Bullet_Sprite_list()[index];
		this->drawing->get_Bullet_Sprite_list().erase(drawing->get_Bullet_Sprite_list().begin() + index);
		break;

	case 3:
		delete this->drawing->get_Tower_Sprite_list()[index];
		this->drawing->get_Tower_Sprite_list().erase(drawing->get_Tower_Sprite_list().begin() + index);
		break;

	case 4:
		delete this->drawing->get_t_Tower_list()[index];
		this->drawing->get_t_Tower_list().erase(drawing->get_t_Tower_list().begin() + index);
		break;
	}
}

void Graphic_control::update_sprite(sf::Vector2f position, float rotaion, int vector_nb, int index, int id)
{
	switch (vector_nb)
	{
	case 1:
		this->drawing->get_Enemy_Sprite_list()[index]->setPosition(position);
		this->drawing->get_Enemy_Sprite_list()[index]->setRotation(rotaion);
		if (id >= 0)
			this->drawing->get_Enemy_Sprite_list()[index]->setTexture(this->drawing->get_Enemy_Texture_buffer()[id]);
		break;

	case 2:
		this->drawing->get_Bullet_Sprite_list()[index]->setPosition(position);
		this->drawing->get_Bullet_Sprite_list()[index]->setRotation(rotaion);
		if (id >= 0)
			this->drawing->get_Bullet_Sprite_list()[index]->setTexture(this->drawing->get_Bullet_Texture_buffer()[id]);
		break;

	case 3:
		this->drawing->get_Tower_Sprite_list()[index]->setPosition(position);
		this->drawing->get_Tower_Sprite_list()[index]->setRotation(rotaion);
		if (id >= 0)
			this->drawing->get_Tower_Sprite_list()[index]->setTexture(this->drawing->get_Tower_Texture_buffer()[id]);
		break;

	case 4:

		this->drawing->get_t_Tower_list()[0]->setPosition(position);
		this->drawing->get_t_Tower_list()[0]->setRotation(rotaion);
		if (id >= 0)
			this->drawing->get_t_Tower_list()[0]->setTexture(this->drawing->get_Tower_Texture_buffer()[id]);
		break;
	}
}

void Graphic_control::update()
{
	this->drawing->update_other();

	for (int i = 0; i < map->get_enemy_list().size(); i++)
	{
		update_sprite(map->get_enemy_list()[i]->get_position(), map->get_enemy_list()[i]->get_rotation(), 1, i);
	}

	for (int i = 0; i < map->get_bullet_list().size(); i++)
	{
		update_sprite(map->get_bullet_list()[i]->get_position(), map->get_bullet_list()[i]->get_rotation(), 2, i);
	}

	for (int i = 0; i < map->get_tower_list().size(); i++)
	{
		update_sprite(map->get_tower_list()[i]->get_position(), map->get_tower_list()[i]->get_rotation(), 3, i);
	}

	if (map->get_t_tower() != nullptr)
	{
		update_sprite(map->get_t_tower()->get_position(), map->get_t_tower()->get_rotation(), 4, 0, map->get_t_tower()->get_index());
	}

}



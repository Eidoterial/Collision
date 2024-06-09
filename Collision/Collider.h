#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"


class Rectangle_Collider : public Rectangle_Collision {
private:

	sf::Vector2f position;
	sf::Vector2f size;

public:

	Rectangle_Collider(sf::Vector2f position, sf::Vector2f size) : position(position), size(size){}

	void set_Position(sf::Vector2f new_position) { position = new_position; }
	sf::Vector2f get_Position() const { return position; }

	void set_Size(sf::Vector2f new_size) { size = new_size; }
	sf::Vector2f get_Size() const { return size; }

};

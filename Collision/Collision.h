#pragma once
#include <SFML/Graphics.hpp>

class Rectangle_Collision {
private:

public:

	Rectangle_Collision() {}

	bool check_On_Collision(sf::Vector2f main_start_position, sf::Vector2f main_size,
		sf::Vector2f second_start_position, sf::Vector2f second_size) const;

	sf::Vector2f collision_Repositioner(sf::Vector2f velosity, sf::Vector2f main_start_position, sf::Vector2f main_size, sf::Vector2f second_start_position, sf::Vector2f second_size);

};
#include <iostream>
#include "Collider.h"


void player_move(sf::Vector2f velosity, Rectangle_Collider& player) { player.set_Position(player.get_Position() + velosity); }




int main() {

	sf::RenderWindow window(sf::VideoMode(400, 400), "Collision", sf::Style::Default);

	window.setFramerateLimit(60);

	sf::RectangleShape mask;

	Rectangle_Collider rect(sf::Vector2f(180, 180), sf::Vector2f(20, 20));
	Rectangle_Collider player(sf::Vector2f(15, 10), sf::Vector2f(40, 40));

	while (window.isOpen()) {
		sf::Event eventer;

		while (window.pollEvent(eventer)) {

			if (eventer.type == sf::Event::KeyPressed) {

				if (eventer.key.code == sf::Keyboard::A) {
					player_move(sf::Vector2f(-5, 0), player);
					if (player.check_On_Collision(player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size())) {
						player.set_Position(player.collision_Repositioner(sf::Vector2f(-5, 0), player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size()));

					}

				}
				else if (eventer.key.code == sf::Keyboard::D) {
					player_move(sf::Vector2f(5, 0), player);
					if (player.check_On_Collision(player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size())) {
						player.set_Position(player.collision_Repositioner(sf::Vector2f(5, 0), player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size()));

					}

				}

				else if (eventer.key.code == sf::Keyboard::W) {
					player_move(sf::Vector2f(0, -5), player);
					if (player.check_On_Collision(player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size())) {
						player.set_Position(player.collision_Repositioner(sf::Vector2f(0, -5), player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size()));

					}

				}

				else if (eventer.key.code == sf::Keyboard::S) {
					player_move(sf::Vector2f(0, 5), player);
					if (player.check_On_Collision(player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size())) {
						player.set_Position(player.collision_Repositioner(sf::Vector2f(0, 5), player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size()));

					}

				}

				else if (eventer.key.code == sf::Keyboard::Escape) window.close();

			}

		}

		window.clear();

		mask.setPosition(rect.get_Position());
		mask.setSize(rect.get_Size());

		window.draw(mask);

		mask.setPosition(player.get_Position());
		mask.setSize(player.get_Size());

		window.draw(mask);

		window.display();

		if (player.check_On_Collision(player.get_Position(), player.get_Size(), rect.get_Position(), rect.get_Size()));


	}
	


	return 0;

}
#include "Collision.h"


bool Rectangle_Collision::check_On_Collision(sf::Vector2f main_start_position, sf::Vector2f main_size,
    sf::Vector2f second_start_position, sf::Vector2f second_size) const {

    sf::Vector2f main_end_position = main_start_position + main_size;
    sf::Vector2f second_end_position = second_start_position + second_size;

    if (((main_end_position.x > second_start_position.x && main_start_position.x < second_start_position.x) ||
         (main_start_position.x < second_end_position.x && main_end_position.x > second_end_position.x) ||
         (main_end_position.x > second_start_position.x && main_start_position.x < second_end_position.x) ||
         (main_end_position.x > second_end_position.x && main_start_position.x < second_start_position.x))
        &&
        ((main_end_position.y > second_start_position.y && main_start_position.y < second_start_position.y) ||
         (main_start_position.y < second_end_position.y && main_end_position.y > second_end_position.y) ||
         (main_end_position.y > second_start_position.y && main_start_position.y < second_end_position.y) ||
         (main_end_position.y > second_end_position.y && main_start_position.y < second_start_position.y))) return true;

    return false;
}

sf::Vector2f Rectangle_Collision::collision_Repositioner(sf::Vector2f velosity, sf::Vector2f main_start_position, sf::Vector2f main_size, sf::Vector2f second_start_position, sf::Vector2f second_size) {
    sf::Vector2f repositioner;

    sf::Vector2f second_end_position = second_start_position + second_size;


    if (velosity.x > 0) repositioner.x = second_start_position.x - main_size.x;
    else if (velosity.x < 0) repositioner.x = second_end_position.x;
    else repositioner.x = main_start_position.x;

    if (velosity.y > 0) repositioner.y = second_start_position.y - main_size.y;
    else if (velosity.y < 0) repositioner.y = second_end_position.y;
    else repositioner.y = main_start_position.y;


    return repositioner;
}


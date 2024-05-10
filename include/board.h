#pragma once

#include <SFML/Graphics.hpp>

#include "constants.h"

class Board{
public:
	void set_position(float x, float y);
	
	[[nodiscard]] sf::Vector2f get_position() const;
	
	[[nodiscard]] int get_size() const;

private:
	sf::Vector2f board_start_position{};
	int board_size{constants::BOARD_SIZE};
	
};

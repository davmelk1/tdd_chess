#include <SFML/System/Vector2.hpp>
#include "board.h"

void Board::set_position(float x, float y) {
	board_start_position = {x, y};
}

sf::Vector2f Board::get_position() const {
	return board_start_position;
}

int Board::get_size() const {
	return board_size;
}


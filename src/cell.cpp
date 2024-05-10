#include "cell.h"

Cell::Cell(ColorEnum color) : color(color) {
}

ColorEnum Cell::get_color() const {
	return color;
}

void Cell::set_position(float x, float y) {
	cell_rectangle.setPosition(x, y);
}

sf::Vector2f Cell::get_position() const {
	return cell_rectangle.getPosition();
}

void Cell::set_size(const sf::Vector2f& size) {
	cell_rectangle.setSize(size);
}

sf::Vector2f Cell::get_size() const {
	return cell_rectangle.getSize();
}

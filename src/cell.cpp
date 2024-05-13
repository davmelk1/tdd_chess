#include "cell.h"

Cell::Cell(ColorEnum color) : color(color) {
    cell_rectangle.setFillColor(color ? constants::WHITE_CELL_COLOR : constants::BLACK_CELL_COLOR);
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

void Cell::set_color(ColorEnum color_) {
    color = color_;
    cell_rectangle.setFillColor(color ? constants::WHITE_CELL_COLOR : constants::BLACK_CELL_COLOR);
}

void Cell::draw(sf::RenderWindow& window) const {
    window.draw(cell_rectangle);
    if (figure_ptr)
        figure_ptr->draw(window);
}

void Cell::add_figure(Figure* figure_pointer) {
    figure_ptr = figure_pointer;
    auto position = cell_rectangle.getPosition();
    auto tlwh = cell_rectangle.getGlobalBounds();
    figure_ptr->set_position_from_center_coordinates(position.x + tlwh.width / 2, position.y + tlwh.height / 2);
}

Figure* Cell::get_figure_pointer() const {
    return figure_ptr;
}

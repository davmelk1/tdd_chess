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

void Cell::set_position(sf::Vector2f pos) {
    cell_rectangle.setPosition(pos);
}


sf::Vector2f Cell::get_position() const {
	return cell_rectangle.getPosition();
}

void Cell::set_size(float size_x, float size_y) {
    cell_rectangle.setSize({size_x, size_y});
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
    if (figure_ptr) {
        if (is_hovered)
            draw_hover_ellipse(window);
        figure_ptr->draw(window);
    }
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

bool Cell::mouse_is_on_this_cell(sf::Vector2i mouse_position) {
    auto bounds = cell_rectangle.getGlobalBounds();
    return bounds.left < mouse_position.x && mouse_position.x < bounds.left + bounds.width &&
           bounds.top < mouse_position.y && mouse_position.y < bounds.top + bounds.height;
}

void Cell::handle_mouse_hovering(const sf::Vector2i& pos) {
    is_hovered = mouse_is_on_this_cell(pos);
}

void Cell::draw_hover_ellipse(sf::RenderWindow& window) const {
    static sf::CircleShape hover_ellipse = [&](){
        sf::CircleShape ellipse;
        ellipse.setRadius(get_size().x / 4);
        ellipse.setScale(0.4 * get_size().x / ellipse.getRadius(), 0.2 * get_size().y / ellipse.getRadius());
        ellipse.setOrigin(ellipse.getLocalBounds().width / 2, ellipse.getLocalBounds().height / 2);
        ellipse.setFillColor({80, 80, 80 });
        return ellipse;
    }();
    auto size{get_size()};
    auto position{get_position()};
    hover_ellipse.setPosition(position.x + size.x / 2, position.y + size.y * 3 / 4);
    window.draw(hover_ellipse);
}

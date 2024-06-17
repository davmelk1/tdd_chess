#include "figure.h"
#include "color_enum.h"

Figure::Figure(ColorEnum color) : color(color) {
    texture.loadFromFile("../figures-removebg-preview.png");
    sprite.setTexture(texture);
}

void Figure::set_position_from_center_coordinates(float x, float y) {
    auto bounds = sprite.getLocalBounds();
    sprite.setPosition(x - bounds.width / 2, y - bounds.height / 2);
}

sf::Vector2f Figure::get_position() const {
    return sprite.getPosition();
}

sf::IntRect Figure::get_figure_rect_from_name_and_color(const std::string& name) {
    sf::Vector2f texture_size = static_cast<sf::Vector2f>(texture.getSize());
    static const std::map<std::string, sf::FloatRect> ma{
        {
            "pawn", {texture_size.x / 6 * 5, texture_size.y / 2,
                        texture_size.x / 6, texture_size.y / 2}
        },
        {
            "knight", {texture_size.x / 6 * 4, texture_size.y / 2,
                        texture_size.x / 6, texture_size.y / 2}
        },
        {
            "bishop", {texture_size.x / 6 * 1, texture_size.y / 2,
                        texture_size.x / 6, texture_size.y / 2}
        },
        {
            "rook", {texture_size.x / 6 * 0, texture_size.y / 2,
                        texture_size.x / 6, texture_size.y / 2}
        },
        {
            "queen", {texture_size.x / 6 * 2, texture_size.y / 2,
                        texture_size.x / 6, texture_size.y / 2}
        },
        {
            "king", {texture_size.x / 6 * 3, texture_size.y / 2,
                        texture_size.x / 6, texture_size.y / 2}
        },
    };
    auto rect = ma.at(name);
    return {static_cast<int>(rect.left), static_cast<int>(rect.top * static_cast<float>(color == White)),
            static_cast<int>(rect.width), static_cast<int>(rect.height)};
}

void Figure::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::Vector2f Figure::get_size() const {
    auto bounds = sprite.getLocalBounds();
    return {bounds.width, bounds.height};
}

void Figure::set_initial_position_to_false() {
    is_in_initial_position = false;
}

ColorEnum Figure::get_color() const {
    return color;
}

bool Figure::set_available_if_so_and_return_status(Cell &cell, std::forward_list<Cell *> &available_moves) {
    if (cell.get_figure_pointer())
        return false;
    available_moves.emplace_front(&cell);
    return true;
}

bool Figure::set_destroyable_if_so_and_return_if_we_should_break(Cell &cell, std::forward_list<Cell *>&
        destroying_moves) const {
    if (!cell.get_figure_pointer())
        return false;
    if (cell.get_figure_color() != color)
        destroying_moves.emplace_front(&cell);
    return true;
}

bool Figure::i_j_in_board_size(int i, int j) {
    return i >= 0 && j >= 0 && i < constants::BOARD_SIZE && j < constants::BOARD_SIZE;
}

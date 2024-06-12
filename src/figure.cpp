#include "figure.h"
#include "color_enum.h"

Figure::Figure(ColorEnum color) : color(color) {
    texture.loadFromFile("../figures-removebg-preview.png");
    sprite.setTexture(texture);
};

void Figure::set_position_from_center_coordinates(float x, float y) {
    auto bounds = sprite.getLocalBounds();
    sprite.setPosition(x - bounds.width / 2, y - bounds.height / 2);
}

sf::Vector2f Figure::get_position() const {
    return sprite.getPosition();
}

sf::IntRect Figure::get_figure_rect_from_name_and_color(const std::string& name) {
    auto texture_size = texture.getSize();
    static const std::map<std::string, sf::FloatRect> ma{
        {
            "pawn", {texture_size.x / 6.f * 5, texture_size.y / 2.f,
                        texture_size.x / 6.f, texture_size.y / 2.f}
        },
        {
            "knight", {texture_size.x / 6.f * 4, texture_size.y / 2.f,
                        texture_size.x / 6.f, texture_size.y / 2.f}
        },
        {
            "bishop", {texture_size.x / 6.f * 1, texture_size.y / 2.f,
                        texture_size.x / 6.f, texture_size.y / 2.f}
        },
        {
            "rook", {texture_size.x / 6.f * 0, texture_size.y / 2.f,
                        texture_size.x / 6.f, texture_size.y / 2.f}
        },
        {
            "queen", {texture_size.x / 6.f * 2, texture_size.y / 2.f,
                        texture_size.x / 6.f, texture_size.y / 2.f}
        },
        {
            "king", {texture_size.x / 6.f * 3, texture_size.y / 2.f,
                        texture_size.x / 6.f, texture_size.y / 2.f}
        },
    };
    auto rect = ma.at(name);
    return {static_cast<int>(rect.left), static_cast<int>(rect.top * color),
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

bool Figure::set_available_if_so_and_return_status(Cell &cell, std::forward_list<Cell *> &available_moves) const {
    if (cell.get_figure_pointer())
        return false;
    available_moves.emplace_front(&cell);
    return true;
}
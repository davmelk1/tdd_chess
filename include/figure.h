#pragma once

#include <SFML/Graphics.hpp>

#include "color_enum.h"
#include "constants.h"

class Figure{
public:
    Figure(ColorEnum color = White);
    
    void set_position_from_center_coordinates(float x, float y);
    
    sf::Vector2f get_position() const;
    
    sf::Vector2f get_size() const;
    
    void draw(sf::RenderWindow& window) const;
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    ColorEnum color;
    sf::IntRect get_figure_rect_from_name_and_color(const std::string& name);
    
};
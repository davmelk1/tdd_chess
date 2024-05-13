#pragma once

#include <SFML/Graphics.hpp>

#include "color_enum.h"
#include "constants.h"
#include "figure.h"

class Cell{
public:
	Cell() = default;
	explicit Cell(ColorEnum color);
	
	ColorEnum get_color() const;
	
	void set_position(float x, float y);
	
	sf::Vector2f get_position() const;
	
	void set_size(const sf::Vector2f& size);
	
	sf::Vector2f get_size() const;
    
    void set_color(ColorEnum color_);
    
    void draw(sf::RenderWindow& window) const;
    
    void add_figure(Figure* figure_pointer);
    
    Figure* get_figure_pointer() const;

private:
	ColorEnum color{White};
	sf::RectangleShape cell_rectangle;
    Figure* figure_ptr{nullptr};
};

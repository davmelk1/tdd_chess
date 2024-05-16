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
	
    void set_position(sf::Vector2f pos);
	
	sf::Vector2f get_position() const;
	
	void set_size(float size_x, float size_y);
	
    void set_size(const sf::Vector2f& size);
	
	sf::Vector2f get_size() const;
    
    void set_color(ColorEnum color_);
    
    void draw(sf::RenderWindow& window) const;
    
    void add_figure(Figure* figure_pointer);
    
    Figure* get_figure_pointer() const;
    
    void handle_mouse_hovering(const sf::Vector2i& pos);
protected:
    ColorEnum color{White};
    sf::RectangleShape cell_rectangle;
    Figure* figure_ptr{nullptr};
    
    bool mouse_is_on_this_cell(sf::Vector2i mouse_position);
    
    bool is_hovered{false};
    
    void draw_hover_ellipse(sf::RenderWindow& window) const;
};

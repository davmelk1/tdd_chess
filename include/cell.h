#pragma once

#include <SFML/Graphics.hpp>
#include <forward_list>

#include "color_enum.h"
#include "constants.h"
#include "figure.h"

class Figure;

class Cell{
public:
	Cell() = default;
	explicit Cell(ColorEnum color);
	
	ColorEnum get_cell_color() const;
	
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
	
	bool cell_contains_position(const sf::Vector2i& pos);
	
	void press();
	
	bool is_pressed() const;
	
	std::forward_list<Cell*> get_available_moves(
        std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board);
	
	void set_available();
	
	void unset_available();
    
    void reset_pressed();
    
    void delete_figure();
    
    bool is_available() const;
    
    ColorEnum get_figure_color() const;
protected:
    ColorEnum color{White};
    sf::RectangleShape cell_rectangle;
    Figure* figure_ptr{nullptr};
    
    bool mouse_is_on_this_cell(sf::Vector2i mouse_position);
    
    bool is_hovered{false};
    
    void draw_hover_ellipse(sf::RenderWindow& window) const;
    
	bool is_cell_pressed{false};
	
	void draw_press_ellipse(sf::RenderWindow& window) const;
	
	void draw_ellipse(sf::RenderWindow& window, sf::CircleShape& ellipse) const;
	
	bool is_cell_available{false};
	
	void draw_available(sf::RenderWindow& window) const;
};

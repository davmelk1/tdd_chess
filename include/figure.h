#pragma once

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <array>

#include "color_enum.h"
#include "constants.h"
#include "cell.h"

class Cell;

class Figure{
public:
    explicit Figure(ColorEnum color = White);
    
    void set_position_from_center_coordinates(float x, float y);
    
    sf::Vector2f get_position() const;
    
    sf::Vector2f get_size() const;
    
    void draw(sf::RenderWindow& window) const;
	
	virtual std::forward_list<Cell*>
    get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board,
                            const Cell* selected_cell) const = 0;
    
    virtual std::forward_list<Cell*>
    get_destroying_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                         Cell* selected_cell) const {return {};};

    
    void set_initial_position_to_false();
    
    bool is_in_initial_position() const;
    
    ColorEnum get_color() const;

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    ColorEnum color;
    sf::IntRect get_figure_rect_from_name_and_color(const std::string& name);
    bool is_in_the_initial_position{true};
    static bool set_available_if_so_and_return_status(Cell &cell, std::forward_list<Cell *> &available_moves) ;
    bool set_destroyable_if_so_and_return_if_we_should_break(Cell &cell, std::forward_list<Cell *>& destroying_moves) const;
    static bool i_j_in_board_size(int i, int j) ;
};

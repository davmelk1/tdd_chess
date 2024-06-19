#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <forward_list>
#include <iostream>

#include "cell.h"
#include "constants.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "text.h"

class Board{
public:
    Board();
    
	void set_position(float x, float y);
 
	
	[[nodiscard]] sf::Vector2f get_position() const;
	
	[[nodiscard]] int get_size() const;
    
    
    
    static sf::Vector2f calculate_board_position_from_constants();
    
    void draw(sf::RenderWindow& window) const;
    
    float get_board_width() const;

    float get_board_height() const;
    
    void handle_mouse_hovering(sf::Vector2i mouse_position);
	
	void handle_mouse_press(const sf::Event::MouseButtonEvent& event);
	
	void draw_labels(sf::RenderWindow& window) const;
    
    [[maybe_unused]] Cell& at(std::pair<int, int>);

    void show_moves();

protected:
    std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> board;
	sf::Vector2f board_start_position{};
	int board_size{constants::BOARD_SIZE};
	std::forward_list<Cell*> available_moves;
    std::forward_list<Cell*> destroying_moves;
    std::forward_list<std::pair<std::string, std::string>> moves;

    ColorEnum order_color{White};
    bool without_order{false};

    void set_position(sf::Vector2f position);
    
    void initialize_pawns();
    
    void initialize_rooks();
    
    void initialize_knights();
    
    void initialize_bishops();
    
    void initialize_queens();
    
    void initialize_kings();
    
    void initialize_figures();
    
    Cell* selected_cell{nullptr};
    
    Cell* get_pressed_cell(const sf::Event::MouseButtonEvent& event);
    
    void reset_clicks();

    void handle_cell_click(Cell *pCell);

    void move_cell_figure_to_selected_cell(Cell *pCell);

    void save_move(Cell *cell1_ptr, Cell *cell2_ptr);
};

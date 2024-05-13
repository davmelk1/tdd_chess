#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "cell.h"
#include "constants.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"

class Board{
public:
    Board();
    
	void set_position(float x, float y);
 
	
	[[nodiscard]] sf::Vector2f get_position() const;
	
	[[nodiscard]] int get_size() const;
    
    static sf::Vector2f calculate_board_position_from_constants();
    
    void draw(sf::RenderWindow& window) const;

protected:
    std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> board;
	sf::Vector2f board_start_position{};
	int board_size{constants::BOARD_SIZE};
    
    void set_position(sf::Vector2f position);
    
    void initialize_pawns();
    
    void initialize_rooks();
    
    void initialize_knights();
    
    void initialize_bishops();
    
    void initialize_queens();
    
    void initialize_kings();
    
    void initialize_figures();
};

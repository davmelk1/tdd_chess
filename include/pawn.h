#pragma once

#include "figure.h"
#include "color_enum.h"

class Pawn : public Figure{
public:
    Pawn(ColorEnum color = White);
    
    std::forward_list<Cell*>
    get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board,
                            Cell* selected_cell) override;
};

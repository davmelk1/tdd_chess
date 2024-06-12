#pragma once

#include "figure.h"
#include "color_enum.h"

class Knight : public Figure{
public:
    Knight(ColorEnum color = White);

    std::forward_list<Cell *>
    get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                            const Cell* selected_cell) {return {};};

    std::forward_list<Cell*>
    get_destroying_moves(const std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board,
                         Cell* selected_cell) const {return {};};
};
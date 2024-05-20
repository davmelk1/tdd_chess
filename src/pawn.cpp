#include <forward_list>
#include "pawn.h"

Pawn::Pawn(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("pawn"));
}

std::forward_list<Cell*>
Pawn::get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board,
                              Cell* selected_cell) {
    int i  = (selected_cell - &board[0][0]) / board.size();
    auto j = selected_cell - &board[i][0];
    int direction = (color == White ? 1 : -1);
    std::forward_list<Cell*> ret;
    i += direction;
    if (board[i][j].get_figure_pointer())
        return ret;
    ret.emplace_front(&board[i][j]);
    i += direction;
    if (board[i][j].get_figure_pointer() || !is_in_initial_position)
        return ret;
    ret.emplace_front(&board[i][j]);
    return ret;
}
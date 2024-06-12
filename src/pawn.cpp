#include <forward_list>
#include "pawn.h"

Pawn::Pawn(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("pawn"));
}

std::forward_list<Cell*>
Pawn::get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board,
                              const Cell* selected_cell) const {
    int i  = (selected_cell - &board[0][0]) / board.size();
    auto j = selected_cell - &board[i][0];
    int direction = (color == White ? 1 : -1);
    i += direction;
    if (i + direction < 0 || i + direction >= board.size())
        return {};
    std::forward_list<Cell*> ret;
    if (board[i][j].get_figure_pointer())
        return ret;
    ret.emplace_front(&board[i][j]);
    i += direction;
    if (board[i][j].get_figure_pointer() || !is_in_initial_position)
        return ret;
    ret.emplace_front(&board[i][j]);
    return ret;
}

std::forward_list<Cell*>
Pawn::get_destroying_moves(const std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board,
                           Cell* selected_cell) const {
    unsigned int i  = (selected_cell - &board[0][0]) / board.size();
    auto j = selected_cell - &board[i][0];
    int direction = (color == White ? 1 : -1);
    if (i + direction < 0 || i + direction >= board.size())
        return {};
    std::forward_list<Cell*> ret;
    if (j + 1 < board.size() && board[i + direction][j + 1].get_figure_pointer() && board[i + direction][j + 1].get_figure_color() != color)
        ret.emplace_front(const_cast<Cell*>(&board[i + direction][j + 1]));
    if (j - 1 >= 0 && board[i + direction][j - 1].get_figure_pointer() && board[i + direction][j - 1].get_figure_color() != color)
        ret.emplace_front(const_cast<Cell*>(&board[i + direction][j - 1]));
    return ret;
}

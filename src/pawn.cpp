#include <forward_list>
#include "pawn.h"

Pawn::Pawn(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("pawn"));
}

std::forward_list<Cell*>
Pawn::get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE>& board,
                              const Cell* selected_cell) const {
    int i  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int j = static_cast<int>(selected_cell - &board[i][0]);
    int direction = (color == White ? 1 : -1);
    if (i + direction < 0 || i + direction >= board.size())
        return {};
    i += direction;
    std::forward_list<Cell*> available_moves;
    if (board[i][j].get_figure_pointer())
        return available_moves;
    available_moves.emplace_front(&board[i][j]);
    i += direction;
    if (board[i][j].get_figure_pointer() || !is_in_initial_position)
        return available_moves;
    available_moves.emplace_front(&board[i][j]);
    return available_moves;
}

std::forward_list<Cell*>
Pawn::get_destroying_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                           Cell* selected_cell) const {
    int i  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int j = static_cast<int>(selected_cell - &board[i][0]);
    int direction = (color == White ? 1 : -1);
    if (i + direction < 0 || i + direction >= board.size())
        return {};
    std::forward_list<Cell*> destroying_moves;
    if (i_j_in_board_size(i + direction, j + 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i + direction][j + 1], destroying_moves);
    if (i_j_in_board_size(i + direction, j - 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i + direction][j - 1], destroying_moves);
    return destroying_moves;
}

#include "knight.h"

Knight::Knight(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("knight"));
}

std::forward_list<Cell *>
Knight::get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                                const Cell *selected_cell) const {
    int row  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int col = static_cast<int>(selected_cell - &board[row][0]);
    std::forward_list<Cell*> available_moves;

    for (int i = 1; i < 3; ++i) {
        int j = i % 2 + 1;
        if (row + i < board.size() && col + j < board[0].size())
            set_available_if_so_and_return_status(board[row+i][col+j], available_moves);
        if (row + i < board.size() && col + j >= 0)
            set_available_if_so_and_return_status(board[row+i][col-j], available_moves);
        if (row - i >= 0 && col + j < board[0].size())
            set_available_if_so_and_return_status(board[row-i][col+j], available_moves);
        if (row - i >= 0 && col - j >= 0)
            set_available_if_so_and_return_status(board[row-i][col-j], available_moves);
    }

    return available_moves;
}

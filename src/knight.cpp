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
        if (i_j_in_board_size(row + i, col + j))
            set_available_if_so_and_return_status(board[row+i][col+j], available_moves);
        if (i_j_in_board_size(row + i, col - j))
            set_available_if_so_and_return_status(board[row+i][col-j], available_moves);
        if (i_j_in_board_size(row - i, col + j))
            set_available_if_so_and_return_status(board[row-i][col+j], available_moves);
        if (i_j_in_board_size(row - i, col - j))
            set_available_if_so_and_return_status(board[row-i][col-j], available_moves);
    }

    return available_moves;
}

std::forward_list<Cell *>
Knight::get_destroying_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                             Cell *selected_cell) const {
    int row  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int col = static_cast<int>(selected_cell - &board[row][0]);
    std::forward_list<Cell*> destroying_moves;
    for (int i = 1; i < 3; ++i) {
        int j = i % 2 + 1;
        if (i_j_in_board_size(row + i, col + j))
            set_destroyable_if_so_and_return_if_we_should_break(board[row+i][col+j], destroying_moves);
        if (i_j_in_board_size(row + i, col - j))
            set_destroyable_if_so_and_return_if_we_should_break(board[row+i][col-j], destroying_moves);
        if (i_j_in_board_size(row - i, col + j))
            set_destroyable_if_so_and_return_if_we_should_break(board[row-i][col+j], destroying_moves);
        if (i_j_in_board_size(row - i, col - j))
            set_destroyable_if_so_and_return_if_we_should_break(board[row-i][col-j], destroying_moves);
    }


    return destroying_moves;
}

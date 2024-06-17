#include "king.h"

King::King(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("king"));
}

std::forward_list<Cell *>
King::get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                              const Cell *selected_cell) const {
    int i  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int j = static_cast<int>(selected_cell - &board[i][0]);
    std::forward_list<Cell*> available_moves;

    for (int ii = i-1; ii < i+2; ++ii) {
        if (ii >= static_cast<int>(board.size()))
            break;
        if (ii < 0)
            continue;
        for (int jj = j - 1; jj < j + 2; ++jj) {
            if (jj >= static_cast<int>(board[0].size()))
                break;
            if (jj < 0)
                continue;
            if (ii == i && jj == j)
                continue;

            set_available_if_so_and_return_status(board[ii][jj], available_moves);
        }
    }

    return available_moves;

}

std::forward_list<Cell *>
King::get_destroying_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                           Cell *selected_cell) const {
    int i  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int j = static_cast<int>(selected_cell - &board[i][0]);
    std::forward_list<Cell*> destroying_moves;
    if (i_j_in_board_size(i - 1, j))
        set_destroyable_if_so_and_return_if_we_should_break(board[i - 1][j], destroying_moves);
    if (i_j_in_board_size(i, j - 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i][j - 1], destroying_moves);
    if (i_j_in_board_size(i + 1 , j))
        set_destroyable_if_so_and_return_if_we_should_break(board[i + 1][j], destroying_moves);
    if (i_j_in_board_size(i, j + 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i][j + 1], destroying_moves);
    if (i_j_in_board_size(i + 1, j + 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i + 1][j + 1], destroying_moves);
    if (i_j_in_board_size(i + 1, j - 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i + 1][j - 1], destroying_moves);
    if (i_j_in_board_size(i - 1, j + 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i - 1][j + 1], destroying_moves);
    if (i_j_in_board_size(i - 1, j - 1))
        set_destroyable_if_so_and_return_if_we_should_break(board[i - 1][j - 1], destroying_moves);

    return destroying_moves;
}



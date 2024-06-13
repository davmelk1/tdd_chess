#include "queen.h"

Queen::Queen(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("queen"));
}

std::forward_list<Cell *>
Queen::get_all_available_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                               const Cell *selected_cell) const {
    int i  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int j = static_cast<int>(selected_cell - &board[i][0]);
    std::forward_list<Cell*> available_moves;

    for (auto jj = j + 1; jj < board[0].size(); jj++)
        if (!set_available_if_so_and_return_status(board[i][jj], available_moves))
            break;

    for (int jj = j - 1; jj >= 0; jj--)
        if (!set_available_if_so_and_return_status(board[i][jj], available_moves))
            break;

    for (auto ii = i + 1; ii < board.size(); ii++)
        if (!set_available_if_so_and_return_status(board[ii][j], available_moves))
            break;

    for (int ii = i - 1; ii >= 0; ii--)
        if (!set_available_if_so_and_return_status(board[ii][j], available_moves))
            break;

    int jj = j, ii = i;
    while (++jj < board[0].size() && --ii >=0)
        if (!set_available_if_so_and_return_status(board[ii][jj], available_moves))
            break;

    jj = j, ii = i;
    while (--jj >= 0 && --ii >= 0)
        if (!set_available_if_so_and_return_status(board[ii][jj], available_moves))
            break;

    jj = j, ii = i;
    while (++jj < board[0].size() && ++ii < board.size())
        if (!set_available_if_so_and_return_status(board[ii][jj], available_moves))
            break;

    jj = j, ii = i;
    while (--jj >= 0 && ++ii < board.size())
        if (!set_available_if_so_and_return_status(board[ii][jj], available_moves))
            break;

    return available_moves;
}

std::forward_list<Cell *>
Queen::get_destroying_moves(std::array<std::array<Cell, constants::BOARD_SIZE>, constants::BOARD_SIZE> &board,
                            Cell *selected_cell) const {
    int i  = static_cast<int>((selected_cell - &board[0][0]) / board.size());
    int j = static_cast<int>(selected_cell - &board[i][0]);
    std::forward_list<Cell*> destroying_moves;

    for (auto jj = j + 1; jj < board[0].size(); jj++)
        if (set_destroyable_if_so_and_return_if_we_should_break(board[i][jj], destroying_moves))
            break;

    for (int jj = j - 1; jj >= 0; jj--)
        if (set_destroyable_if_so_and_return_if_we_should_break(board[i][jj], destroying_moves))
            break;

    for (auto ii = i + 1; ii < board.size(); ii++)
        if (set_destroyable_if_so_and_return_if_we_should_break(board[ii][j], destroying_moves))
            break;

    for (int ii = i - 1; ii >= 0; ii--)
        if (set_destroyable_if_so_and_return_if_we_should_break(board[ii][j], destroying_moves))
            break;

    int jj = j, ii = i;
    while (++jj < board[0].size() && --ii >=0)
        if (set_destroyable_if_so_and_return_if_we_should_break(board[ii][jj], destroying_moves))
            break;

    jj = j, ii = i;
    while (--jj >= 0 && --ii >= 0)
        if (set_destroyable_if_so_and_return_if_we_should_break(board[ii][jj], destroying_moves))
            break;

    jj = j, ii = i;
    while (++jj < board[0].size() && ++ii < board.size())
        if (set_destroyable_if_so_and_return_if_we_should_break(board[ii][jj], destroying_moves))
            break;

    jj = j, ii = i;
    while (--jj >= 0 && ++ii < board.size())
        if (set_destroyable_if_so_and_return_if_we_should_break(board[ii][jj], destroying_moves))
            break;

    return destroying_moves;
}

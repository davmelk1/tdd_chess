#include <SFML/System/Vector2.hpp>
#include "board.h"

Board::Board() {
    set_position(calculate_board_position_from_constants());
    for (int i = 0; i < get_size(); ++i)
        for (int j = 0; j < get_size(); ++j) {
            board[i][j].set_color((i + j) % 2 ? White : Black);
            board[i][j].set_size({constants::CELL_WIDTH, constants::CELL_WIDTH});
            board[i][j].set_position(board_start_position.x + constants::CELL_WIDTH * j,
                                     board_start_position.y + constants::CELL_WIDTH * i);
        }
    initialize_figures();
}

void Board::set_position(float x, float y) {
	board_start_position = {x, y};
}

void Board::set_position(sf::Vector2f position) {
    board_start_position = position;
}

sf::Vector2f Board::get_position() const {
	return board_start_position;
}

int Board::get_size() const {
	return board_size;
}

sf::Vector2f Board::calculate_board_position_from_constants() {
    auto padding{(constants::WINDOW_WIDTH - constants::BOARD_SIZE * constants::CELL_WIDTH) / 2};
    return {padding, padding};
}

void Board::draw(sf::RenderWindow& window) const {
    for (const auto& row : board)
        for (const auto& cell : row)
            cell.draw(window);
}

void Board::initialize_pawns() {
    for (int i = 0; i < constants::BOARD_SIZE; ++i) {
        board[1][i].add_figure(new Pawn(White));
        board[6][i].add_figure(new Pawn(Black));
    }
}

void Board::initialize_rooks() {
    board[0][0].add_figure(new Rook(White));
    board[0][7].add_figure(new Rook(White));
    board[7][0].add_figure(new Rook(Black));
    board[7][7].add_figure(new Rook(Black));
}

void Board::initialize_knights() {
    board[0][1].add_figure(new Knight(White));
    board[0][6].add_figure(new Knight(White));
    board[7][1].add_figure(new Knight(Black));
    board[7][6].add_figure(new Knight(Black));
}

void Board::initialize_bishops() {
    board[0][2].add_figure(new Bishop(White));
    board[0][5].add_figure(new Bishop(White));
    board[7][2].add_figure(new Bishop(Black));
    board[7][5].add_figure(new Bishop(Black));
}

void Board::initialize_queens() {
    board[0][3].add_figure(new Queen(White));
    board[7][3].add_figure(new Queen(Black));
}

void Board::initialize_kings() {
    board[0][4].add_figure(new King(White));
    board[7][4].add_figure(new King(Black));
}

void Board::initialize_figures() {
    initialize_pawns();
    initialize_bishops();
    initialize_kings();
    initialize_knights();
    initialize_queens();
    initialize_rooks();
}


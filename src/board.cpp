#include <SFML/System/Vector2.hpp>
#include "board.h"

Board::Board() {
    set_position(calculate_board_position_from_constants());
    for (int i = 0; i < get_size(); ++i)
        for (int j = 0; j < get_size(); ++j) {
            board[i][j].set_color((i + j) % 2 ? White : Black);
            board[i][j].set_size({constants::CELL_WIDTH, constants::CELL_WIDTH});
            board[i][j].set_position(board_start_position.x + constants::CELL_WIDTH * static_cast<float>(j),
                                     board_start_position.y + constants::CELL_WIDTH * static_cast<float>(i));
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

float Board::get_board_width() const {
    return board[constants::BOARD_SIZE-1][0].get_position().y + board[constants::BOARD_SIZE-1][0].get_size().y -  board[0][0].get_position().y;
}

float Board::get_board_height() const {
    return board[0][constants::BOARD_SIZE-1].get_position().x + board[0][constants::BOARD_SIZE-1].get_size().x -  board[0][0].get_position().x;
}

void Board::handle_mouse_hovering(sf::Vector2i mouse_position) {
    for (auto& row : board)
        for (auto& cell : row)
            cell.handle_mouse_hovering(mouse_position);
}

void Board::handle_mouse_press(const sf::Event::MouseButtonEvent& event) {
	if (event.button != sf::Mouse::Button::Left)
		return;
    Cell* clicked_cell{get_pressed_cell(event)};
    handle_cell_click(clicked_cell);
}

void Board::draw_labels(sf::RenderWindow& window) const {
	auto board_position = get_position();
	for (int i = 0; i < get_size(); ++i) {
		Text label;
		label.set_text(std::to_string(i + 1));
		label.set_center_position(board_position.x + constants::CELL_WIDTH * static_cast<float>(i) + constants::CELL_WIDTH / 2, board_position.y - label.get_size().y);
		label.draw(window);
		label.set_center_position(board_position.x + constants::CELL_WIDTH * static_cast<float>(i) + constants::CELL_WIDTH / 2, board_position.y + get_board_height() + label.get_size().y);
		label.draw(window);
		label.set_text({char('A' + i)});
		label.set_center_position(board_position.x - 25, board_position.y + static_cast<float>(i) * constants::CELL_WIDTH + constants::CELL_WIDTH / 2);
		label.draw(window);
		label.set_center_position(board_position.x + get_board_width() + 25, board_position.y + static_cast<float>(i) * constants::CELL_WIDTH + constants::CELL_WIDTH / 2);
		label.draw(window);
	}
}

Cell* Board::get_pressed_cell(const sf::Event::MouseButtonEvent& event) {
    for (auto& row : board)
        for (auto& cell : row)
            if (cell.cell_contains_position({event.x, event.y}))
                return &cell;
    return nullptr;
}

void Board::reset_clicks() {
    if (selected_cell)
        selected_cell->reset_pressed();
    selected_cell = nullptr;
    for (auto& available : available_moves)
        available->unset_available();
    available_moves = {};
    for (const auto& move : destroying_moves)
        move->unset_destroyable();
    destroying_moves = {};
}

[[maybe_unused]] Cell& Board::at(std::pair<int, int> position) {
    return board[position.first][position.second];
}

void Board::handle_cell_click(Cell* clicked_cell) {
    if (!clicked_cell) {
        reset_clicks();
        return;
    }

    if (clicked_cell->get_figure_pointer() && !clicked_cell->can_be_destroyed())
        clicked_cell->press();
    if (clicked_cell->is_pressed()) {
        if (clicked_cell != selected_cell && selected_cell)
            reset_clicks();
        selected_cell = clicked_cell;
        available_moves = clicked_cell->get_available_moves(board);
        destroying_moves = clicked_cell->get_destroying_moves(board);
        for (const auto& move: available_moves)
            move->set_available();
        for (const auto& move : destroying_moves)
            move->set_can_be_destroyed();
    } else {
        if (std::find(available_moves.begin(), available_moves.end(), clicked_cell) != available_moves.end()) {
            move_cell_figure_to_selected_cell(clicked_cell);
        } else if (std::find(destroying_moves.begin(), destroying_moves.end(), clicked_cell) != destroying_moves.end()) {
            clicked_cell->delete_figure();
            move_cell_figure_to_selected_cell(clicked_cell);
        }
        reset_clicks();
    }

}

void Board::move_cell_figure_to_selected_cell(Cell* clicked_cell) {
    clicked_cell->add_figure(selected_cell->get_figure_pointer());
    selected_cell->delete_figure();
}


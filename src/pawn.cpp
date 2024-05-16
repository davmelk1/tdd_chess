#include "pawn.h"

Pawn::Pawn(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("pawn"));
}

std::vector<std::pair<int, int>> Pawn::get_all_available_moves(int i, int j) const {
	return {{i-(color == White ? -1 : 1), j}, {i-(color == White ? -2 : 2), j}};
}


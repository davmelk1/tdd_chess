#pragma once

#include "figure.h"
#include "color_enum.h"

class Pawn : public Figure{
public:
    Pawn(ColorEnum color = White);
	
	std::vector<std::pair<int, int>> get_all_available_moves(int i, int j) const override;
};

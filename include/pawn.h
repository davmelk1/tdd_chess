#pragma once

#include "figure.h"
#include "color_enum.h"

class Pawn : public Figure{
public:
    Pawn(ColorEnum color = White);
};
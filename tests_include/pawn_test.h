#pragma once

#include <gtest/gtest.h>

#include "pawn.h"

class PawnTest : public ::testing::Test{
public:
    Pawn pawn;
};


TEST_F(PawnTest, TestFigureSetPosition) {
    pawn.set_position_from_center_coordinates(32, 54);
    auto size = pawn.get_size();
    ASSERT_EQ(pawn.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}
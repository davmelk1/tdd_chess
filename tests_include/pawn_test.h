#pragma once

#include <gtest/gtest.h>

#include "pawn.h"
#include "figure_test.h"

class PawnTest : public ::testing::Test{
public:
    Pawn pawn;
};


TEST_F(PawnTest, TestFigureSetPosition) {
    pawn.set_position_from_center_coordinates(32, 54);
    auto size = pawn.get_size();
    ASSERT_EQ(pawn.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}


TEST_F(DerivedFromBoard, TestAvailableMovesForWhitePawn) {
    auto selected = &board[1][4];
    auto moves = selected->get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][4]), moves.end());
    EXPECT_EQ(distance(moves.begin(), moves.end()), 2);
}
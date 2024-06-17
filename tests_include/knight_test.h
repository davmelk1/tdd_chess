#pragma once

#include <gtest/gtest.h>

#include "knight.h"
#include "board_test.h"

class KnightTest : public ::testing::Test{
public:
    Knight knight;
};


TEST_F(KnightTest, TestFigureSetPosition) {
    knight.set_position_from_center_coordinates(32, 54);
    auto size = knight.get_size();
    ASSERT_EQ(knight.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}

TEST_F(DerivedFromBoard, TestWhiteKnightAvailableMoves) {
    auto moves = board[0][1].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][2]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
    handle_cell_click(&board[0][1]);
    handle_cell_click(&board[2][2]);
    moves = board[2][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[0][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][4]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 5);
}

TEST_F(DerivedFromBoard, TestBlackKnightAvailableMoves) {
    auto moves = board[7][6].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][5]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
    handle_cell_click(&board[7][6]);
    handle_cell_click(&board[5][5]);
    handle_cell_click(&board[5][5]);
    handle_cell_click(&board[4][3]);
    moves = board[4][3].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 6);
}

TEST_F(DerivedFromBoard, TestEmptyDestroyingMovesForKnight) {
    auto moves = board[0][1].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
    moves = board[0][6].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
    moves = board[7][1].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
    moves = board[7][6].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestDestroyingMovesForKnight) {
    handle_cell_click(&board[0][1]);
    available_moves.emplace_front(&board[5][3]);
    handle_cell_click(&board[5][3]);
    handle_cell_click(&board[7][1]);
    available_moves.emplace_front(&board[2][2]);
    handle_cell_click(&board[2][2]);

    auto moves = board[5][3].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 4);
    moves = board[2][2].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 3);

    handle_cell_click(&board[2][2]);
    handle_cell_click(&board[0][1]);
    moves = board[0][1].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 1);
}
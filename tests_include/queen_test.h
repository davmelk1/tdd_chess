#pragma once

#include <gtest/gtest.h>

#include "queen.h"

class QueenTest : public ::testing::Test{
public:
    Queen queen;
};


TEST_F(QueenTest, TestFigureSetPosition) {
    queen.set_position_from_center_coordinates(32, 54);
    auto size = queen.get_size();
    ASSERT_EQ(queen.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}

TEST_F(DerivedFromBoard, TestEmptyAvailableMovesForWhiteQueen) {
    auto moves = board[0][3].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestEmptyAvailableMovesForBlackQueen) {
    auto moves = board[7][3].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestAllAvailableMovesForQueen) {
    handle_cell_click(&board[0][3]);
    available_moves.emplace_front(&board[3][3]);
    handle_cell_click(&board[3][3]);
    auto moves = board[3][3].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][5]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 16);
}

TEST_F(DerivedFromBoard, TestEmptyDestroyingMovesForWhiteQueen) {
    auto moves = board[0][3].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestEmptyDestroyingeMovesForBlackQueen) {
    auto moves = board[7][3].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestDestroyingMovesForQueen) {
    handle_cell_click(&board[7][3]);
    available_moves.emplace_front(&board[2][4]);
    handle_cell_click(&board[2][4]);
    auto moves = board[2][4].get_destroying_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[1][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[1][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[1][5]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 3);

    handle_cell_click(&board[0][3]);
    available_moves.emplace_front(&board[5][4]);
    handle_cell_click(&board[5][4]);
    moves = board[5][4].get_destroying_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 4);
    handle_cell_click(&board[6][3]);
    handle_cell_click(&board[5][3]);
    handle_cell_click(&board[6][5]);
    handle_cell_click(&board[5][5]);
    moves = board[5][4].get_destroying_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[7][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[7][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][5]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 6);

}
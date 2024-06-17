#pragma once

#include <gtest/gtest.h>

#include "king.h"

class KingTest : public ::testing::Test{
public:
    King king;
};


TEST_F(KingTest, TestFigureSetPosition) {
    king.set_position_from_center_coordinates(32, 54);
    auto size = king.get_size();
    ASSERT_EQ(king.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}

TEST_F(DerivedFromBoard, TestWhiteKingEmptyAvailableMoves) {
    auto moves = board[0][5].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestBlackKingEmptyAvailableMoves) {
    auto moves = board[7][5].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestWhiteKingAvailableMoves1) {
    handle_cell_click(&board[1][4]);
    handle_cell_click(&board[3][4]);
    auto moves = board[0][4].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[1][4]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 1);
    handle_cell_click(&board[0][4]);
    handle_cell_click(&board[1][4]);
    moves = board[1][4].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[0][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][5]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 4);
}

TEST_F(DerivedFromBoard, TestBlackKingAvailableMoves1) {
    handle_cell_click(&board[6][4]);
    handle_cell_click(&board[4][4]);
    auto moves = board[7][4].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][4]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 1);
    handle_cell_click(&board[7][4]);
    handle_cell_click(&board[6][4]);
    moves = board[6][4].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[7][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][5]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 4);
}

TEST_F(DerivedFromBoard, TestEmptyDestroyingMovesForKing) {
    auto moves = board[0][4].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
    moves = board[7][4].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestDestroyingMovesForKing) {
    handle_cell_click(&board[0][4]);
    available_moves.emplace_front(&board[2][2]);
    handle_cell_click(&board[2][2]);
    handle_cell_click(&board[7][4]);
    available_moves.emplace_front(&board[0][4]);
    handle_cell_click(&board[0][4]);
    handle_cell_click(&board[2][2]);
    available_moves.emplace_front(&board[7][4]);
    handle_cell_click(&board[7][4]);

    auto moves = board[0][4].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 5);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[0][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[0][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[1][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[1][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[1][5]), moves.end());
    moves = board[7][4].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 5);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[7][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[7][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][5]), moves.end());
}
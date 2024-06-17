#pragma once

#include <gtest/gtest.h>

#include "bishop.h"
#include "board_test.h"

class BishopTest : public ::testing::Test{
public:
    Bishop bishop;
};


TEST_F(BishopTest, TestFigureSetPosition) {
    bishop.set_position_from_center_coordinates(32, 54);
    auto size = bishop.get_size();
    ASSERT_EQ(bishop.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}

TEST_F(DerivedFromBoard, TestWhiteBishopEmptyAvailableMoves1) {
    auto moves = board[0][2].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestBlackBishopEmptyAvailableMoves1) {
    auto moves = board[7][2].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestWhiteBishopEmptyAvailableMoves2) {
    auto moves = board[0][5].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestBlackBishopEmptyAvailableMoves2) {
    auto moves = board[7][5].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestWhiteBishopAvailableMoves1) {
    handle_cell_click(&board[1][1]);
    handle_cell_click(&board[2][1]);
    auto moves = board[0][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[1][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][0]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
}

TEST_F(DerivedFromBoard, TestWhiteBishopAvailableMoves2) {
    handle_cell_click(&board[1][3]);
    handle_cell_click(&board[2][3]);
    auto moves = board[0][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[1][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[3][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[4][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[5][7]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 5);
}

TEST_F(DerivedFromBoard, TestWhiteBishopAvailableMoves3) {
    handle_cell_click(&board[1][3]);
    handle_cell_click(&board[2][3]);
    handle_cell_click(&board[0][2]);
    handle_cell_click(&board[3][5]);
    auto moves = board[3][5].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[0][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[1][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[4][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[5][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[4][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[5][3]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 8);
}

TEST_F(DerivedFromBoard, TestBlackBishopAvailableMoves1) {
    handle_cell_click(&board[6][1]);
    handle_cell_click(&board[5][1]);
    auto moves = board[7][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[6][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[5][0]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
}

TEST_F(DerivedFromBoard, TestBlackBishopAvailableMoves2) {
    handle_cell_click(&board[6][3]);
    handle_cell_click(&board[5][3]);
    auto moves = board[7][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[6][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[5][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[4][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[3][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][7]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 5);
}

TEST_F(DerivedFromBoard, TestBlackBishopAvailableMoves3) {
    handle_cell_click(&board[6][3]);
    handle_cell_click(&board[5][3]);
    handle_cell_click(&board[7][2]);
    handle_cell_click(&board[4][5]);
    auto moves = board[4][5].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[7][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[6][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[5][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[3][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[5][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[3][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][3]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 8);
}

TEST_F(DerivedFromBoard, TestEmptyDestroyingMovesForBishop) {
    auto moves = board[0][2].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
    moves = board[0][5].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
    moves = board[7][2].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
    moves = board[7][5].get_destroying_moves(board);
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestDestroyingMovesForBishop) {
    handle_cell_click(&board[1][4]);
    handle_cell_click(&board[2][4]);
    handle_cell_click(&board[0][5]);
    handle_cell_click(&board[3][2]);
    handle_cell_click(&board[3][2]);
    handle_cell_click(&board[5][4]);
    handle_cell_click(&board[6][1]);
    handle_cell_click(&board[5][1]);
    handle_cell_click(&board[7][2]);
    handle_cell_click(&board[6][1]);
    handle_cell_click(&board[6][1]);
    handle_cell_click(&board[2][5]);
    auto moves = board[2][5].get_destroying_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[0][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[1][6]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
    moves = board[5][4].get_destroying_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[6][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[6][5]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
}
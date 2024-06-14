#pragma once

#include <gtest/gtest.h>

#include "rook.h"
#include "board_test.h"

class RookTest : public ::testing::Test{
public:
    Rook rook;
};


TEST_F(RookTest, TestFigureSetPosition) {
    rook.set_position_from_center_coordinates(32, 54);
    auto size = rook.get_size();
    ASSERT_EQ(rook.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}

TEST_F(DerivedFromBoard, TestWhiteRookEmptyAvailableMoves1) {
    auto moves = board[0][0].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestBlackRookEmptyAvailableMoves1) {
    auto moves = board[0][7].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestWhiteRookEmptyAvailableMoves2) {
    auto moves = board[0][0].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestBlackRookEmptyAvailableMoves2) {
    auto moves = board[7][0].get_available_moves(board);
    ASSERT_EQ(std::distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestWhiteRookAvailableMoves1) {
    handle_cell_click(&board[1][0]);
    handle_cell_click(&board[2][0]);
    auto moves = board[0][0].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[1][0]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 1);
}

TEST_F(DerivedFromBoard, TestWhiteRookAvailableMoves2) {
    handle_cell_click(&board[1][0]);
    handle_cell_click(&board[3][0]);
    auto moves = board[0][0].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[1][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][0]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
}

TEST_F(DerivedFromBoard, TestWhiteRookAvailableMoves3) {
    handle_cell_click(&board[1][0]);
    handle_cell_click(&board[3][0]);
    handle_cell_click(&board[0][0]);
    handle_cell_click(&board[2][0]);
    auto moves = board[2][0].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[0][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[1][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(),&board[2][7]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 9);
}

TEST_F(DerivedFromBoard, TestWhiteRookAvailableMoves4) {
    handle_cell_click(&board[1][0]);
    handle_cell_click(&board[3][0]);
    handle_cell_click(&board[0][0]);
    handle_cell_click(&board[2][0]);
    handle_cell_click(&board[2][0]);
    handle_cell_click(&board[2][7]);
    auto moves = board[2][7].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][7]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 10);
}

TEST_F(DerivedFromBoard, TestBlackRookAvailableMoves1) {
    handle_cell_click(&board[6][7]);
    handle_cell_click(&board[5][7]);
    auto moves = board[7][7].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][7]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 1);
}

TEST_F(DerivedFromBoard, TestBlackRookAvailableMoves2) {
    handle_cell_click(&board[6][7]);
    handle_cell_click(&board[4][7]);
    auto moves = board[7][7].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][7]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 2);
}

TEST_F(DerivedFromBoard, TestBlackRookAvailableMoves3) {
    handle_cell_click(&board[6][7]);
    handle_cell_click(&board[4][7]);
    handle_cell_click(&board[7][7]);
    handle_cell_click(&board[5][7]);
    auto moves = board[5][7].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[6][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[7][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][0]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 9);
}

TEST_F(DerivedFromBoard, TestBlackRookAvailableMoves4) {
    handle_cell_click(&board[6][7]);
    handle_cell_click(&board[4][7]);
    handle_cell_click(&board[7][7]);
    handle_cell_click(&board[5][7]);
    handle_cell_click(&board[5][7]);
    handle_cell_click(&board[5][0]);
    auto moves = board[5][0].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][7]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][6]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][5]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][3]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][1]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][0]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][0]), moves.end());
    EXPECT_EQ(std::distance(moves.begin(), moves.end()), 10);
}
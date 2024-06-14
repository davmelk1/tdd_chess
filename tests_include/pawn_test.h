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
    handle_cell_click(&board[1][4]);
    auto moves = board[1][4].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[2][4]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][4]), moves.end());
    EXPECT_EQ(distance(moves.begin(), moves.end()), 2);
}

TEST_F(DerivedFromBoard, TestAvailableMovesForBlackPawn) {
    handle_cell_click(&board[6][2]);
    auto moves = board[6][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[5][2]), moves.end());
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][2]), moves.end());
    EXPECT_EQ(distance(moves.begin(), moves.end()), 2);
}

TEST_F(DerivedFromBoard, TestAvailableMovesForBlackPawnOnSecondStep1) {
    handle_cell_click(&board[6][2]);
    handle_cell_click(&board[5][2]);
    handle_cell_click(&board[5][2]);
    auto moves = board[5][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][2]), moves.end());
    EXPECT_EQ(distance(moves.begin(), moves.end()), 1);
}


TEST_F(DerivedFromBoard, TestAvailableMovesForWhitePawnOnSecondStep1) {
    handle_cell_click(&board[1][1]);
    handle_cell_click(&board[2][1]);
    handle_cell_click(&board[2][1]);
    auto moves = board[2][1].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][1]), moves.end());
    EXPECT_EQ(distance(moves.begin(), moves.end()), 1);
}

TEST_F(DerivedFromBoard, TestAvailableMovesForBlackPawnOnSecondStep2) {
    handle_cell_click(&board[6][2]);
    handle_cell_click(&board[4][2]);
    handle_cell_click(&board[4][2]);
    auto moves = board[4][2].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[3][2]), moves.end());
    EXPECT_EQ(distance(moves.begin(), moves.end()), 1);
}


TEST_F(DerivedFromBoard, TestAvailableMovesForWhitePawnOnSecondStep2) {
    handle_cell_click(&board[1][1]);
    handle_cell_click(&board[3][1]);
    handle_cell_click(&board[3][1]);
    auto moves = board[3][1].get_available_moves(board);
    EXPECT_NE(std::find(moves.begin(), moves.end(), &board[4][1]), moves.end());
    EXPECT_EQ(distance(moves.begin(), moves.end()), 1);
}

TEST_F(DerivedFromBoard, TestAvailableMovesForBlackPawnThatHasNoMove) {
    board[2][3].add_figure(new Pawn(Black));
    auto moves = board[2][3].get_available_moves(board);
    EXPECT_EQ(distance(moves.begin(), moves.end()), 0);
}

TEST_F(DerivedFromBoard, TestAvailableMovesForWhitePawnThatHasNoMove) {
    board[5][3].add_figure(new Pawn(White));
    auto moves = board[5][3].get_available_moves(board);
    EXPECT_EQ(distance(moves.begin(), moves.end()), 0);
}
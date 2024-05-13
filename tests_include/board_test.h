#pragma once

#include "board.h"

class BoardTest : public ::testing::Test{
public:
	Board board;
};

class DerivedFromBoard : public ::testing::Test, public Board {

};

TEST(TestCReatingBoard, TestDefaultBoardCreation) {
	Board board;
}

TEST_F(BoardTest, TestBoardSize) {
	ASSERT_EQ(board.get_size(), constants::BOARD_SIZE);
}

TEST_F(BoardTest, TestSettingPosition) {
	board.set_position(15, 23);
	ASSERT_EQ(board.get_position(), sf::Vector2f(15.f, 23.f));
}

TEST_F(DerivedFromBoard, TestSettingPositionWithVector) {
	set_position({15, 23});
	ASSERT_EQ(get_position(), sf::Vector2f(15.f, 23.f));
}

TEST_F(DerivedFromBoard, TestTheOrderOfCellsOnBoard) {
    for (int i = 0; i < get_size(); ++i) {
        for (int j = 0; j < get_size(); ++j) {
            EXPECT_EQ(board[i][j].get_color(), (i + j) % 2 ? White : Black);
        }
    }
}

TEST_F(DerivedFromBoard, TestCellSizes) {
    for (int i = 0; i < get_size(); ++i) {
        for (int j = 0; j < get_size(); ++j) {
            EXPECT_EQ(board[i][j].get_size(), sf::Vector2f(constants::CELL_WIDTH, constants::CELL_WIDTH));
        }
    }
}

TEST_F(DerivedFromBoard, TestCellPositions) {
    auto padding = Board::calculate_board_position_from_constants();
    for (int i = 0; i < get_size(); ++i) {
        for (int j = 0; j < get_size(); ++j) {
            EXPECT_EQ(board[i][j].get_position(), sf::Vector2f(padding.x + constants::CELL_WIDTH * j,
                                                               padding.y + constants::CELL_WIDTH * i));
        }
    }
}

TEST(TestBoardStaticMethod, TestBoardPaddingCalculations) {
    auto padding = (constants::WINDOW_WIDTH - constants::BOARD_SIZE * constants::CELL_WIDTH) / 2;
    ASSERT_EQ(Board::calculate_board_position_from_constants(), sf::Vector2f(padding, padding));
}

TEST_F(BoardTest, TestDefaultBoardIsInTheRightPlace) {
    ASSERT_EQ(board.get_position(), Board::calculate_board_position_from_constants());
}


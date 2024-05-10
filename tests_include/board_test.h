#pragma once

#include "board.h"

class BoardTest : public ::testing::Test{
public:
	Board board;
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


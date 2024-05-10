#pragma once

#include <gtest/gtest.h>

#include "cell.h"
#include "constants.h"

class CellTest : public ::testing::Test{
public:
	Cell cell;
};

TEST(TestCreatingCells, DefaultCellCreation) {
	Cell cell;
}

TEST(TestCreatingCells, TestCreatingBlackCell) {
	Cell cell{Black};
	ASSERT_EQ(cell.get_color(), Black);
}

TEST(TestCreatingCells, TestCreatingWhiteCell) {
	Cell cell{White};
	ASSERT_EQ(cell.get_color(), White);
}

TEST(TestCreatingCells, TestDefaultCellIsWhite) {
	Cell cell;
	ASSERT_EQ(cell.get_color(), White);
}

TEST_F(CellTest, TestSettingPosition) {
	cell.set_position(15, 23);
	ASSERT_EQ(cell.get_position(), sf::Vector2f(15.f, 23.f));
}

TEST_F(CellTest, TestSettingSize) {
	sf::Vector2f size{constants::CELL_WIDTH, constants::CELL_WIDTH};
	cell.set_size(size);
	ASSERT_EQ(cell.get_size(), size);
}


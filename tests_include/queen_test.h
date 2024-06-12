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
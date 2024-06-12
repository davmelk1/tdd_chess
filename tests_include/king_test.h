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
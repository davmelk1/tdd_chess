#pragma once

#include <gtest/gtest.h>

#include "bishop.h"

class BishopTest : public ::testing::Test{
public:
    Bishop bishop;
};


TEST_F(BishopTest, TestFigureSetPosition) {
    bishop.set_position_from_center_coordinates(32, 54);
    auto size = bishop.get_size();
    ASSERT_EQ(bishop.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}
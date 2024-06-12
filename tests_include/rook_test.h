#pragma once

#include <gtest/gtest.h>

#include "rook.h"

class RookTest : public ::testing::Test{
public:
    Rook rook;
};


TEST_F(RookTest, TestFigureSetPosition) {
    rook.set_position_from_center_coordinates(32, 54);
    auto size = rook.get_size();
    ASSERT_EQ(rook.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}
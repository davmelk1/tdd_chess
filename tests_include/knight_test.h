#pragma once

#include <gtest/gtest.h>

#include "knight.h"

class KnightTest : public ::testing::Test{
public:
    Knight knight;
};


TEST_F(KnightTest, TestFigureSetPosition) {
    knight.set_position_from_center_coordinates(32, 54);
    auto size = knight.get_size();
    ASSERT_EQ(knight.get_position(), sf::Vector2f(32 - size.x / 2, 54 - size.y / 2));
}
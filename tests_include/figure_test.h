#pragma once

#include "figure.h"

class DerivedFromFigure : public ::testing::Test, public Figure{
};

TEST_F(DerivedFromFigure, TestFigureSetPosition) {
    set_position_from_center_coordinates(32, 54);
    auto size = get_size();
    ASSERT_EQ(get_position(), sf::Vector2f(32 - size.x / 2,54 - size.y / 2));
}


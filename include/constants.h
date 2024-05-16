#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace constants{
	constexpr int BOARD_SIZE{8};
    constexpr float WINDOW_WIDTH{800};
	constexpr float CELL_WIDTH{WINDOW_WIDTH * 8 / 10 / BOARD_SIZE};
    const sf::Color BACKGROUND_COLOR{237, 198, 138};
    const sf::Color WHITE_CELL_COLOR{237, 180, 92};
    const sf::Color BLACK_CELL_COLOR{140, 96, 29};
    inline const sf::Font font = []() {
        sf::Font font;
        font.loadFromFile("../arnamu.ttf");
        return font;
    }();
}

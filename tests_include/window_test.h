#pragma once

#include <gtest/gtest.h>

#include "board.h"

TEST(TestWindow, TestBoardDrawing) {
    sf::RenderWindow window{{800, 800}, "widnow"};
    Board board;
    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::KeyPressed) {
                ASSERT_NE(ev.key.code, sf::Keyboard::Escape);
                window.close();
            }
        }
        window.clear(constants::BACKGROUND_COLOR);
        board.draw(window);
        window.display();
    }
}
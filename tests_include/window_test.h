#pragma once

#include <gtest/gtest.h>

#include "window.h"

class DerivedFromGameWindow : public ::testing::Test, public GameWindow{};

TEST_F(DerivedFromGameWindow, TestBoardDrawing) {
    while (window.isOpen()) {
        sf::Event ev{};
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::KeyPressed) {
                ASSERT_NE(ev.key.code, sf::Keyboard::Escape);
                window.close();
            }
        }
        window.clear(constants::BACKGROUND_COLOR);
        board.draw(window);
        draw_labels();
        window.display();
    }
}

TEST_F(DerivedFromGameWindow, TestCheckingCloseEvent) {
    sf::Event close_event{sf::Event::Closed};
    EXPECT_EQ(close_event_appeared(close_event), true);
    sf::Event escape_event{sf::Event::KeyPressed, sf::Keyboard::Escape};
    EXPECT_EQ(close_event_appeared(escape_event), true);
}
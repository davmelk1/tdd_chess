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
			switch (ev.type) {
				case sf::Event::MouseMoved:
					board.handle_mouse_hovering({ev.mouseMove.x, ev.mouseMove.y});
					break;
				case sf::Event::MouseButtonPressed:
					board.handle_mouse_press(ev.mouseButton);
					break;
				default:
					break;
				
			}
		}
		draw_and_display();
    }
}

TEST_F(DerivedFromGameWindow, TestCheckingCloseEvent) {
    sf::Event close_event{sf::Event::Closed};
    EXPECT_EQ(close_event_appeared(close_event), true);
    sf::Event escape_event{sf::Event::KeyPressed, sf::Keyboard::Escape};
    EXPECT_EQ(close_event_appeared(escape_event), true);
}

TEST_F(DerivedFromGameWindow, TestCheckingWindowClosed) {
    sf::Event close_event{sf::Event::Closed};
    EXPECT_EQ(is_cross_pressed(close_event), true);
	sf::Event escape_event{sf::Event::KeyPressed, sf::Keyboard::Escape};
	EXPECT_EQ(is_cross_pressed(escape_event), false);
}

TEST_F(DerivedFromGameWindow, TestCheckingEscapePressed) {
    sf::Event close_event{sf::Event::Closed};
    EXPECT_EQ(is_escape_pressed(close_event), false);
	sf::Event escape_event{sf::Event::KeyPressed, sf::Keyboard::Escape};
	EXPECT_EQ(is_escape_pressed(escape_event), true);
}


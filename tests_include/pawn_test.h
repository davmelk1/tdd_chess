#pragma once

#include <gtest/gtest.h>

#include "pawn.h"

class PawnTest : public ::testing::Test{
public:
    Pawn pawn;
};

//TEST_F(PawnTest, TestWhitePawnRect) {
//    sf::RenderWindow window{{100, 100}, "White pawn"};
//    pawn.draw(window);
//    while (window.isOpen()) {
//        sf::Event ev{};
//        while (window.pollEvent(ev)) {
//            if (ev.type == sf::Event::KeyPressed) {
//                ASSERT_NE(ev.key.code, sf::Keyboard::Escape);
//                window.close();
//            }
//        }
//
//        window.clear(constants::BACKGROUND_COLOR);
//        pawn.draw(window);
//        window.display();
//    }
//}
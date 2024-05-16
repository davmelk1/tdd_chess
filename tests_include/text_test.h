#pragma once

#include "text.h"

class TextTest : public ::testing::Test{
public:
    Text text;
};

TEST_F(TextTest, TestSettingText) {
    text.set_text("hello");
    ASSERT_EQ(text.get_text(), "hello");
}

TEST_F(TextTest, TestSettingPosition) {
    text.set_position({3, 76});
    EXPECT_EQ(text.get_position(), sf::Vector2f(3, 76));
    text.set_position(65, 43);
    EXPECT_EQ(text.get_position(), sf::Vector2f(65, 43));
}

TEST_F(TextTest, TestGettingSize) {
    text.set_text("asdfg");
    sf::Text t;
    t.setString("asdfg");
    auto font = text.get_font();
    t.setFont(font);
    ASSERT_EQ(text.get_size(), sf::Vector2f(t.getLocalBounds().width, t.getLocalBounds().height));
}

//TEST_F(TextTest, TestDrawingText) {
//    text.set_text("asd");
//    text.set_position(5, 10);
//    sf::RenderWindow window{{150,150}, "asd text"};
//    while (window.isOpen()) {
//        sf::Event ev{};
//        while (window.pollEvent(ev)) {
//            if (ev.type == sf::Event::KeyPressed) {
//                ASSERT_NE(ev.key.code, sf::Keyboard::Escape);
//                window.close();
//            }
//        }
//        window.clear(constants::BACKGROUND_COLOR);
//        text.draw(window);
//        window.display();
//    }
//}
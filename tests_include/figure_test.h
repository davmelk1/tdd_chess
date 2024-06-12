#pragma once

#include "figure.h"

class DerivedFromFigure : public ::testing::Test, public Figure{
};


//TEST(TestFigureRects, WhitePawn) {
//    Pawn knight;
//    sf::RenderWindow window{{300, 100}, "White knight"};
//    knight.draw(window);
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
//        knight.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, BlackPawn) {
//    Pawn knight{Black};
//    sf::RenderWindow window{{300, 100}, "Black knight"};
//    knight.draw(window);
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
//        knight.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, WhiteKnight) {
//    Knight knight;
//    sf::RenderWindow window{{300, 100}, "White knight"};
//    knight.draw(window);
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
//        knight.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, BlackKnight) {
//    Knight knight{Black};
//    sf::RenderWindow window{{300, 100}, "Black knight"};
//    knight.draw(window);
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
//        knight.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, WhiteRook) {
//    Rook rook;
//    sf::RenderWindow window{{300, 100}, "White rook"};
//    rook.draw(window);
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
//        rook.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, BlackRook) {
//    Rook rook{Black};
//    sf::RenderWindow window{{300, 100}, "Black rook"};
//    rook.draw(window);
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
//        rook.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, WhiteBishop) {
//    Bishop bishop;
//    sf::RenderWindow window{{300, 100}, "White bishop"};
//    bishop.draw(window);
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
//        bishop.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, BlackBishop) {
//    Bishop bishop{Black};
//    sf::RenderWindow window{{300, 100}, "Black bishop"};
//    bishop.draw(window);
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
//        bishop.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, WhiteKing) {
//    King king;
//    sf::RenderWindow window{{300, 100}, "White king"};
//    king.draw(window);
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
//        king.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, BlackKing) {
//    King king{Black};
//    sf::RenderWindow window{{300, 100}, "Black king"};
//    king.draw(window);
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
//        king.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, WhiteQueen) {
//    Queen queen;
//    sf::RenderWindow window{{300, 100}, "White queen"};
//    queen.draw(window);
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
//        queen.draw(window);
//        window.display();
//    }
//}
//
//TEST(TestFigureRects, BlackQueen) {
//    Queen queen{Black};
//    sf::RenderWindow window{{300, 100}, "Black queen"};
//    queen.draw(window);
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
//        queen.draw(window);
//        window.display();
//    }
//}
//)
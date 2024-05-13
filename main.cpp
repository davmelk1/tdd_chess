#include <iostream>

#include "board.h"

int main() {
    sf::RenderWindow window{{static_cast<unsigned int>(constants::WINDOW_WIDTH),
                             static_cast<unsigned int>(constants::WINDOW_WIDTH)}, "TDD Chess"};
    Board board;
    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(constants::BACKGROUND_COLOR);
        board.draw(window);
        window.display();
    }
    return 0;
}

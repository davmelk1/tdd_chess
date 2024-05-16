#include "window.h"

GameWindow::GameWindow(unsigned int window_width, unsigned int window_height) : window({window_width, window_height},
                                                                                       "TDD Chess") {
}

void GameWindow::run() {
    while (window.isOpen()) {
        handle_events();
        draw_and_display();
    }
}

void GameWindow::handle_events() {
    sf::Event ev{};
    while (window.pollEvent(ev)) {
        if (close_event_appeared(ev)) {
            handle_close_event();
            continue;
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
}

void GameWindow::handle_close_event() {
    window.close();
}

bool GameWindow::close_event_appeared(const sf::Event& ev) {
    return is_cross_pressed(ev) || is_escape_pressed(ev);
}

bool GameWindow::is_cross_pressed(const sf::Event& ev) {
    return ev.type == sf::Event::Closed;
}

bool GameWindow::is_escape_pressed(const sf::Event& ev) {
    return ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape;
}

void GameWindow::draw_and_display() {
    draw_widgets();
    window.display();
}

void GameWindow::draw_widgets() {
    window.clear(constants::BACKGROUND_COLOR);
    board.draw(window);
	board.draw_labels(window);
}


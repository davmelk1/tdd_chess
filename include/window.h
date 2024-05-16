#pragma once

#include "board.h"

class GameWindow{
public:
    GameWindow(unsigned int window_width = static_cast<unsigned int>(constants::WINDOW_WIDTH),
                             unsigned int window_height = static_cast<unsigned int>(constants::WINDOW_WIDTH));
    
    void run();

protected:
    sf::RenderWindow window;
    Board board;
    
    void handle_close_event();
    
    static bool close_event_appeared(const sf::Event& ev);
    
    static bool is_cross_pressed(const sf::Event& ev);
    
    static bool is_escape_pressed(const sf::Event& ev);
    
    void draw_and_display();
    
    void draw_widgets();
	
	void handle_events();
};

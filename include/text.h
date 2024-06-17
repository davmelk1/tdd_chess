#pragma once

#include "constants.h"

class Text{
public:
    Text();
    
    void set_text(const std::string& string);
    
    [[nodiscard]] std::string get_text() const;
    
    [[maybe_unused]] void set_font(const sf::Font& new_font);
    
    sf::Font get_font() const;
    
    void set_position(const sf::Vector2f& vec);
    
    void set_position(float x, float y);
    
    sf::Vector2f get_position() const;
    
    sf::Vector2f get_size() const;
    
    void draw(sf::RenderWindow& window) const;
    
    void set_center_position(float x, float y);

private:
    sf::Font font{constants::font};
    sf::Text text;
    
};
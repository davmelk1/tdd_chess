#include "text.h"

void Text::set_text(const std::string& string) {
    text.setString(string);
}

std::string Text::get_text() const {
    return text.getString();
}

void Text::set_font(const sf::Font& new_font) {
    font = new_font;
    text.setFont(new_font);
}

sf::Font Text::get_font() const {
    return font;
}

void Text::set_position(const sf::Vector2f& vec) {
    text.setPosition(vec);
}

void Text::set_position(float x, float y) {
    set_position({x,y});
}

sf::Vector2f Text::get_position() const {
    return text.getPosition();
}

void Text::draw(sf::RenderWindow& window) const {
    window.draw(text);
}

Text::Text() {
    text.setFont(font);
}

sf::Vector2f Text::get_size() const {
    return {text.getLocalBounds().width, text.getLocalBounds().height};
}

void Text::set_center_position(float x, float y) {
    auto bounds = text.getLocalBounds();
    text.setPosition(x - bounds.width / 2, y - bounds.height);
}

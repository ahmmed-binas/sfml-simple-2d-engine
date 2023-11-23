#include "DynamicShapeButton.hpp"
#include <SFML/Graphics.hpp>

DynamicShapeButton::DynamicShapeButton(const std::string& label, const sf::Vector2f& position, sf::RenderWindow& window)
    : label(label), position(position), window(&window) {}

void DynamicShapeButton::draw() const {
    sf::RectangleShape button(sf::Vector2f(150, 50));
    button.setPosition(position);
    window->draw(button);

    sf::Text buttonText;
    buttonText.setString(label);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(position.x + 25, position.y + 15);

    window->draw(buttonText);
}

bool DynamicShapeButton::isClicked(sf::Vector2f mousePosition) const {
    sf::FloatRect buttonRect(position.x, position.y, 150, 50);
    return buttonRect.contains(mousePosition);
}

std::string DynamicShapeButton::getLabel() const {
    return label;
}

sf::RenderWindow* DynamicShapeButton::getWindow() const {
    return window;
}

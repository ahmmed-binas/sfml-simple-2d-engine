#ifndef DYNAMIC_SHAPE_BUTTON_HPP
#define DYNAMIC_SHAPE_BUTTON_HPP

#include <SFML/Graphics.hpp>

class DynamicShapeButton {
public:
    DynamicShapeButton(const std::string& label, const sf::Vector2f& position, sf::RenderWindow& window);

    void draw() const;
    bool isClicked(sf::Vector2f mousePosition) const;
    std::string getLabel() const;
    sf::RenderWindow* getWindow() const;

private:
    std::string label;
    sf::Vector2f position;
    sf::RenderWindow* window;
};

#endif

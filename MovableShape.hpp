#pragma once

#include <SFML/Graphics.hpp>

class MovableShape {
public:
    MovableShape(sf::Shape* shape);
    void draw(sf::RenderWindow& window) const;
    void move(sf::Vector2f offset);
    void setSelected(bool selected);
    bool contains(sf::Vector2f point) const;
    void startDragging(sf::Vector2f initialMousePosition);
    void stopDragging();
    void updateDragging(sf::Vector2f currentMousePosition);

private:
    sf::Shape* shape;
    bool isSelected;
    bool isBeingDragged;
    sf::Vector2f dragOffset;
};

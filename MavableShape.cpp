#include "MovableShape.hpp"

MovableShape::MovableShape(sf::Shape* shape) : shape(shape), isSelected(false), isBeingDragged(false) {}

void MovableShape::draw(sf::RenderWindow& window) const {
    window.draw(*shape);
}

void MovableShape::move(sf::Vector2f offset) {
    if (isBeingDragged) {
        shape->move(offset);
    }
}

void MovableShape::setSelected(bool selected) {
    isSelected = selected;
}

bool MovableShape::contains(sf::Vector2f point) const {
    return shape->getGlobalBounds().contains(point);
}

void MovableShape::startDragging(sf::Vector2f initialMousePosition) {
    if (isSelected) {
        isBeingDragged = true;
        dragOffset = shape->getPosition() - initialMousePosition;
    }
}

void MovableShape::stopDragging() {
    isBeingDragged = false;
}

void MovableShape::updateDragging(sf::Vector2f currentMousePosition) {
    if (isBeingDragged) {
        shape->setPosition(currentMousePosition + dragOffset);
    }
}

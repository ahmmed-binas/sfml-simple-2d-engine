#pragma once

#include <SFML/Graphics.hpp>

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window);

    // Add other rendering methods as needed
    void drawLineIncremental(float startX, float startY, float endX, float endY, sf::Color color);

private:
    sf::RenderWindow& window;
};

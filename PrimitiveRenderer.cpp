#include "PrimitiveRenderer.hpp"

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {}

void PrimitiveRenderer::drawLineIncremental(float startX, float startY, float endX, float endY, sf::Color color) {
    // Your implementation of incremental line drawing here using sf::VertexArray or other suitable methods
    // For simplicity, I'm just using the basic drawLine method in this example
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(startX, startY), color),
        sf::Vertex(sf::Vector2f(endX, endY), color)
    };

    window.draw(line, 2, sf::Lines);
}

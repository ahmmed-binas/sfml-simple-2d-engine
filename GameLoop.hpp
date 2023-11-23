#pragma once

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.hpp" // Include the PrimitiveRenderer header

class GameLoop {
public:
    GameLoop(sf::RenderWindow& window, unsigned int width, unsigned int height, unsigned int bitsPerPixel);

    void run();

private:
    sf::RenderWindow& window;
    unsigned int width, height, bitsPerPixel;
    bool useFirstBuffer;
    sf::RenderTexture frameBuffer1, frameBuffer2;
    PrimitiveRenderer renderer; // Add a member variable for PrimitiveRenderer

    // Add other game-related variables and methods as needed
    std::vector<DynamicShapeButton> buttons;
    std::vector<MovableShape> shapes;

    void processInput();
    void update();
    void render();
};

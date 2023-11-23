#include "GameLoop.hpp"

GameLoop::GameLoop(sf::RenderWindow& window, unsigned int width, unsigned int height, unsigned int bitsPerPixel)
    : window(window), width(width), height(height), bitsPerPixel(bitsPerPixel), useFirstBuffer(true), renderer(window) {
    // Initialize the frame buffers
    frameBuffer1.create(width, height);
    frameBuffer2.create(width, height);
}

void GameLoop::run() {
    while (window.isOpen()) {
        processInput();
        update();
        render();
    }
}

void GameLoop::processInput() {
    // Handle input events
    sf::Event event;
    while (window.pollEvent(event)) {
        // Process input events
        // ...
    }
}

void GameLoop::update() {
    // Update game logic
    // ...
}

void GameLoop::render() {
    // Choose the active frame buffer
    sf::RenderTexture& activeBuffer = (useFirstBuffer) ? frameBuffer1 : frameBuffer2;
    sf::RenderTexture& inactiveBuffer = (useFirstBuffer) ? frameBuffer2 : frameBuffer1;

    // Clear the active frame buffer
    activeBuffer.clear();

    // Render objects to the active frame buffer using the PrimitiveRenderer
    renderer.drawLineIncremental(100, 100, 400, 400, sf::Color::Blue);

    // Render other objects (buttons, shapes, etc.)
    for (auto& button : buttons) {
        button.draw(activeBuffer);
    }

    for (auto& movableShape : shapes) {
        movableShape.draw(activeBuffer);
        movableShape.updateDragging(sf::Vector2f(sf::Mouse::getPosition(window)));
    }

    // Display the active frame buffer
    activeBuffer.display();

    // Draw the active frame buffer to the window
    sf::Sprite sprite(activeBuffer.getTexture());
    window.draw(sprite);

    // Display the rendered frame
    window.display();

    // Swap the active and inactive frame buffers
    useFirstBuffer = !useFirstBuffer;
}

#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"

int main() {
    unsigned int width = 800;
    unsigned int height = 600;
    unsigned int bitsPerPixel = 32;

    sf::RenderWindow window(sf::VideoMode(width, height, bitsPerPixel), "SFML Window");

    GameLoop gameLoop(window, width, height, bitsPerPixel);
    gameLoop.run();

    return 0;
}

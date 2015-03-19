#include "block.hpp"
#include "game.hpp"

const int Block::DIMENSION = Game::SCREEN_WIDTH / 10;

Block::Block(int x, int y) {
    rect.setSize(sf::Vector2f(DIMENSION, DIMENSION));
    rect.setPosition(DIMENSION * 5 - x * DIMENSION, y * DIMENSION);
    rect.setFillColor(sf::Color::Red);
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color::Black);
}

void Block::render(sf::RenderWindow &window) {
    window.draw(rect);
}

void Block::moveLeft() {
    rect.move(-DIMENSION, 0);
}

void Block::moveRight() {
    rect.move(DIMENSION, 0);
}

void Block::moveDown() {
    rect.move(0, DIMENSION);
}

bool Block::canMoveLeft() {
    return rect.getPosition().x - DIMENSION >= 0;
}

bool Block::canMoveRight() {
    return rect.getPosition().x + DIMENSION * 2 <= Game::SCREEN_WIDTH;
}

bool Block::canMoveDown() {
    return rect.getPosition().y + DIMENSION * 2 <= Game::SCREEN_HEIGHT;
}

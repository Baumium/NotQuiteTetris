#include "block.h"
#include "game.h"
#include <cstdio>

const int Block::DIMENSION = Game::SCREEN_WIDTH / 10;

Block::Block(int x, int y) {
    rect = new SDL_Rect{(DIMENSION * 5) - (x * DIMENSION), y * DIMENSION, DIMENSION, DIMENSION};
}

void Block::render(SDL_Renderer *renderer) {
    SDL_RenderFillRect(renderer, rect);
}

void Block::moveLeft() {
    rect->x = rect->x - DIMENSION;
}

void Block::moveRight() {
    rect->x = rect->x + DIMENSION;
}

void Block::moveDown() {
    rect->y = rect->y + DIMENSION;
}

bool Block::canMoveLeft() {
    return rect->x - DIMENSION >= 0;
}

bool Block::canMoveRight() {
    return rect->x + rect->w + DIMENSION <= Game::SCREEN_WIDTH;
}

bool Block::canMoveDown() {
    return rect->y + rect->h + DIMENSION <= Game::SCREEN_HEIGHT;
}

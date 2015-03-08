#include "block.h"
#include "game.h"
#include <cstdio>

const int Block::DIMENSION = Game::SCREEN_HEIGHT / 25;

Block::Block(int x, int y) {
    rect = new SDL_Rect{DIMENSION * 6 + x * DIMENSION, y * DIMENSION, DIMENSION, DIMENSION};
}

void Block::render(SDL_Renderer *renderer) {
    SDL_RenderFillRect(renderer, rect);
}

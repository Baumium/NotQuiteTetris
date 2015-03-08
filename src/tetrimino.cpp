#include "tetrimino.h"

Tetrimino::Tetrimino(Shape shape) {
    switch(shape) {
        case T:
            blocks[0] = Block(1, 0);
            blocks[1] = Block(1, 1);
            blocks[2] = Block(0, 1);
            blocks[3] = Block(1, 2);
            break;
        case J:
            blocks[0] = Block(0, 0);
            blocks[1] = Block(1, 0);
            blocks[2] = Block(0, 1);
            blocks[3] = Block(0, 2);
            break;
        case Z:
            blocks[0] = Block(1, 0);
            blocks[1] = Block(1, 1);
            blocks[2] = Block(0, 1);
            blocks[3] = Block(0, 2);
            break;
        case O:
            blocks[0] = Block(0, 0);
            blocks[1] = Block(1, 0);
            blocks[2] = Block(0, 1);
            blocks[3] = Block(1, 1);
            break;
        case L:
            blocks[0] = Block(0, 0);
            blocks[1] = Block(1, 0);
            blocks[2] = Block(1, 1);
            blocks[3] = Block(1, 2);
            break;
        case S:
            blocks[0] = Block(0, 0);
            blocks[1] = Block(0, 1);
            blocks[2] = Block(1, 1);
            blocks[3] = Block(1, 2);
            break;
        case I:
            blocks[0] = Block(0, 0);
            blocks[1] = Block(1, 0);
            blocks[2] = Block(2, 0);
            blocks[3] = Block(3, 0);
            break;
        default:
            blocks[0] = Block(0, 0);
            blocks[1] = Block(0, 6);
            blocks[2] = Block(0, 2);
            blocks[3] = Block(0, 3);
            break;
    }
}

void Tetrimino::render(SDL_Renderer *renderer) {
    for(int i = 0; i < 4; i++) {
        blocks[i].render(renderer);
    }
}

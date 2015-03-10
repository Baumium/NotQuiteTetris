#include "tetrimino.h"

Tetrimino::Tetrimino(Shape shape) {
    switch(shape) {
        case T:
            rotations = 4;
            blocks[0][0] = Block(1, 0);
            blocks[0][1] = Block(1, 1);
            blocks[0][2] = Block(0, 1);
            blocks[0][3] = Block(1, 2);
            break;
        case J:
            rotations = 2;
            blocks[0][0] = Block(0, 0);
            blocks[0][1] = Block(1, 0);
            blocks[0][2] = Block(0, 1);
            blocks[0][3] = Block(0, 2);
            break;
        case Z:
            rotations = 2;
            blocks[0][0] = Block(1, 0);
            blocks[0][1] = Block(1, 1);
            blocks[0][2] = Block(0, 1);
            blocks[0][3] = Block(0, 2);
            break;
        case O:
            rotations = 1;
            blocks[0][0] = Block(0, 0);
            blocks[0][1] = Block(1, 0);
            blocks[0][2] = Block(0, 1);
            blocks[0][3] = Block(1, 1);
            break;
        case L:
            rotations = 2;
            blocks[0][0] = Block(0, 0);
            blocks[0][1] = Block(1, 0);
            blocks[0][2] = Block(1, 1);
            blocks[0][3] = Block(1, 2);
            break;
        case S:
            rotations = 2;
            blocks[0][0] = Block(0, 0);
            blocks[0][1] = Block(0, 1);
            blocks[0][2] = Block(1, 1);
            blocks[0][3] = Block(1, 2);
            break;
        case I:
            rotations = 2;
            blocks[0][0] = Block(0, 0);
            blocks[0][1] = Block(1, 0);
            blocks[0][2] = Block(2, 0);
            blocks[0][3] = Block(3, 0);
            break;
        default:
            rotations = 1;
            blocks[0][0] = Block(0, 0);
            blocks[0][1] = Block(0, 6);
            blocks[0][2] = Block(0, 2);
            blocks[0][3] = Block(0, 3);
            break;
    }

    lastDropped = 0;
}

const int Tetrimino::DROP_DELAY = 500;

void Tetrimino::render(SDL_Renderer *renderer) {
    for(int i = 0; i < 4; i++) {
        blocks[0][i].render(renderer);
    }
}

void Tetrimino::moveLeft() {
    bool canMove = true;
    for(int i = 0; i < 4; i++) {
        if(!blocks[0][i].canMoveLeft()) {
            canMove = false;
        }
    }
    if(canMove) {
        for(int i = 0; i < 4; i++) {
            blocks[0][i].moveLeft();
        }
    }
}

void Tetrimino::moveRight() {
    bool canMove = true;
    for(int i = 0; i < 4; i++) {
        if(!blocks[0][i].canMoveRight()) {
            canMove = false;
        }
    }
    if(canMove) {
        for(int i = 0; i < 4; i++) {
            blocks[0][i].moveRight();
        }
    }
}

void Tetrimino::update() {
    //Apply a delay for dropping piece
    if(lastDropped + DROP_DELAY < SDL_GetTicks()) {
        lastDropped = SDL_GetTicks();
        bool canMove = true;
        for(int i = 0; i < 4; i++) {
            if(!blocks[0][i].canMoveDown()) {
                canMove = false;
            }
        }
        if(canMove) {
            for(int i = 0; i < 4; i++) {
                blocks[0][i].moveDown();
            }
        }
    }
}

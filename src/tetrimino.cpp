#include "tetrimino.hpp"
#include "block.hpp"
#include <cstdio>

Tetrimino::Tetrimino(Shape shape) : lastDropped(0), dropDelay(500), hitBottom(false) {
    switch(shape) {
        case T:
            rotations = 4;
            blocks[0][0] = new Block(1, 0);
            blocks[0][1] = new Block(1, 1);
            blocks[0][2] = new Block(0, 1);
            blocks[0][3] = new Block(1, 2);
            break;
        case J:
            rotations = 2;
            blocks[0][0] = new Block(0, 0);
            blocks[0][1] = new Block(1, 0);
            blocks[0][2] = new Block(0, 1);
            blocks[0][3] = new Block(0, 2);
            break;
        case Z:
            rotations = 2;
            blocks[0][0] = new Block(1, 0);
            blocks[0][1] = new Block(1, 1);
            blocks[0][2] = new Block(0, 1);
            blocks[0][3] = new Block(0, 2);
            break;
        case O:
            rotations = 1;
            blocks[0][0] = new Block(0, 0);
            blocks[0][1] = new Block(1, 0);
            blocks[0][2] = new Block(0, 1);
            blocks[0][3] = new Block(1, 1);
            break;
        case L:
            rotations = 2;
            blocks[0][0] = new Block(0, 0);
            blocks[0][1] = new Block(1, 0);
            blocks[0][2] = new Block(1, 1);
            blocks[0][3] = new Block(1, 2);
            break;
        case S:
            rotations = 2;
            blocks[0][0] = new Block(0, 0);
            blocks[0][1] = new Block(0, 1);
            blocks[0][2] = new Block(1, 1);
            blocks[0][3] = new Block(1, 2);
            break;
        case I:
            rotations = 2;
            blocks[0][0] = new Block(0, 0);
            blocks[0][1] = new Block(1, 0);
            blocks[0][2] = new Block(2, 0);
            blocks[0][3] = new Block(3, 0);
            break;
        default:
            rotations = 1;
            blocks[0][0] = new Block(0, 0);
            blocks[0][1] = new Block(0, 6);
            blocks[0][2] = new Block(0, 2);
            blocks[0][3] = new Block(0, 3);
            break;
    }
}

void Tetrimino::render(sf::RenderWindow &window) {
    for(int i = 0; i < 4; i++) {
        blocks[0][i]->render(window);
    }
}

void Tetrimino::moveLeft() {
    bool canMove = true;
    for(int i = 0; i < 4; i++) {
        if(!blocks[0][i]->canMoveLeft()) {
            canMove = false;
        }
    }
    if(canMove) {
        for(int i = 0; i < 4; i++) {
            blocks[0][i]->moveLeft();
        }
    }
}

void Tetrimino::moveRight() {
    bool canMove = true;
    for(int i = 0; i < 4; i++) {
        if(!blocks[0][i]->canMoveRight()) {
            canMove = false;
        }
    }
    if(canMove) {
        for(int i = 0; i < 4; i++) {
            blocks[0][i]->moveRight();
        }
    }
}

void Tetrimino::update(int time) {
    if(lastDropped + dropDelay < time) {
        lastDropped = time;
        bool canMove = true;
        for(int i = 0; i < 4; i++) {
            if(!blocks[0][i]->canMoveDown()) {
                canMove = false;
                hitBottom = true;
            }
        }
        if(canMove) {
            for(int i = 0; i < 4; i++) {
                blocks[0][i]->moveDown();
            }
        }
    }
}

void Tetrimino::addBlocks(std::vector<Block> &blocks) {
    for(int i = 0; i < 4; i++) {
        blocks.push_back(*this->blocks[0][i]);
    }
}

void Tetrimino::startDrop() {
    dropDelay = 50;
}

void Tetrimino::stopDrop() {
    dropDelay *= 500;
}

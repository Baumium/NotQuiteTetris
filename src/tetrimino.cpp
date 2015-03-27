#include "tetrimino.hpp"
#include "block.hpp"

Tetrimino::Tetrimino() : lastDropped(0), dropDelay(500), currentRotation(0), hitBottom(false) {
    Shape shape = static_cast<Shape>(rand() % (I + 1));
    switch(shape) {
        case T:
            rotations = 4;
            blocks[0][0] = new Block(-1, 0, sf::Color::Magenta);
            blocks[0][1] = new Block(0, 0, sf::Color::Magenta);
            blocks[0][2] = new Block(1, 0, sf::Color::Magenta);
            blocks[0][3] = new Block(0, 1, sf::Color::Magenta);

            blocks[1][0] = new Block(0, -1, sf::Color::Magenta);
            blocks[1][1] = new Block(0, 0, sf::Color::Magenta);
            blocks[1][2] = new Block(-1, 0, sf::Color::Magenta);
            blocks[1][3] = new Block(0, 1, sf::Color::Magenta);

            blocks[2][0] = new Block(1, 0, sf::Color::Magenta);
            blocks[2][1] = new Block(0, 0, sf::Color::Magenta);
            blocks[2][2] = new Block(-1, 0, sf::Color::Magenta);
            blocks[2][3] = new Block(0, -1, sf::Color::Magenta);

            blocks[3][0] = new Block(1, 0, sf::Color::Magenta);
            blocks[3][1] = new Block(0, 0, sf::Color::Magenta);
            blocks[3][2] = new Block(0, -1, sf::Color::Magenta);
            blocks[3][3] = new Block(0, 1, sf::Color::Magenta);
            break;
        case J:
            rotations = 4;
            blocks[0][0] = new Block(1, 0, sf::Color::Blue);
            blocks[0][1] = new Block(0, 0, sf::Color::Blue);
            blocks[0][2] = new Block(-1, 0, sf::Color::Blue);
            blocks[0][3] = new Block(-1, 1, sf::Color::Blue);

            blocks[1][0] = new Block(0, 1, sf::Color::Blue);
            blocks[1][1] = new Block(0, 0, sf::Color::Blue);
            blocks[1][2] = new Block(0, -1, sf::Color::Blue);
            blocks[1][3] = new Block(-1, -1, sf::Color::Blue);

            blocks[2][0] = new Block(1, -1, sf::Color::Blue);
            blocks[2][1] = new Block(1, 0, sf::Color::Blue);
            blocks[2][2] = new Block(0, 0, sf::Color::Blue);
            blocks[2][3] = new Block(-1, 0, sf::Color::Blue);

            blocks[3][0] = new Block(1, 1, sf::Color::Blue);
            blocks[3][1] = new Block(0, 1, sf::Color::Blue);
            blocks[3][2] = new Block(0, 0, sf::Color::Blue);
            blocks[3][3] = new Block(0, -1, sf::Color::Blue);
            break;
        case Z:
            rotations = 2;
            blocks[0][0] = new Block(1, 0, sf::Color::Red);
            blocks[0][1] = new Block(0, 0, sf::Color::Red);
            blocks[0][2] = new Block(0, 1, sf::Color::Red);
            blocks[0][3] = new Block(-1, 1, sf::Color::Red);

            blocks[1][0] = new Block(0, 1, sf::Color::Red);
            blocks[1][1] = new Block(0, 0, sf::Color::Red);
            blocks[1][2] = new Block(-1, 0, sf::Color::Red);
            blocks[1][3] = new Block(-1, -1, sf::Color::Red);
            break;
        case O:
            rotations = 1;
            blocks[0][0] = new Block(1, 1, sf::Color::Yellow);
            blocks[0][1] = new Block(0, 1, sf::Color::Yellow);
            blocks[0][2] = new Block(1, 0, sf::Color::Yellow);
            blocks[0][3] = new Block(0, 0, sf::Color::Yellow);
            break;
        case L:
            rotations = 4;
            blocks[0][0] = new Block(1, 1, sf::Color(255, 140, 0));
            blocks[0][1] = new Block(1, 0, sf::Color(255, 140, 0));
            blocks[0][2] = new Block(0, 0, sf::Color(255, 140, 0));
            blocks[0][3] = new Block(-1, 0, sf::Color(255, 140, 0));

            blocks[1][0] = new Block(0, 1, sf::Color(255, 140, 0));
            blocks[1][1] = new Block(-1, 1, sf::Color(255, 140, 0));
            blocks[1][2] = new Block(0, 0, sf::Color(255, 140, 0));
            blocks[1][3] = new Block(0, -1, sf::Color(255, 140, 0));

            blocks[2][0] = new Block(1, 0, sf::Color(255, 140, 0));
            blocks[2][1] = new Block(0, 0, sf::Color(255, 140, 0));
            blocks[2][2] = new Block(-1, 0, sf::Color(255, 140, 0));
            blocks[2][3] = new Block(-1, -1, sf::Color(255, 140, 0));

            blocks[3][0] = new Block(0, 1, sf::Color(255, 140, 0));
            blocks[3][1] = new Block(0, 0, sf::Color(255, 140, 0));
            blocks[3][2] = new Block(0, -1, sf::Color(255, 140, 0));
            blocks[3][3] = new Block(1, -1, sf::Color(255, 140, 0));
            break;
        case S:
            rotations = 2;
            blocks[0][0] = new Block(1, 1, sf::Color::Green);
            blocks[0][1] = new Block(0, 1, sf::Color::Green);
            blocks[0][2] = new Block(0, 0, sf::Color::Green);
            blocks[0][3] = new Block(-1, 0, sf::Color::Green);

            blocks[1][0] = new Block(0, 0, sf::Color::Green);
            blocks[1][1] = new Block(0, -1, sf::Color::Green);
            blocks[1][2] = new Block(-1, 0, sf::Color::Green);
            blocks[1][3] = new Block(-1, 1, sf::Color::Green);
            break;
        case I:
            rotations = 2;
            blocks[0][0] = new Block(2, 0, sf::Color::Cyan);
            blocks[0][1] = new Block(1, 0, sf::Color::Cyan);
            blocks[0][2] = new Block(0, 0, sf::Color::Cyan);
            blocks[0][3] = new Block(-1, 0, sf::Color::Cyan);

            blocks[1][0] = new Block(0, 2, sf::Color::Cyan);
            blocks[1][1] = new Block(0, 1, sf::Color::Cyan);
            blocks[1][2] = new Block(0, 0, sf::Color::Cyan);
            blocks[1][3] = new Block(0, -1, sf::Color::Cyan);
            break;
        default:
            rotations = 1;
            blocks[0][0] = new Block(0, 0, sf::Color::Cyan);
            blocks[0][1] = new Block(0, 1, sf::Color::Cyan);
            blocks[0][2] = new Block(0, 2, sf::Color::Cyan);
            blocks[0][3] = new Block(0, 3, sf::Color::Cyan);
            break;
    }
}

void Tetrimino::render(sf::RenderWindow &window) {
    for(int i = 0; i < 4; i++) {
        blocks[currentRotation][i]->render(window);
    }
}

void Tetrimino::moveLeft(std::vector<Block> &stationaryBlocks) {
    bool canMove = true;
    for(int i = 0; i < 4; i++) {
        if(!blocks[currentRotation][i]->canMoveLeft()) {
            canMove = false;
            break;
        }
        for(std::vector<Block>::iterator block = stationaryBlocks.begin(); block != stationaryBlocks.end(); ++block) {
            if(blocks[currentRotation][i]->getY() == block->getY() && blocks[currentRotation][i]->getX() - blocks[currentRotation][i]->getWidth() == block->getX()) {
                canMove = false;
                break;
            }
        }
    }
    if(canMove) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < rotations; j++) {
                blocks[j][i]->moveLeft();
            }
        }
    }
}

void Tetrimino::moveRight(std::vector<Block> &stationaryBlocks) {
    bool canMove = true;
    for(int i = 0; i < 4; i++) {
        if(!blocks[currentRotation][i]->canMoveRight()) {
            canMove = false;
            break;
        }
        for(std::vector<Block>::iterator block = stationaryBlocks.begin(); block != stationaryBlocks.end(); ++block) {
            if(blocks[currentRotation][i]->getY() == block->getY() && blocks[currentRotation][i]->getX() + blocks[currentRotation][i]->getWidth() == block->getX()) {
                canMove = false;
                break;
            }
        }
    }
    if(canMove) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < rotations; j++) {
                blocks[j][i]->moveRight();
            }
        }
    }
}

void Tetrimino::update(int time, std::vector<Block> &stationaryBlocks) {
    //Move tetrimino down
    if(lastDropped + dropDelay < time) {
        lastDropped = time;
        bool canMove = true;
        for(int i = 0; i < 4; i++) {
            if(!blocks[currentRotation][i]->canMoveDown()) {
                canMove = false;
                hitBottom = true;
                break;
            }
            for(std::vector<Block>::iterator block = stationaryBlocks.begin(); block != stationaryBlocks.end(); ++block) {
                if(blocks[currentRotation][i]->getX() == block->getX() && blocks[currentRotation][i]->getY() + blocks[currentRotation][i]->getHeight() == block->getY()) {
                    canMove = false;
                    hitBottom = true;
                    break;
                }
            }
        }
        if(canMove) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < rotations; j++) {
                    blocks[j][i]->moveDown();
                }
            }
        }
    }
}

void Tetrimino::addBlocks(std::vector<Block> &blocks) {
    for(int i = 0; i < 4; i++) {
        blocks.push_back(*this->blocks[currentRotation][i]);
    }
}

void Tetrimino::startDrop() {
    dropDelay = 50;
}

void Tetrimino::stopDrop() {
    dropDelay = 500;
}

void Tetrimino::rotate() {
    currentRotation = currentRotation < rotations - 1 ? currentRotation + 1 : 0;
}

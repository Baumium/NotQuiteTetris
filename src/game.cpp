#include "game.hpp"
#include "block.hpp"
#include "tetrimino.hpp"
#include <cstdio>

const int Game::SCREEN_WIDTH = 250;
const int Game::SCREEN_HEIGHT = 500;

Game::Game() {
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Not Quite Tetris");
    window.setKeyRepeatEnabled(false);
    font.loadFromFile("assets/font.ttf");
    scoreText.setFont(font);
    scoreText.setColor(sf::Color::White);
    scoreText.setPosition(SCREEN_WIDTH - 50, 0);
    scoreText.setCharacterSize(15);
    tetrimino = new Tetrimino();
    isPlaying = false;
    blocks = new std::vector<Block>();
    score = 0;
}

void Game::update() {
    sf::Event event;
    while(window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Left:
                        tetrimino->moveLeft(*blocks);
                        break;
                    case sf::Keyboard::Right:
                        tetrimino->moveRight(*blocks);
                        break;
                    case sf::Keyboard::Space:
                        isPlaying = !isPlaying;
                        break;
                    case sf::Keyboard::Down:
                        tetrimino->startDrop();
                        break;
                    case sf::Keyboard::Up:
                        tetrimino->rotate(*blocks);
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                switch(event.key.code) {
                    case sf::Keyboard::Down:
                        tetrimino->stopDrop();
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    if(isPlaying) {
        if(tetrimino->hitBottom) {
            tetrimino->addBlocks(*blocks);
            tetrimino = new Tetrimino();
        } else {
            tetrimino->update(clock.getElapsedTime().asMilliseconds(), *blocks);
        }

        //Check is there is a full line to remove
        for(unsigned long i = 0; i < blocks->size(); ++i) {
            if(blocks->at(i).getX() == 0) {
                int number = 0;
                Block block = blocks->at(i);
                //Detect if there are 10 blocks on a line
                for(unsigned long j = 0; j < blocks->size(); ++j) {
                    if(block.getY() == blocks->at(j).getY()) {
                        number++;
                    }
                }
                //Remove all blocks on the line
                if(number >= 10) {
                    score++;
                    for(unsigned long j = 0; j < blocks->size(); ++j) {
                        if(block.getY() == blocks->at(j).getY()) {
                            blocks->erase(blocks->begin() + j);
                            j--;
                        }
                    }
                    //Lower every block above by one line
                    for(unsigned long j = 0; j < blocks->size(); ++j) {
                        if(block.getY() > blocks->at(j).getY()) {
                            blocks->at(j).moveDown();
                        }
                    }
                }

            }
        }
    }
    scoreText.setString(std::to_string(score));
}

void Game::render() {
    window.clear(sf::Color::Black);
    tetrimino->render(window);

    for(std::vector<Block>::iterator iterator = blocks->begin(); iterator != blocks->end(); ++iterator) {
        iterator->render(window);
    }

    //Display score
    window.draw(scoreText);

    window.display();
}

void Game::execute() {
    while(window.isOpen()) {
        update();
        render();
    }
}


#include "game.hpp"
#include "block.hpp"
#include "tetrimino.hpp"
#include <cstdio>

const int Game::SCREEN_WIDTH = 250;
const int Game::SCREEN_HEIGHT = 500;

Game::Game() {
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Not Quite Tetris");
    window.setKeyRepeatEnabled(false);
    tetrimino = new Tetrimino(O);
    isPlaying = false;
    blocks = new std::vector<Block>();
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
                        tetrimino->moveLeft();
                        break;
                    case sf::Keyboard::Right:
                        tetrimino->moveRight();
                        break;
                    case sf::Keyboard::Space:
                        isPlaying = true;
                        break;
                    case sf::Keyboard::Down:
                        tetrimino->startDrop();
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
            tetrimino = new Tetrimino(O);
        } else {
            tetrimino->update(clock.getElapsedTime().asMilliseconds());
        }
    }
}

void Game::render() {
    window.clear(sf::Color::Black);
    tetrimino->render(window);

    for(std::vector<Block>::iterator iterator = blocks->begin(); iterator != blocks->end(); ++iterator) {
        iterator->render(window);
    }

    window.display();
}

void Game::execute() {
    while(window.isOpen()) {
        update();
        render();
    }
}


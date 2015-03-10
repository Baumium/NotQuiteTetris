#include <SDL2/SDL.h>
#include <cstdio>
#include "game.h"
#include "shapes.h"

//Screen resolution
const int Game::SCREEN_WIDTH = 250;
const int Game::SCREEN_HEIGHT = 500;

Game::Game() {
    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Create window and renderer
    window = SDL_CreateWindow("Not Quite Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    isExit = false;
    isPlaying = false;

    tetrimino = new Tetrimino(I);
}

void Game::input() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                isExit = true;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE: //Escape = mark program for closure
                        isExit = true;
                        break;
                    case SDLK_SPACE: //If space is pressed, start the game
                        isPlaying = true;
                        break;
                    case SDLK_LEFT:
                        tetrimino->moveLeft();
                        break;
                    case SDLK_RIGHT:
                        tetrimino->moveRight();
                }
                break;
        }
    }
}

void Game::update() {
    if(isPlaying) {
        tetrimino->update();
    }
}

void Game::render() {
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    tetrimino->render(renderer);


    SDL_RenderPresent(renderer);
}


void Game::cleanUp() {
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_Quit();
}

void Game::execute() {
    while(!isExit) {
        input();
        update();
        render();
    }
    cleanUp();
}

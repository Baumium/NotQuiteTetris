#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "tetrimino.h"

class Game {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        bool isExit;
        bool isPlaying;

        Tetrimino *tetrimino;
    public:
        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;


        Game();
        void input();
        void update();
        void render();
        void execute();
        void cleanUp();
};

#endif

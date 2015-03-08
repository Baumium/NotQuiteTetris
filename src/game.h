#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "block.h"

class Game {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        const Uint8 *keystates;

        bool isExit;
        bool isPlaying;

        Block *block;
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

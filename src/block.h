#ifndef BLOCK_H
#define BLOCK_H

#include <SDL2/SDL.h>

class Block {
    private:
        static const int DIMENSION;

        SDL_Rect *rect;

    public:
        Block(int x, int y);
        int getX() const;
        int getY() const;
        void update();
        void render(SDL_Renderer *renderer);
};

#endif

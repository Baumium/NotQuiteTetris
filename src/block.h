#ifndef BLOCK_H
#define BLOCK_H

#include <SDL2/SDL.h>

class Block {
    private:
        static const int DIMENSION;

        SDL_Rect *rect;

    public:
        Block(int x = 0, int y = 0);
        int getX() const;
        int getY() const;
        void update();
        void render(SDL_Renderer *renderer);
        void moveLeft();
        void moveRight();
        void moveDown();
        bool canMoveLeft();
        bool canMoveRight();
        bool canMoveDown();
};

#endif

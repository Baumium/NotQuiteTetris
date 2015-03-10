#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "block.h"
#include "shapes.h"

class Tetrimino {
    public:
        Tetrimino(Shape shape);
        void render(SDL_Renderer *renderer);
        void moveLeft();
        void moveRight();
        void update();
        void rotate();

    private:
        Block blocks[][4];
        int rotations;

        static const int DROP_DELAY;
        unsigned int lastDropped;
};


#endif

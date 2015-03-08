#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "block.h"
#include "shapes.h"

class Tetrimino {
    public:
        Tetrimino(Shape shape);
        void render(SDL_Renderer *renderer);

    private:
        Block blocks[4];
};


#endif

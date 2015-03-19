#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>

class Block {
    private:
        static const int DIMENSION;
        sf::RectangleShape rect;

    public:
        Block(int x, int y);
        int getX() const;
        int getY() const;
        void update();
        void render(sf::RenderWindow &window);
        void moveLeft();
        void moveRight();
        void moveDown();
        bool canMoveLeft();
        bool canMoveRight();
        bool canMoveDown();
};

#endif

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>

class Block {
    private:
        static const int DIMENSION;
        sf::RectangleShape rect;

    public:
        Block(int x, int y, sf::Color);
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
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

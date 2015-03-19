#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "tetrimino.hpp"

class Game {
    private:
        sf::RenderWindow window;
        Tetrimino *tetrimino;
        sf::Clock clock;
        bool isPlaying;
        std::vector<Block> *blocks;
    public:
        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;

        Game();
        void update();
        void render();
        void execute();
};

#endif

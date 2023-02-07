#pragma once
#include <SFML/Graphics.hpp>

struct X_Y
{
    int x;
    int y;
};

struct my_color
{
    int r;
    int g;
    int b;
};

namespace cr_lvl {

    class Block
    {
    private:
        sf::RectangleShape* block;

    public:
        Block(X_Y size, my_color color);
        sf::RectangleShape* return_block();
        ~Block();
    };
}
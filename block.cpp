#pragma once
#include <SFML/Graphics.hpp>
#include "block.hpp"

namespace cr_lvl {

    Block::Block(X_Y size, my_color color) {
        block = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
        block->setFillColor(sf::Color(color.r, color.g, color.b));
    };

    sf::RectangleShape* Block::return_block(){ return block; };

    Block::~Block() {}
}
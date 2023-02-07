#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include "block.hpp"


// min + (rand() % static_cast<int>(max - min + 1))
//class Block
//{
//    private:
//        sf::RectangleShape *block;
//    public:
//        Block(X_Y size, int color[3]) {
//            block = new sf::RectangleShape (sf::Vector2f(size.x, size.y));
//            block->setFillColor(sf::Color(color[0], color[1], color[2]));
//        };
//        sf::RectangleShape* return_block();
//        ~Block();
//
//
//};
//sf::RectangleShape* Block::return_block() { return block; }
//Block::Block(X_Y size, int color[3]) {}
//Block::~Block() {}

int main()
{
    srand(time(NULL));
    int x, y;
    /*std::cout << "Input, X window size >= 600 and Y window size >= 600, through Enter\nStock 600 x 600\n";
    std::cin >> x >> y;
    if (x < 600) 
        x = 600;
    if (y < 600)
        y = 600;*/
    x = 1920;
    y = 1080;
    X_Y window_size = { x,y };
    /*std::cout << "Input, X block size and Y block size through Enter\nStock 10 x 10\n";
    std::cin >> x >> y;
    if (x < 10)
        x = 10;
    if (y < 10)
        y = 10;*/
    x = 10;
    y = 10;
    X_Y block_size = { x,y };
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Life Game", sf::Style::Fullscreen);
    std::vector<cr_lvl::Block> blocks;
    std::vector<my_color> colors;
    colors.push_back({ 255, 255, 255 });
    colors.push_back({ 255, 255, 0 });
    colors.push_back({ 255, 0, 255 });
    colors.push_back({ 0, 255, 255 });
    colors.push_back({ 255, 0, 0 });
    colors.push_back({ 0, 255, 0 });
    colors.push_back({ 0, 0, 255 });
    colors.push_back({ 0, 0, 0 });
    for (int i = 0; i < colors.size(); i++) { blocks.push_back(cr_lvl::Block(block_size, colors[i])); }
    window.setFramerateLimit(1200);
    sf::RectangleShape gridx(sf::Vector2f(window_size.x, 2));
    gridx.setFillColor(sf::Color(130,130,130));
    sf::RectangleShape gridy(sf::Vector2f(2, window_size.y));
    gridy.setFillColor(sf::Color(130, 130, 130));
    /*sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text Count;
    Count.setFont(font);
    Count.setString("\"SPACE\" - pause(Draw Mode)\n\"Left Mouse Button\" - Delite block\n\"Right Mouse Button\" - Create block\n\"R\" - Restart\n\"C\" - Clear\n\"G\" -  Off grid");
    Count.setCharacterSize(25);
    Count.setPosition(window_size.x / 2-250, window_size.y / 2-150);
    Count.setStyle(sf::Text::Bold);
    Count.setColor(sf::Color::White);*/

    std::vector<std::vector<int>> blocks_grid;
    blocks_grid.resize(window_size.x/block_size.x + 2);

    for (int i = 0; i < blocks_grid.size(); i++) {
        blocks_grid[i].resize(window_size.y / block_size.y+2);
    }
    bool flag_grid = false;
    bool flag_stop = true;
    bool mouse_left_togle = false;
    bool mouse_right_togle = false;
    int color = 1;
    //while (flag_stop && window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
    //            flag_stop = false;
    //        
    //    }
    //    //window.draw(Count);
    //    window.display();
    //}

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
                flag_stop = !flag_stop;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::G))
                flag_grid = !flag_grid;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1))
                color = 1;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2))
                color = 2;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3))
                color = 3;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num4))
                color = 4;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num5))
                color = 5;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num6))
                color = 6;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num7))
                color = 7;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num8))
                color = 8;
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num9))
                color = 9;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                for (int i = 0; i < blocks_grid.size(); i ++) {
                    for (int j = 0; j < blocks_grid[i].size(); j ++) {
                        blocks_grid[i][j] = 0;
                    }
                }
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            mouse_left_togle = true;
        else
            mouse_left_togle = false;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            mouse_right_togle = true;
        else
            mouse_right_togle = false;

        sf::Vector2i position = sf::Mouse::getPosition();
        std::cout << position.x << std::endl;
        if (position.x > 0 && position.y > 0)
            if (0 <= position.x / block_size.x+1 <= window_size.x / block_size.x && 0 <= position.y / block_size.y + 1 <= window_size.y / block_size.y) {
                if (mouse_left_togle) {
                    blocks_grid[position.x / block_size.x + 1][position.y / block_size.y + 1] = color;
                }
                if (mouse_right_togle) {
                    blocks_grid[position.x / block_size.x + 1][position.y / block_size.y + 1] = 0;
                }
            }
        
        window.clear(sf::Color(100, 100, 100));//sf::Color(255,255,255));
        for (int i = 1; i < blocks_grid.size() - 1; i++) {
            for (int j = 1; j < blocks_grid[i].size() - 1; j++) {
                for (int k = 1; k < colors.size()+1; k++)
                if (blocks_grid[i][j] == k) {
                    blocks[k-1].return_block()->setPosition((i - 1) * block_size.x, (j - 1) * block_size.y);
                    window.draw(*blocks[k - 1].return_block());
                }
            }
        }
        if (flag_grid)
            for (int i = 0; i < window_size.x/block_size.x+1; i++) {
                gridy.setPosition(i * block_size.x-1, 0);
                window.draw(gridy);
            }
        if (flag_grid)
            for (int i = 0; i < window_size.y / block_size.y + 1; i++) {
                gridx.setPosition(0, i * block_size.y - 1);
                window.draw(gridx);
            }

        window.display();
    }

    return 0;
}
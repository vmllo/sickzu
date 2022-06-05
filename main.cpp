#include "character.hpp"
#include <iostream>
int main()
{
    Character player;
    Character ob;
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Sickzu neeeenja!");
    float position = player.getPosx();
    float ground = 700;
    float hops = 5;
    float height = 70;
    float hitLimitx = 0;
    float hitLimity = 0;
    int count = 0;
    sf::Vector2i p;
    sf::Vector2f hitbox;
    float speedx = rand() % 300;
    float speedy = rand() % 100;
    float sizex = rand() % 100; 
    float sizey = rand() % 100;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.text.unicode == '\x64')
            {
                position += 30;
                height = -70;
            }
            if (event.text.unicode == '\x61')
            {
                position -= 30;
                height = -70;
            }
            if (event.text.unicode == '\x73')
            {
                height = -10;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    p = sf::Mouse::getPosition(window);
                }
            }
        }
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        window.clear();
        if (speedy >= 0 && speedy <= 1000)
        {
            speedy += .1;
            ob.setCharacter(100, 100, speedx, speedy, sf::Color::Red);
            window.draw(ob.getCharacter());
        }
        else
        {
            speedx = rand() % 1500 + 1;
            speedy = 0;
        }
        player.setCharacter(50, height, position, ground, sf::Color::White);
        window.draw(player.getCharacter());
        window.display();
    }

    return 0;
}
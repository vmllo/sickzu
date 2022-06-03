#include "character.hpp"
#include <iostream>
int main()
{
    Character player;
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Sickzu neeeenja!");
    float position = player.getPosx();
    float ground = 700;
    float hops = 5;
    float height = 70;
    int count = 0;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.text.unicode == '\x64')
            {
                position += 30;
               
            }
            if (event.text.unicode == '\x61')
            {
                position -= 30;
            }
            if (event.text.unicode == '\x77')
            {
                if (count == 0)
                {
                    ground -= 200;
                    count = 1;
                }
            }
            if (count)
            {
                if (ground < 700)
                {
                    ground += 5;
                }
                else if(ground <= 700)
                {
                    count = 0;
                }
                std::cout << ground << std::endl;
            }
            if (event.text.unicode == '\x73')
            {
                height = -10;
            }
            else {
                height = -70;
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        player.setCharacter(50, height, position, ground, sf::Color::White);
        window.draw(player.getCharacter());
        window.display();
    }

    return 0;
}
#include "character.hpp"
#include "UI.hpp"
#include <string>
#include <algorithm>
#include <iostream>
int main()
{
    Character player[5];
    Character ob[2];
    UI ui;
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Sickzu neeeenja!");
    float position = player[0].getPosx();
    float ground = 700;
    float hops = 5;
    float height = 70;
    sf::Vector2i p;
    sf::Vector2f hitbox;
    int count = 0;
    int flag = 0;
    float speedx = rand() % 300;
    float speedy = rand() % 100;
    float sizex = rand() % 100;
    float sizey = rand() % 100;
    float speedenx = rand() % 300;
    float speedeny = rand() % 100;
    float sizeenx = rand() % 100;
    float sizeeny = rand() % 100;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if ('\x64' == event.text.unicode)
            {
                for (int i = 0; i <= 4; i++)
                {
                    window.draw(player[i].getCharacter());
                }
                position += 30;
            }
            if ('\x61' == event.text.unicode)
            {
                for (int i = 0; i <= 4; i++)
                {
                    window.draw(player[i].getCharacter());
                }
                position -= 30;
            }
            if ('\x20' == event.text.unicode)
            {
                for (int i = 0; i <= 4; i++)
                {
                    window.draw(player[i].getCharacter());
                }
                if (!flag)
                {
                    flag = 1;
                    ground = 300;
                }
            }
            else
            {
                if (flag)
                {
                    if (ground < 700)
                    {
                        ground += .5;
                    }
                    if(ground == 700)
                    {
                        flag = 0;
                    }
                }
            }
            if ('\x73' == event.text.unicode)
            {
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    float hitLimity = (player[1].getPosy() + player[1].getSizey()) + 10;
                    float hitLimityy = (ob[0].getPosy() + ob[0].getSizey())+10;
                    float hitlimitx = (player[1].getPosx() + player[1].getSizex()) + 10;
                    float hitlimitxx = (ob[0].getPosx() + ob[0].getSizey()) + 10;
                    if ((hitLimity >= ob[0].getPosy() && hitLimity <= hitLimityy) && (hitlimitx <= hitlimitxx) && (hitlimitx >= ob[0].getPosx()))
                    {
                        count++;
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    float hitLimity = (player[4].getPosy() + player[4].getSizey());
                    float hitLimityy = (ob[0].getPosy() + ob[0].getSizey()) + 10;
                    float hitlimitx = player[4].getPosx() + player[4].getSizex();
                    float hitlimitxx = (ob[0].getPosx() + ob[0].getSizey()) + 10;
                    if ((hitLimity <= hitLimityy && hitLimity >= ob[0].getPosy()) && (hitlimitx <= hitlimitxx) && (hitlimitx >= ob[0].getPosx()))
                    {
                        count++;
                    }
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
            speedy += .2;
            ob[0].setCharacter(100, 100, speedx, speedy, sf::Color::Red);
            window.draw(ob[0].getCharacter());
        }
        else
        {
            speedx = rand() % 1000 + 1;
            speedy = 0;
        }
        if (speedenx >= 0 && speedenx <= 1500)
        {
            speedenx += .2;
            ob[1].setCharacter(100, 100, speedenx, speedeny, sf::Color::Green);
            window.draw(ob[1].getCharacter());
        }
        else
        {
            speedeny = rand() % 1500 + 500;
            speedenx= 0;
        }
        ui.textBox("ArialCE.ttf",std::to_string(count),24,sf::Color::White,50,50);
        player[0].setCharacter(50, height, position, ground, sf::Color::White);
        player[1].setCharacter(50, height, position + 60, ground, sf::Color::Cyan);
        player[2].setCharacter(50, height, position, ground + 60, sf::Color::Cyan);
        player[3].setCharacter(50, height, position, ground - 60, sf::Color::Cyan);
        player[4].setCharacter(50, height, position - 60, ground, sf::Color::Cyan);
        if(count >= 0)
        {
            window.setTitle("Sickzu neeeenja! Score: " +std::to_string(count));
        }
        for (int i = 0; i <= 4; i++)
        {
            window.draw(player[i].getCharacter());
        }
        window.display();
    }

    return 0;
}
#include "character.hpp"
#include "UI.hpp"
#include <string>
#include <algorithm>
#include <iostream>
sf::RenderWindow window(sf::VideoMode(1500, 1000), "Sickzu neeeenja!");
Character player[5];
Character ob[2];
UI ui[2];
float position = player[0].getPosx();
float ground = 850;
float speed;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;

int gravity = 2;
void playerRez()
{
    window.draw(player[0].getCharacter());
    window.draw(player[1].getCharacter());
    window.draw(player[4].getCharacter());
}

void updateMovement() {

    if (ground <= 500)
    {
        velocityY += gravity;
        std::cout << ground << std::endl;
    }
    if (ground > 850)
    {
        ground = 850;
    }

    velocityY += accelerationY;

    ground += velocityY;
}
int main()
{
    int hitr;
    sf::Clock clock;
    int hitl;
    float hops = 5;
    float height = 100;
    sf::Vector2i p;
    sf::Vector2f hitbox;
    int count = 0;
    int flag = 0;
    float speed = 320;
    float speedx = rand() % 300;
    float speedy = 320;
    float sizex = rand() % 100;
    float sizey = rand() % 100;
    float speedenx = rand() % 300;
    float speedeny = rand() % 100;
    sf::Time elapsedTime;
    sf::Time elapsedTime2;
    float sizeenx = rand() % 100;
    float sizeeny = rand() % 100;
    ui[1].textBox("ArialCE.ttf", "Controls: AD(Left:Right) is movement\nSpace: Jump", 24, sf::Color::White, 50, 50);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen())
    {
        elapsedTime = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {

            if ('\x64' == event.text.unicode)
            {
                position += 30;
            }
            if ('\x61' == event.text.unicode)
            {                
                position -= 30;
            }
            if ('\x20' == event.text.unicode)
            {
                float hitLimity = (player[1].getPosy() + player[1].getSizey()) + 10;
                float hitLimityy = (ob[0].getPosy() + ob[0].getSizey()) + 10;
                float hitlimitx = (player[1].getPosx() + player[1].getSizex()) + 10;
                float hitlimitxx = (ob[0].getPosx() + ob[0].getSizey()) + 10;

                if ((hitLimity >= ob[0].getPosy() && hitLimity <= hitLimityy) && (hitlimitx <= hitlimitxx) && (hitlimitx >= ob[0].getPosx()))
                {
                    hitr = 1;
                    hitl = 0;
                    count = 0;
                    velocityY = -30;
                    position -= 100;
                    ui[0].textBox("ArialCE.ttf", "power: A and D go up", 24, sf::Color::White, 50, 100);
                }
                else
                {
                    velocityY = -20;
                }
            }    
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                   
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    float hitLimity = (player[4].getPosy() + player[4].getSizey());
                    float hitLimityy = (ob[0].getPosy() + ob[0].getSizey()) + 10;
                    float hitlimitx = player[4].getPosx() + player[4].getSizex();
                    float hitlimitxx = (ob[0].getPosx() + ob[0].getSizey()) + 10;

                    if ((hitLimity <= hitLimityy && hitLimity >= ob[0].getPosy()) && (hitlimitx <= hitlimitxx) && (hitlimitx >= ob[0].getPosx()))
                    {
                        hitl = 1;
                        hitr = 0;
                        count = 0;
                        flag = 0;
                        ui[0].textBox("ArialCE.ttf", "power: A and D go down", 24, sf::Color::White, 50, 100);
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    float hitLimitvy = (player[4].getPosy() + player[4].getSizey());
                    float hitLimitvyy = (ob[1].getPosy() + ob[1].getSizey()) + 10;
                    float hitlimitvx = player[4].getPosx() + player[4].getSizex();
                    float hitlimitvxx = (ob[1].getPosx() + ob[1].getSizey()) + 10;

                    if ((hitLimitvy <= hitLimitvyy && hitLimitvy >= ob[1].getPosy()) && (hitlimitvx <= hitlimitvxx) && (hitlimitvx >= ob[1].getPosx()))
                    {
                        hitl = 1;
                        hitr = 0;
                        count = 0;
                        flag = 0;
                        ui[0].textBox("ArialCE.ttf", "power: A and D go down", 24, sf::Color::White, 50, 100);
                    }
                }
            }
        }
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        window.clear();
        if (speedenx >= 0 && speedenx <= 1300)
        {
            speedenx += elapsedTime.asSeconds() * speed;
            ob[1].setCharacter(100, 100, speedenx, speedeny, sf::Color::Green);
        }
        else
        {
            count += 10;
            speedeny = rand() % 1000 + 1;
            speedenx = 0;
        }
        if (speedy >= 0 && speedy <= 1000)
        {
            speedy += elapsedTime.asSeconds() * speed;
            ob[0].setCharacter(100, 100, speedx, speedy, sf::Color::Red);
        }
        else
        {
            count += 10;
            speedx = rand() % 1000 + 1;
            speedy = 0;
        }
        player[0].setCharacter(50, height, position, ground, sf::Color::White);
        player[1].setCharacter(50, height, position + 60, ground, sf::Color::Cyan);
        player[4].setCharacter(50, height, position - 60, ground, sf::Color::Cyan);
        if (count >= 0)
        {
            window.setTitle("Sickzu neeeenja! Score: " + std::to_string(count));
        }
        window.draw(ui[0].gettextBox());
        window.draw(ui[1].gettextBox());
        window.draw(ob[1].getCharacter());
        window.draw(ob[0].getCharacter());
        updateMovement();
        playerRez();

        window.display();
    }

    return 0;
}
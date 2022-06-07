#include <SFML/Graphics.hpp>

class Character
{
public:
    void setCharacter(float sizex, float sizey, float posx, float posy, sf::Color color)
    {
        this->posx = posx;
        this->posy = posy;
        this->sizex = sizex;
        this->sizey = sizey;
        character.setSize(sf::Vector2f(sizex, sizey));
        character.setPosition(sf::Vector2f(posx, posy));
        character.setFillColor(color);
    }
    void setHitbox(float hsizex, float hsizey, float hposx, float hposy, sf::Color hcolor)
    {
        this->hposx = hposx;
        this->hposy = hposy;
        this->hsizex = hsizex;
        this->hsizey = hsizey;
        hitbox.setScale(hsizex, hsizey);
        hitbox.setRadius(1.0);
        hitbox.setPosition(sf::Vector2f(hposx, hposy));
        hitbox.setFillColor(hcolor);
    }
    sf::CircleShape getHitBox()
    {
        return hitbox;
    }
    sf::RectangleShape getCharacter()
    {
        return character;
    }
    float getPosx()
    {
        return posx;
    }
    float getPosy()
    {
        return posy;
    }
    float getSizex()
    {
        return sizex;
    }
    float getSizey()
    {
        return sizey;
    }
    float gethPosx()
    {
        return hposx;
    }
    float gethPosy()
    {
        return hposy;
    }
    float gethSizex()
    {
        return hsizex;
    }
    float gethSizey()
    {
        return hsizey;
    }

private:
    sf::RectangleShape character;
    sf::CircleShape hitbox;
    float posx;
    float posy;
    float sizex;
    float sizey;
    float hposx;
    float hposy;
    float hsizex;
    float hsizey;
};
#include <SFML/Graphics.hpp>

class Character
{
public:
    void setCharacter(float sizex, float sizey, float posx, float posy, sf::Color color)
    {
        this->posx = posx;
        character.setSize(sf::Vector2f(sizex, sizey));
        character.setPosition(sf::Vector2f(posx, posy));
        character.setFillColor(color);
    }
   sf::RectangleShape getCharacter()                                                   
    {                                                                                
        return character;                                                               
    }   
    float getPosx()
    {
        return posx;
    }
private:
    sf::RectangleShape character;
    float posx;
};
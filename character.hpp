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
    float getSizey(){
        return sizey;
    }
    void movement()
    {

    }
    bool targetHit(sf::Vector2i)
    {

    }
    
private:
    sf::RectangleShape character;
    float posx;
    float posy;
    float sizex;
    float sizey;
};
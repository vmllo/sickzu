
#include <SFML/Graphics.hpp>
#include <string>

class UI
{
public:
    void textBox(std::string ttfstring, std::string displaystring, int size, sf::Color color, int x, int y)
    {

        if (!font.loadFromFile(ttfstring))
        {
            printf("aint working nerd\n");
        }
        textboxS.setFont(font);
        textboxS.setString(displaystring);
        textboxS.setCharacterSize(size);
        textboxS.setFillColor(color);
        textboxS.setPosition(sf::Vector2f(x, y));
    }
    sf::Text gettextBox()
    {
        return textboxS;
    }

private:
    sf::Font font;
    sf::Text textboxS;
    sf::RectangleShape button;
    sf::Mouse mouse;
    sf::Vector2f size;
};
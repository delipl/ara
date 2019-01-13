#include "lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 720), "Gdzie jest widelec");

    sf::Texture rudys;
    if (!rudys.loadFromFile("rudy.png"))
    {
        // error...
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Sprite rudy;
        rudy.setTexture(rudys);
        rudy.setOrigin(250, 297);
        rudy.setPosition(sf::Vector2f(1366/2.0f,720/2.0f));
        sf::Vector2f scale = rudy.getScale();
        rudy.setScale(sf::Vector2f(0.5f, 0.5f));
        for(;;)
        {
            window.clear(sf::Color(0, 0, 0, 255));
            rudy.rotate(0.1);
            window.draw(rudy);
            window.display();
        }
        window.clear();

    }

    return 0;
}

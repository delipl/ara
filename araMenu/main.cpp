#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>
#include "Messages.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 720), "A.R.A");

    sf::Texture Tlo;
    if (!Tlo.loadFromFile("img\\backgroundImage.png"))
    {
        ms_error(12, "nie zaladowano menuBackground", true);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Sprite tlo;
        tlo.setTexture(Tlo);
        window.draw(tlo);
        window.display();
        window.clear();
    }
    while(true){
        int a;
        std::cin>>a;
        if(a==1){
            window.close();
            system("..\\..\\..\\bin\\Debug\\ara.exe");

        }
    }
}

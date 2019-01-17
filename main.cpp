#include "lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "lib/SFML-2.5.1/include/SFML/Window.hpp"
#include <iostream>
//#include <Windows.h>
class Pole:public sf::Sprite{
        public:
            std::string objekt;
            int owner;  //0-puste           1-gracz 1            2- gracz 2

    };

#include "Figures.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 720), "Gdzie jest widelec");

//=================================T£O================================================//
    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {

    }





    sf::Sprite fields[17][34];
    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                    fields[i][j].setTexture(Background);
                    fields[i][j].setScale(sf::Vector2f(0.2f, 0.2f));
                    fields[i][j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
                }
            }
            else
            {
                if(j%2==1)
                {
                    fields[i][j].setTexture(Background);
                    fields[i][j].setScale(sf::Vector2f(0.2f, 0.2f));
                    fields[i][j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
                }
            }
        }
    }

        for (int i = 0; i<8;++i)
        {
            for (int j = 0; j<8; ++j)
            {
                if((j-i)>=0)
                {
                    fields[i][j-i].setColor(sf::Color(0,0,0));
                    fields[i][26+j].setColor(sf::Color(0,0,0));
                }
                else
                {
                    fields[9+i][j].setColor(sf::Color(0,0,0));
                    fields[9+i][32-j].setColor(sf::Color(0,0,0));
                }
            }
        }


//=================================RUDY===============================================//
    sf::Texture rudys;
    if (!rudys.loadFromFile("img/rudy.png"))
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

//=================================WYŒWIETLANIE==========================================//

        for (int i = 0; i<17; ++i)
        {
            for (int j = 0; j<33; ++j)
            {
                window.draw(fields[i][j]);
            }
        }

        window.draw(rudy);
        window.display();
        window.clear();
    }
    return 0;
}

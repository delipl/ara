#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 720), "Gdzie jest widelec");

//=================================T£O================================================//
    sf::Texture texture;
    if (!texture.loadFromFile("img/dupa.png"))
    {

    }

    sf::Sprite background[34][9];
    for (int i = 0; i<9;++i)
    {
        for (int j = 0; j<34; ++j)
        {
            background[i][j].setTexture(texture);
        }
    }


//=================================RUDY===============================================//
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

//=================================WYŒWIETLANIE==========================================//

        for (int i = 0; i<9; ++i)
        {
            for (int j = 0; j<34; ++j)
            {
                if(j%2==0)
                {
                    background[i][j].setScale(sf::Vector2f(0.25f, 0.25f));
                    background[i][j].setPosition(i*80, j*25);
                    window.draw(background[i][j]);
                }
                else
                {
                    background[i][j].setScale(sf::Vector2f(0.25f, 0.25f));
                    background[i][j].setPosition(40+(i*80), j*25);
                    window.draw(background[i][j]);
                }

            }
        }

        //window.draw(rudy);
        window.display();
        window.clear();
    }
    return 0;
}

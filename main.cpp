#include "Figures.h"
#include <math.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 720), "Gdzie jest widelec");

//=================================T£O================================================//
    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {

    }

    sf::Texture texture_pawn;
    sf::Texture texture_ghost;
    sf::Texture texture_cav;
    sf::Texture texture_king;
    sf::Texture texture_tower;
    sf::Texture texture_charge;
    sf::Texture texture_mystery;
    sf::Texture texture_notexist;

    {   //wczytuje teksturki pionkow
        if (!texture_pawn.loadFromFile("img/pawn.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
        if (!texture_ghost.loadFromFile("img/ghost.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
        if (!texture_cav.loadFromFile("img/cav.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
        if (!texture_king.loadFromFile("img/king.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
        if (!texture_tower.loadFromFile("img/tower.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
        if (!texture_charge.loadFromFile("img/charge.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
        if (!texture_mystery.loadFromFile("img/mystery.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
        if (!texture_notexist.loadFromFile("img/notexist.png"))
        {
            std::cout<<"NIE JEST DOBRZE!!!\n";
            system("PAUSE");
        }
    }

    int board_size_y = 34;

    int field_size = 40;

    Pole background_fields[17][34];
    Pole *front_fields;
    front_fields = new Pole [578];

    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            front_fields[i * board_size_y + j].name = "empty";
            if(i%2==j%2)
            {
                background_fields[i][j].setTexture(Background);
                background_fields[i][j].setScale(sf::Vector2f(0.2, 0.2));
                background_fields[i][j].setPosition(sf::Vector2f(i*30,j*20));
                front_fields[i * board_size_y + j].setTexture(Background);
                front_fields[i * board_size_y + j].setScale(sf::Vector2f(0.2, 0.2));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(i*30,j*20));
            }
            else
            {
                background_fields[i][j].setScale(sf::Vector2f(0, 0));
                //background_fields[i][j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + j].setScale(sf::Vector2f(0, 0));
                //front_fields[i * board_size_y + j].setPosition(sf::Vector2f(10000, 10000));
            }
        }
    }

    for (int i = 0; i<8;++i)
    {
        for (int j = 0; j<8; ++j)
        {
            if((j-i)>=0)
            {
                background_fields[i][j-i].setScale(sf::Vector2f(0, 0));
                background_fields[i][26+j].setScale(sf::Vector2f(0, 0));
                front_fields[i * board_size_y + j-i].setScale(sf::Vector2f(0, 0));
                front_fields[i * board_size_y + 26+j].setScale(sf::Vector2f(0, 0));
            }
            else
            {
                background_fields[9+i][j].setScale(sf::Vector2f(0, 0));
                background_fields[9+i][32-j].setScale(sf::Vector2f(0, 0));
                front_fields[(9+i) * board_size_y + j].setScale(sf::Vector2f(0, 0));
                front_fields[(9+i) * board_size_y + 32-j].setScale(sf::Vector2f(0, 0));
            }
        }
    }

    LoadSave(0, front_fields);

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if(front_fields[i * board_size_y + j].name == "pawn")
            {
                front_fields[i * board_size_y + j].setTexture(texture_pawn);
            }
            else if(front_fields[i * board_size_y + j].name == "tower")
            {
                front_fields[i * board_size_y + j].setTexture(texture_tower);
            }
            else if(front_fields[i * board_size_y + j].name == "ghost")
            {
                front_fields[i * board_size_y + j].setTexture(texture_ghost);
            }
            else if(front_fields[i * board_size_y + j].name == "cav")
            {
                front_fields[i * board_size_y + j].setTexture(texture_cav);
            }
            else if(front_fields[i * board_size_y + j].name == "king")
            {
                front_fields[i * board_size_y + j].setTexture(texture_king);
            }
            else if(front_fields[i * board_size_y + j].name == "mystery")
            {
                front_fields[i * board_size_y + j].setTexture(texture_mystery);
            }
            else if(front_fields[i * board_size_y + j].name == "charge")
            {
                front_fields[i * board_size_y + j].setTexture(texture_charge);
            }
            else if(front_fields[i * board_size_y + j].name == "notexist")
            {
                front_fields[i * board_size_y + j].setTexture(texture_notexist);
            }
            background_fields[i][j].setTexture(Background);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

//==============================Aktualizacja tekstur=====================================//

        for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                if(front_fields[i * board_size_y + j].name == "pawn")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_pawn);
                }
                else if(front_fields[i * board_size_y + j].name == "tower")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_tower);
                }
                else if(front_fields[i * board_size_y + j].name == "ghost")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_ghost);
                }
                else if(front_fields[i * board_size_y + j].name == "cav")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_cav);
                }
                else if(front_fields[i * board_size_y + j].name == "king")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_king);
                }
                else if(front_fields[i * board_size_y + j].name == "mystery")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_mystery);
                }
                else if(front_fields[i * board_size_y + j].name == "charge")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_charge);
                }
                else if(front_fields[i * board_size_y + j].name == "notexist")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_notexist);
                }
                background_fields[i][j].setTexture(Background);
            }
        }

//==============================Zabawa z myszka==========================================//

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                if(pow(localPosition.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(localPosition.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                {
                    background_fields[i][j].setColor(sf::Color::Blue);
                    std::cout<<i<<" x "<<j<<"\n";
                }
            }
        }

//=================================WYŒWIETLANIE==========================================//

        for (int i = 0; i<17; ++i)
        {
            for (int j = 0; j<33; ++j)
            {
                window.draw(background_fields[i][j]);
                //window.draw(front_fields[i * board_size_y + j]);
            }
        }

        window.display();
        window.clear();
    }

    SaveGame(2, front_fields);

    return 0;
}

//#include "Figures.h"

#include "Load_From_File.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 720), "Gdzie jest widelec");

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

    sf::Sprite background_fields[17][34];
    Pole *front_fields;
    front_fields = new Pole [578];

    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            front_fields[i * board_size_y + j].name = "empty";
            if(i%2==0)
            {
                if(j%2==0)
                {
                    background_fields[i][j].setTexture(texture_king);
                    background_fields[i][j].setScale(sf::Vector2f(0.2f, 0.2f));
                    background_fields[i][j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
                    front_fields[i * board_size_y + j].setTexture(Background);
                    front_fields[i * board_size_y + j].setScale(sf::Vector2f(0.2f, 0.2f));
                    front_fields[i * board_size_y + j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
                }
            }
            else
            {
                if(j%2==1)
                {
                    background_fields[i][j].setTexture(texture_king);
                    background_fields[i][j].setScale(sf::Vector2f(0.2f, 0.2f));
                    background_fields[i][j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
                    front_fields[i * board_size_y + j].setTexture(Background);
                    front_fields[i * board_size_y + j].setScale(sf::Vector2f(0.2f, 0.2f));
                    front_fields[i * board_size_y + j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
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
                background_fields[i][j-i].setPosition(10000, 10000);
                background_fields[i][26+j].setPosition(10000, 10000);
                front_fields[i * board_size_y + j-i].setPosition(10000, 10000);
                front_fields[i * board_size_y + 26+j].setPosition(10000, 10000);
            }
            else
            {
                background_fields[9+i][j].setPosition(10000, 10000);
                background_fields[9+i][32-j].setPosition(10000, 10000);
                front_fields[(9+i) * board_size_y + j].setPosition(10000, 10000);
                front_fields[(9+i) * board_size_y + 32-j].setPosition(10000, 10000);
            }
        }
    }

    LoadSave(0, front_fields);

    SaveGame(1, front_fields);

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
            background_fields[i][j].setScale(sf::Vector2f(0.2f, 0.2f));
            background_fields[i][j].setPosition(sf::Vector2f(i*30.0f,j*20.0f));
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

//=================================WYŒWIETLANIE==========================================//

        for (int i = 0; i<17; ++i)
        {
            for (int j = 0; j<33; ++j)
            {
                //window.draw(background_fields[i][j]);
                window.draw(front_fields[i * board_size_y + j]);
            }
        }

        window.display();
        window.clear();
    }

    return 0;
}

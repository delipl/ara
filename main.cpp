#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "Figures.h"
#include "Header.h"
#include <math.h>

int main()
{
    renderWindow();
    sf::RenderWindow window(sf::VideoMode(VIEW_HEIGHT, VIEW_HEIGHT), "Gdzie jest widelec");
    sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
//=================================T£O================================================//



    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {

    }

    loadTexture();

    int board_size_y = 34;



    Pole klik;
    klik.setPosition(sf::Vector2f(680, 350));
    klik.setScale(sf::Vector2f(0.2, 0.2));
    klik.setTexture(Background);
    klik.setColor(sf::Color::Red);

    front_fields = new Pole [578];
    // Przygotowanie tablic

    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            front_fields[i * board_size_y + j].name = "empty";
            if(i%2==j%2)
            {
                background_fields[i][j].setTexture(Background);
                background_fields[i][j].setScale(sf::Vector2f(0.2, 0.2));
                background_fields[i][j].setOrigin(sf::Vector2f(0.1, 0.1));
                background_fields[i][j].setPosition(sf::Vector2f(i*30,j*20));
                front_fields[i * board_size_y + j].setScale(sf::Vector2f(0.2, 0.2));
                front_fields[i * board_size_y + j].setOrigin(sf::Vector2f(0.1, 0.1));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(i*30,j*20));
            }
            else
            {
                background_fields[i][j].setPosition(sf::Vector2f(10000, 10000));
                background_fields[i][j].setOrigin(sf::Vector2f(0.1, 0.1));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + j].setOrigin(sf::Vector2f(0.1, 0.1));
            }
        }
    }

    for (int i = 0; i<8;++i)
    {
        for (int j = 0; j<8; ++j)
        {
            if((j-i)>=0)
            {
                background_fields[i][j-i].setPosition(sf::Vector2f(10000, 10000));
                background_fields[i][26+j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + j-i].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + 26+j].setPosition(sf::Vector2f(10000, 10000));
            }
            else
            {
                background_fields[9+i][j].setPosition(sf::Vector2f(10000, 10000));
                background_fields[9+i][32-j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[(9+i) * board_size_y + j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[(9+i) * board_size_y + 32-j].setPosition(sf::Vector2f(10000, 10000));
            }
        }
    }

    for(int i = 8; i < 17; i ++)
    {
        background_fields[i][33].setPosition(sf::Vector2f(10000, 10000));
        front_fields[i * board_size_y + 33].setPosition(sf::Vector2f(10000, 10000));
    }

    // Koniec przygotowania

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
            else if(front_fields[i * board_size_y + j].name == "empty")
            {
                front_fields[i * board_size_y + j].setTexture(texture_nothing);
            }
            background_fields[i][j].setTexture(Background);
        }
    }



    // Tryby pracy myszki

    std::string actual_mode = "play"; //aktualny tryb dzialania myszki: "play", "edit"

    sf::Vector2i mouse_position;
    bool mouse_pressed = 0;

    // Tryb edit

    std::string actual_name = "pawn";
    int actual_owner = 0;

    // Tryb play

    int figure_x = 0;
    int figure_y = 0;
    int target_x = 0;
    int target_y = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    ResizeView(window, view);
                    break;
            }

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
                else if(front_fields[i * board_size_y + j].name == "empty")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_nothing);
                }
                background_fields[i][j].setTexture(Background);
            }
        }

//==============================Zabawa z myszka==========================================//
        mouse_pressed = 0;

        mouse_position = sf::Mouse::getPosition(window);

        for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                background_fields[i][j].setColor(sf::Color::White);

                if((front_fields[i * board_size_y + j].name != "empty") && (front_fields[i * board_size_y + j].name != "notexist"))
                {
                    if(front_fields[i * board_size_y + j].owner == 1)
                    {
                        background_fields[i][j].setColor(sf::Color::Yellow);
                    }
                    else
                    {
                        background_fields[i][j].setColor(sf::Color::Blue);
                    }
                }

                if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                {
                    background_fields[i][j].setColor(sf::Color::Green);
                }
            }
        }


        while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mouse_position = sf::Mouse::getPosition(window);
            mouse_pressed = 1;
        }
//===================================Chowanie Konsolki============================//
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            ShowWindow( hWnd, SW_HIDE );
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            ShowWindow( hWnd, SW_SHOW );
        }
//===============================================================================//
        if((pow(mouse_position.x - 20 - klik.getPosition().x, 2) + pow(mouse_position.y - 20 - klik.getPosition().y, 2) < 400) && mouse_pressed)
        {
            if(actual_mode == "edit")
            {
                actual_mode = "play";
                std::cout<<"Zmieniono tryb na \"play\"\n";
            }
            else
            {
                actual_mode = "edit";
                std::cout<<"Zmieniono tryb na \"edit\"\n";
                std::cin>>actual_name;
                std::cin>>actual_owner;
            }
        }
        else if((actual_mode == "edit") && mouse_pressed)
        {
            for(int i = 0; i < 17; i ++)
            {
                for(int j = 0; j < 34; j ++)
                {
                    if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                    {
                        front_fields[i * board_size_y + j].name = actual_name;
                        front_fields[i * board_size_y + j].owner = actual_owner;
                        i = 16;
                        j = 33;
                    }
                }
            }
        }
        else if((actual_mode == "play") && mouse_pressed)
        {
            if((figure_x == 0) && (figure_y == 0))
            {
                for(int i = 0; i < 17; i ++)
                {
                    for(int j = 0; j < 34; j ++)
                    {
                        if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                        {
                            figure_x = i;
                            figure_y = j;
                        }
                    }
                }
            }
            else
            {
                for(int i = 0; i < 17; i ++)
                {
                    for(int j = 0; j < 34; j ++)
                    {
                        if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                        {
                            target_x = i;
                            target_y = j;
                            if(CanMove(front_fields, figure_x, figure_y, target_x, target_y))
                            {
                                Move(front_fields, figure_x, figure_y, target_x, target_y);
                            }
                            figure_x = 0;
                            figure_y = 0;
                        }
                    }
                }
            }
        }

//=================================WYŒWIETLANIE==========================================//

        for (int i = 0; i<17; ++i)
        {
            for (int j = 0; j<33; ++j)
            {
                window.draw(background_fields[i][j]);
                window.draw(front_fields[i * board_size_y + j]);
            }
        }
        view.setCenter(sf::Vector2f(360.0f, 360.0f));
        window.draw(klik);
        window.setView(view);
        window.display();
        window.clear();
    }

    SaveGame(2, front_fields);

    return 0;
}

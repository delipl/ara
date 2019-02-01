#include "pole.h"

// Pionki

sf::Texture texture_pawn;
sf::Texture texture_ghost;
sf::Texture texture_cav;
sf::Texture texture_king;
sf::Texture texture_tower;
sf::Texture texture_charge;
sf::Texture texture_mystery;
sf::Texture texture_notexist;
sf::Texture texture_nothing;
sf::Texture Background;

// Czcionka

sf::Font font;

// Menu

sf::Texture menu;
sf::Texture save;
sf::Sprite Menu;
sf::Sprite Save;

void loadFigureTexture(){
    //wczytuje teksturki pionkow
    if (!texture_pawn.loadFromFile("img/pawn.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_ghost.loadFromFile("img/ghost.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_cav.loadFromFile("img/cav.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_king.loadFromFile("img/king.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_tower.loadFromFile("img/tower.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_charge.loadFromFile("img/charge.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_mystery.loadFromFile("img/mystery.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_notexist.loadFromFile("img/notexist.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!texture_nothing.loadFromFile("img/nothing.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!Background.loadFromFile("img/dupa.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
}

void loadMenuTexture(){
    //wczytuje textury menu itp.
    if (!menu.loadFromFile("img\\menu.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }
    if (!save.loadFromFile("img\\save.png"))
    {
        ms_error(666, "Header.h", 1);
        system("PAUSE");
    }

    Menu.setTexture(menu);
    Menu.setPosition(sf::Vector2f(0, 0));
    Menu.setScale(sf::Vector2f(1, 1));

    Save.setTexture(save);
    Save.setPosition(sf::Vector2f(0, 0));
    Save.setScale(sf::Vector2f(1, 1));
}

void setFigureTexture()

#include "pole.h"

//-------------------------------Deklaracja tekstur-----------------------------------------------
// frontFields
sf::Texture texture_pawn;
sf::Texture texture_ghost;
sf::Texture texture_cav;
sf::Texture texture_king;
sf::Texture texture_tower;
sf::Texture texture_charge;
sf::Texture texture_mystery;
sf::Texture texture_notexist;
sf::Texture texture_nothing;
// beckgroundFields
sf::Texture Background;
// menu (+ sprite'y)
sf::Texture menu;
sf::Texture save;
    sf::Sprite Menu;
    sf::Sprite Save;
// font
sf::Font font;
// kursor (+sprite)
sf::Texture kursor;
    sf::Sprite Kursor;




void loadFiguresTexture(){
    if (!texture_pawn.loadFromFile("img/pawn.png"))
    {
        ms_error(666, "img/pawn.png", 1);
    }
    if (!texture_ghost.loadFromFile("img/ghost.png"))
    {
        ms_error(666, "img/ghost.png", 1);
    }
    if (!texture_cav.loadFromFile("img/cav.png"))
    {
        ms_error(666, "img/cav.png", 1);
    }
    if (!texture_king.loadFromFile("img/king.png"))
    {
        ms_error(666, "img/king.png", 1);
    }
    if (!texture_tower.loadFromFile("img/tower.png"))
    {
        ms_error(666, "img/tower.png", 1);
    }
    if (!texture_charge.loadFromFile("img/charge.png"))
    {
        ms_error(666, "img/charge.png", 1);
    }
    if (!texture_mystery.loadFromFile("img/mystery.png"))
    {
        ms_error(666, "img/mystery.png", 1);
    }
    if (!texture_notexist.loadFromFile("img/notexist.png"))
    {
        ms_error(666, "img/notexist.png", 1);
    }
    if (!texture_nothing.loadFromFile("img/nothing.png"))
    {
        ms_error(666, "img/nothing.png", 1);
    }
    if (!Background.loadFromFile("img/dupa.png"))
    {
        ms_error(666, "img/dupa.png", 1);
    }
}

void loadMenuTexture(){
    if (!menu.loadFromFile("img/menu.png"))
    {
        ms_error(666, "img/menu.png", 1);
    }
    if (!save.loadFromFile("img/save.png"))
    {
        ms_error(666, "img/save.png", 1);
    }
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        ms_error(666, "fonts/arial.ttf", 1);
    }
    if (!kursor.loadFromFile("img/kursor.png"))
    {
        ms_error(666, "img/kursor.png", 1);
    }

    //ustawianie tekstur dla menu itp.
    Menu.setTexture(menu);
    Menu.setPosition(sf::Vector2f(0, 0));
    Menu.setScale(sf::Vector2f(1, 1));

    Save.setTexture(save);
    Save.setPosition(sf::Vector2f(0, 0));
    Save.setScale(sf::Vector2f(1, 1));

    Kursor.setTexture(kursor);
    Kursor.setScale(0.1f, 0.1f);
}

void setFigureTexture(Pole *field){
    if(field->name == "pawn")
    {
        field->setTexture(texture_pawn);
    }
    else if(field->name == "tower")
    {
        field->setTexture(texture_tower);
    }
    else if(field->name == "ghost")
    {
        field->setTexture(texture_ghost);
    }
    else if(field->name == "cav")
    {
        field->setTexture(texture_cav);
    }
    else if(field->name == "king")
    {
        field->setTexture(texture_king);
    }
    else if(field->name == "mystery")
    {
        field->setTexture(texture_mystery);
    }
    else if(field->name == "charge")
    {
        field->setTexture(texture_charge);
    }
    else if(field->name == "notexist")
    {
        field->setTexture(texture_notexist);
    }
    else if(field->name == "empty")
    {
        field->setTexture(texture_nothing);
    }
}

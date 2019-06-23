#include "pole.h"

//-------------------------------Deklaracja tekstur-----------------------------------------------
// frontFields
sf::Texture texture_pawnU;
sf::Texture texture_ghostU;
sf::Texture texture_cavU;
sf::Texture texture_kingU;
sf::Texture texture_towerU;
sf::Texture texture_chargeU;
sf::Texture texture_mysteryU;
sf::Texture texture_pawnD;
sf::Texture texture_ghostD;
sf::Texture texture_cavD;
sf::Texture texture_kingD;
sf::Texture texture_towerD;
sf::Texture texture_chargeD;
sf::Texture texture_mysteryD;
sf::Texture texture_notexist;
sf::Texture texture_nothing;

// beckgroundFields
sf::Texture Background;
sf::Texture Background2;
sf::Texture Background3;
sf::Texture BackgroundBroken;
sf::Texture BackgroundBroken2;
sf::Texture BackgroundBroken3;
// menu (+ sprite'y)
sf::Texture firstMenuTexture;
sf::Texture menu;
sf::Texture save;
sf::Sprite firstMenuSprite;
sf::Sprite Menu;
sf::Sprite Save;
sf::Sprite WinTexture;
// font
sf::Font font;
// kursor (+sprite)
sf::Texture kursor;
sf::Sprite Kursor;
sf::Texture backroundImage;



void loadFiguresTexture(){
    if (!texture_pawnU.loadFromFile("graphics/ikony/peasantRed.png"))
    {
        ms_error(666, "graphics/ikony/peasantRed.png", 1);
    }
    if (!texture_ghostU.loadFromFile("graphics/ikony/ghostRed.png"))
    {
        ms_error(666, "graphics/ikony/ghostRed.png", 1);
    }
    if (!texture_cavU.loadFromFile("graphics/ikony/kawaleriaRed.png"))
    {
        ms_error(666, "graphics/ikony/kawaleriaRed.png", 1);
    }
    if (!texture_kingU.loadFromFile("graphics/ikony/kroolRed.png"))
    {
        ms_error(666, "graphics/ikony/kroolRed.png", 1);
    }
    if (!texture_towerU.loadFromFile("graphics/ikony/towerRed.png"))
    {
        ms_error(666, "graphics/ikony/towerRed.png", 1);
    }
    if (!texture_chargeU.loadFromFile("graphics/ikony/nosekred^^.png"))
    {
        ms_error(666, "graphics/ikony/nosekred^^.png", 1);
    }
    if (!texture_mysteryU.loadFromFile("graphics/ikony/zagadkaRed.png"))
    {
        ms_error(666, "graphics/ikony/zagadkaRed.png", 1);
    }
    if (!texture_notexist.loadFromFile("img/notexist.png"))
    {
        ms_error(666, "img/notexist.png", 1);
    }
    if (!texture_nothing.loadFromFile("img/nothing.png"))
    {
        ms_error(666, "img/nothing.png", 1);
    }
    if (!texture_pawnD.loadFromFile("graphics/ikony/peasantBlue.png"))
    {
        ms_error(666, "graphics/ikony/peasantBlue.png", 1);
    }
    if (!texture_ghostD.loadFromFile("graphics/ikony/ghostBlue.png"))
    {
        ms_error(666, "graphics/ikony/ghostBlue.png", 1);
    }
    if (!texture_cavD.loadFromFile("graphics/ikony/kawaleriaBlue.png"))
    {
        ms_error(666, "graphics/ikony/kawaleriaBlue.png", 1);
    }
    if (!texture_kingD.loadFromFile("graphics/ikony/kroolBlue.png"))
    {
        ms_error(666, "graphics/ikony/kroolBlue.png", 1);
    }
    if (!texture_towerD.loadFromFile("graphics/ikony/towerBlue.png"))
    {
        ms_error(666, "graphics/ikony/towerBlue.png", 1);
    }
    if (!texture_chargeD.loadFromFile("graphics/ikony/nosekblue^^.png"))
    {
        ms_error(666, "graphics/ikony/nosekblue^^.png", 1);
    }
    if (!texture_mysteryD.loadFromFile("graphics/ikony/zagadkaBlue.png"))
    {
        ms_error(666, "graphics/ikony/zagadkaRed.png", 1);
    }
    if (!Background.loadFromFile("graphics/stones/stone3.0.png"))

    {
        ms_error(666, "graphics/stones/stone3.0.png", 1);
    }
    if (!BackgroundBroken.loadFromFile("graphics/stones/stone3.1.png"))
    {
        ms_error(666, "graphics/stones/stone3.1.png", 1);
    }
    if (!Background2.loadFromFile("graphics/stones/stone2.0.png"))

    {
        ms_error(666, "graphics/stones/stone2.0.png", 1);
    }
    if (!BackgroundBroken2.loadFromFile("graphics/stones/stone2.1.png"))
    {
        ms_error(666, "graphics/stones/stone2.1.png", 1);
    }
    if (!Background3.loadFromFile("graphics/stones/stone1.0.png"))

    {
        ms_error(666, "graphics/stones/stone1.0.png", 1);
    }
    if (!BackgroundBroken3.loadFromFile("graphics/stones/stone1.1.png"))
    {
        ms_error(666, "graphics/stones/stone1.1.png", 1);
    }
}

void loadMenuTexture(){
    if (!firstMenuTexture.loadFromFile("graphics/menu/menu2PlusSub.png"))
    {
        ms_error(666, "graphics/menu/menu2PlusSub.png", 1);
    }
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
    if (!kursor.loadFromFile("graphics/rzeczy/kursorDuzy.png"))
    {
        ms_error(666, "graphics/rzeczy/kursorDuzy.png", 1);
    }
    if(!backroundImage.loadFromFile("graphics/rzeczy/tloLight.jpg")){
        ms_error(666, "graphics/rzeczy/tloLight.jpg");
    }
    //ustawianie tekstur dla menu itp.
    Menu.setTexture(menu);
    Menu.setPosition(sf::Vector2f(0, 0));
    Menu.setScale(float(sf::VideoMode::getDesktopMode().width)/menu.getSize().x, float(sf::VideoMode::getDesktopMode().height)/menu.getSize().y);


    Save.setTexture(save);
    Save.setPosition(sf::Vector2f(0, 0));
    Save.setScale(float(sf::VideoMode::getDesktopMode().width)/save.getSize().x, float(sf::VideoMode::getDesktopMode().height)/save.getSize().y);

    firstMenuSprite.setTexture(firstMenuTexture);
    firstMenuSprite.setScale(float(sf::VideoMode::getDesktopMode().width)/firstMenuTexture.getSize().x, float(sf::VideoMode::getDesktopMode().height)/firstMenuTexture.getSize().y);

    Kursor.setTexture(kursor);
    Kursor.setScale(0.5f, 0.5f);
}

void setFigureTexture(Pole *field){
    if(field->name == "pawn")
    {
        if(field->owner==1)field->setTexture(texture_pawnD);
        else field->setTexture(texture_pawnU);
    }
    else if(field->name == "tower")
    {
        if(field->owner==1)field->setTexture(texture_towerD);
        else field->setTexture(texture_towerU);
    }
    else if(field->name == "ghost")
    {
        if(field->owner==1)field->setTexture(texture_ghostD);
        else field->setTexture(texture_ghostU);
    }
    else if(field->name == "cav")
    {
        if(field->owner==1)field->setTexture(texture_cavD);
        else field->setTexture(texture_cavU);
    }
    else if(field->name == "king")
    {
        if(field->owner==1)field->setTexture(texture_kingD);
        else field->setTexture(texture_kingU);
    }
    else if(field->name == "mystery")
    {
        if(field->owner==1)field->setTexture(texture_mysteryD);
        else field->setTexture(texture_mysteryU);
    }
    else if(field->name == "charge")
    {
        if(field->owner==1)field->setTexture(texture_chargeD);
        else field->setTexture(texture_chargeU);
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

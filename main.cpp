#define _WIN32_WINNT 0x0500

bool click=0;


#include <sstream>
#include "figures.h"
#include "header.h"
#include "fields.h"
#include <math.h>
#include "highlight.h"
#include "AI.h"

bool ai=0;


void setup(){
    loadFiguresTexture();
    loadSettings();
    loadMenuTexture();
    backgroundFields();
    LoadSave(saveChosing(), front_fields);
    frontFields();
}

int main()
{
    srand(time(NULL));
    //sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    window.setMouseCursorVisible(false);
    sf::Clock minutes;
    sf::Clock seconds;
    sf::Music music;

    if (!music.openFromFile("sounds/music.wav"))ms_error(24, "nie zaladowano music.wav");
    music.setVolume(10.f);

    music.play();
    music.setLoop(true);
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sounds/sound.wav"))
        ms_error(22, "nie zaladowano dzwieku");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(150.f);




//=================================T£O================================================//



    if(sf::VideoMode::getDesktopMode().width>sf::VideoMode::getDesktopMode().height){
        scale=0.35*sf::VideoMode::getDesktopMode().height/1080; //uzależnic od sizePlanszyPrzed
        posuniecieX=0;
        posuniecieY=0;//paweł da rade!
    }else{
        scale=0.397*sf::VideoMode::getDesktopMode().width/1080; //uzależnić od size planszzyPrzed
        posuniecieX=0;
        posuniecieY=0;
    }



    if(nrTura==1){
        background_fields[baseX][baseY].setPosition(1000,1000);
        front_fields[baseX*34+baseY].name="notexist";
        front_fields[baseX*34+baseY].owner=0;
        baseX+=1;
        baseY-=1;
        basex-=1;
        basey+=1;
    }
setup();
    for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                background_fields[i][j].setScale(scale, scale);
                sf::Color a= background_fields[i][j].getColor();
                if(front_fields[i*34+j].name!="notexist"){
                    if(a!=sf::Color::Cyan)background_fields[i][j].setTexture(Background);
                }
                else background_fields[i][j].setTexture(texture_notexist);
            }
        }

    float skalaX = float(sf::VideoMode::getDesktopMode().width)/backroundImage.getSize().x;
    float skalaY = float(sf::VideoMode::getDesktopMode().height)/backroundImage.getSize().y;

    int czteresci =texture_kingD.getSize().x*scale;
    int dwajscia = czteresci/2;



    sf::Sprite SbackroundImage;
    SbackroundImage.setTexture(backroundImage);
    if(sf::VideoMode::getDesktopMode().width>sf::VideoMode::getDesktopMode().height){
        SbackroundImage.setScale(skalaX, skalaX);
        SbackroundImage.setPosition(0, float(-(backroundImage.getSize().y*skalaX - sf::VideoMode::getDesktopMode().height)/2));
    }else{
        SbackroundImage.setScale(skalaY, skalaY);
        SbackroundImage.setPosition((float(sf::VideoMode::getDesktopMode().width)-backroundImage.getSize().x*skalaY)/2 ,0);
    }



    while (window.isOpen())
    {


        Kursor.setTexture(kursor);
        mousePointing = 0;
        mouse_pressed = 0;
        window.draw(SbackroundImage);
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:

                    window.close();
                    music.stop();
                    return 0;
                    break;
                case sf::Event::Resized:
                    //ResizeView(window, view);
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape&&isMenu)isMenu=0;
                    else if(event.key.code == sf::Keyboard::Escape&&isSaving){
                        isMenu=1;
                        isSaving=0;
                    }else if(event.key.code == sf::Keyboard::Escape)isMenu=1;
                    else if(event.key.code == sf::Keyboard::S&&isSaving){
                        isMenu=1;
                        isSaving=0;
                    }else if(event.key.code == sf::Keyboard::S&&!isSaving){
                        isSaving=1;
                        isMenu=0;
                    }
                break;
            }

        }

        //consoleHiding();


//=========================Znikanie mapy=====================================//

        if(oldTura+coIleTurMaSieZapadac<=nrTura){

            background_fields[baseX][baseY].setPosition(1000,1000);
            front_fields[baseX*34+baseY].name="notexist";
            window.draw(front_fields[baseX*34+baseY]);
            front_fields[baseX*34+baseY].owner=0;
            front_fields[baseX*34+baseY].setTexture(texture_notexist);
            background_fields[basex][basey].setPosition(1000,1000);
            front_fields[basex*34+basey].name="notexist";
            window.draw(front_fields[basex*34+basey]);
            front_fields[basex*34+basey].owner=0;
            front_fields[basex*34+basey].setTexture(texture_notexist);
            algorytmBase();



            oldTura=nrTura;

            nrZmiany++;

        }

        mouse_position = sf::Mouse::getPosition(window);
        if(!isMenu&!isSaving){
            for(int i = 0; i < 17; i ++)
            {
                for(int j = 0; j < 34; j ++)
                {
                    if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < dwajscia*dwajscia)
                    {
                        if(!click){
                                if(front_fields[i*34+j].owner==1)background_fields[i][j].setColor(sf::Color(175,210,255,150));
                                else if (front_fields[i*34+j].owner==2) background_fields[i][j].setColor(sf::Color(255,220,175,140));
                                else background_fields[i][j].setColor(sf::Color(255,255,255,220));
                        }else{

                            if(front_fields[i*34+j].owner==opponentOwner){
                               if (!kursor.loadFromFile("graphics/rzeczy/kursorKlik.png"))ms_error(216, "no kursor found", 1);
                            }else{
                                if (!kursor.loadFromFile("graphics/rzeczy/kursorDuzy.png"))
                                    {
                                    ms_error(26, "no kursor found", 1);
                                    }
                            }


                        }
                    }
                    else if((front_fields[i * board_size_y + j].name != "empty"))
                    {
                        if(front_fields[i * board_size_y + j].owner == 1)
                        {
                            if(!click)background_fields[i][j].setColor(bColor);
                        }
                        else if(front_fields[i * board_size_y + j].owner == 2)
                        {
                            if(!click){
                                    background_fields[i][j].setColor(yColor);
                            }
                        }else if(front_fields[i * board_size_y + j].name == "notexist"){
                            if(!click)background_fields[i][j].setTexture(texture_notexist);
                        }

                    }else if(!click){
                        sf::Color a= background_fields[i][j].getColor();
                        if(a!=sf::Color::Cyan)background_fields[i][j].setColor(sf::Color(200, 200, 200));



                    background_fields[baseX][baseY].setTexture(BackgroundBroken);
                    background_fields[basex][basey].setTexture(BackgroundBroken);

                    }
                }
            }
            while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mouse_position = sf::Mouse::getPosition(window);
                mouse_pressed = 1;
            }

            if((actual_mode == "play") && (mouse_pressed||(ai&&tura==1)))
            {
                if(!ai||tura==2){
                    if((figure_x == 0) && (figure_y == 0))
                    {
                        for(int i = 0; i < 17; i ++)
                        {
                            for(int j = 0; j < 34; j ++)
                            {
                                if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < pow(dwajscia,2))
                                {
                                    figure_x = i;
                                    figure_y = j;
                                    front_fields[i*34+j].owner==1?background_fields[i][j].setColor(sf::Color(175,210,255,150)):background_fields[i][j].setColor(sf::Color(255,220,175,140));
                                    if((front_fields[figure_x * 34 + figure_y].name == "empty"))
                                    {
                                        figure_x = 0;
                                        figure_y = 0;
                                    }else if(front_fields[figure_x*34+figure_y].owner==tura){
                                        click=1;

                                        mouse_position = sf::Mouse::getPosition(window);
                                        (front_fields[figure_x* 34 + figure_y].owner == 1)?opponentOwner = 2:opponentOwner = 1;
                                        //=======================================[highLight]================================
                                        if(!highlight(figure_x, figure_y))ms_error(279, "cos poszlo nie tak z highlightem");
                                        //========================================highlight=========================================================
                                    }
                                    else{
                                        figure_x=0;
                                        figure_y=0;
                                    }
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
                                if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < pow(dwajscia,2))
                                {

                                    target_x = i;
                                    target_y = j;
                                    if(front_fields[34*figure_x+figure_y].owner == tura)
                                    {
                                        if(action(front_fields, figure_x, figure_y, target_x, target_y))
                                        {

                                            if(tura == 1) tura = 2;
                                            else tura = 1;
                                            nrTura++;
                                            sound.play();
                                            click=0;

                                            front_fields[target_x*34+target_y].setTexture(*front_fields[figure_x*34+figure_y].getTexture());
                                            front_fields[figure_x*34+figure_y].setTexture(texture_nothing);

                                            window.draw(front_fields[target_x*34+target_y]);
                                            window.draw(front_fields[figure_x*34+figure_y]);
                                            for(int i = 0; i < 17; i++){

                                                for (int j = 0; j< 34; j++){
                                                    frontFields();
                                                    window.draw(front_fields[i*34+j]);
                                                    window.draw(front_fields[i*34+j]);

                                                }
                                            }


                                            if (!kursor.loadFromFile("graphics/rzeczy/kursorDuzy.png"))
                                            {
                                                ms_error(26, "graphics/rzeczy/kursorDuzy.png", 1);
                                            }
                                        }
                                    }
                                    else ms_message("to nie twoja tura dzbanie");
                                    figure_x = 0;
                                    figure_y = 0;
                                }
                            }
                        }
                    }
                }else if(!win){
                    if(!AI(front_fields));
                    std::cout<<"doszlem\n";
                    if(!action(front_fields, aiFX, aiFY, aiTX, aiTY));
                    mouse_pressed=0;
                    if(tura == 1) tura = 2;
                    else tura = 1;
                    nrTura++;
                    sound.play();
                    click=0;
                }
            }
        }

        //=======================Plansza menu==========================//
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))clickInSaving=0;

        if(isMenu&&!clickInSaving){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>110&&mouse_position.y<180){
                    isMenu=0;
                    sound.play();
                }else if(mouse_position.x>=230&mouse_position.x<=510&&mouse_position.y>215&&mouse_position.y<290){
                    sound.play();
                    isMenu=0;
                    isSaving=1;
                    clickInMenu=1;
                }else if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>320&&mouse_position.y<380){  //działa tylko z execa (wraca do menu){
                    sound.play();
                    window.close();
                    music.stop();
                    //system("./araMenu/sfml-app.o");  //działa tylko z execa (wraca do menu
                    system("ara.exe");  //działa tylko z execa (wraca do menu
                    return 0;
                }else if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>430&&mouse_position.y<490){
                    sound.play();
                    music.stop();

                    window.close();
                    return 0;
                }
            }
        }
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))clickInMenu=0;

        if(isSaving&&!clickInMenu){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>50&&mouse_position.y<120){
                    SaveGame(1, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                else if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>150&&mouse_position.y<230){
                    SaveGame(2, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                else if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>270&&mouse_position.y<360){
                    SaveGame(3, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>380&&mouse_position.y<450){
                    SaveGame(4, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>480&&mouse_position.y<560){
                    SaveGame(5, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
            }
        }




            for (int i = 0; i<17; ++i)
            {
                for (int j = 0; j<33; ++j)
                {
                    window.draw(background_fields[i][j]);
                    window.draw(front_fields[i * board_size_y + j]);
                }
            }
            sf::Texture winTexture;
            // !!!!!!!!!!!!!!!!!Napisac ekran wygranej !!!!!!!!!!!!!!!!!!//
            if(win){

                if(tura==1){
                    if (!winTexture.loadFromFile("img/winDolny.png"))
                    {
                    ms_error(230, "main.cpp no file winDolny.png, 1");
                    }
                }else{
                    if (!winTexture.loadFromFile("img/winGorny.png"))
                    {
                        ms_error(230, "main.cpp no file winGorny.png", true);
                    }

                }
                WinTexture.setTexture(winTexture);
                WinTexture.setPosition(sf::Vector2f(0,0));
                WinTexture.setScale(float(sf::VideoMode::getDesktopMode().width)/winTexture.getSize().x, float(sf::VideoMode::getDesktopMode().height)/winTexture.getSize().y);
            }

            unsigned int time;
            unsigned int minute;

            if(!isMenu){
                time = seconds.getElapsedTime().asSeconds();
                minute = minutes.getElapsedTime().asSeconds()/60;
            }
        std::ostringstream ss;
        ss.clear();
        (time<10)?ss << "Czas: " <<minute<<":0"<<time:ss << "Czas: " <<minute<<":"<<time;


        sf::Text clock;
        clock.setPosition(sf::Vector2f(1625, 325));
        clock.setFont(font);
        clock.setCharacterSize(20);
        clock.setStyle(sf::Text::Regular);
        clock.setString(ss.str());

        std::ostringstream ss1;
        if(tura==2)ss1<<" Tura: "<<nrTura<<std::endl<<"Gracz: Dolny";
        else ss1<<" Tura: "<<nrTura<<std::endl<<"Gracz: Gorny";

        sf::Text turn;
        turn.setPosition(sf::Vector2f(1635, 275));
        turn.setFont(font);
        turn.setCharacterSize(20);
        turn.setStyle(sf::Text::Regular);
        turn.setString(ss1.str());

         if(int(time)>59)
        {
            seconds.restart();
        }
        if(minute!=0&&minute%3==0)music.play();
        //window.draw(klik);
        window.draw(clock);
        window.draw(turn);
        window.draw(WinTexture);
        //view.setCenter(sf::Vector2f(360.0f, 360.0f));
        //window.setView(view);
        if(isMenu)window.draw(Menu);
        if(isSaving)window.draw(Save);
        Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(Kursor);
        //std::cout<<Kursor.getPosition().x<<"x"<<Kursor.getPosition().y<<"\n";
        window.display();
        window.clear();

        if(win==1){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)||sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    music.stop();
                    window.close();
                    system("ara.exe");  //działa tylko z execa (wraca do menu
                    //system("./araMenu/sfml-app.o");  //działa tylko z execa (wraca do menu)
                }
        }


    }

    return 0;
}

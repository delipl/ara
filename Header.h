    #include <math.h>

    #define board_size_y 34

    sf::Texture texture_pawn;
    sf::Texture texture_ghost;
    sf::Texture texture_cav;
    sf::Texture texture_king;
    sf::Texture texture_tower;
    sf::Texture texture_charge;
    sf::Texture texture_mystery;
    sf::Texture texture_notexist;
    sf::Texture texture_nothing;
    sf::Texture menu;

    sf::Sprite Menu;

    Pole background_fields[17][34];
    Pole *front_fields;

    static const float VIEW_HEIGHT = 720.0f;

    HWND hWnd = GetConsoleWindow();

    int figure_x = 0;
    int figure_y = 0;
    int target_x = 0;
    int target_y = 0;

    std::string actual_mode = "play"; //aktualny tryb dzialania myszki: "play", "edit"

    sf::Vector2i mouse_position;
    bool mouse_pressed = 0;

    std::string actual_name = "pawn";
    int actual_owner = 0;

    int tura =2;
    int oldTura =2;
    int nrZmiany=1;
    int nrZmiany2=1;
    int baseX=8;
    int baseY=16;

    int basex=8;
    int basey=16;

    bool isMenu=0;

void algorytmBase(){
    if(nrZmiany%(3*nrZmiany2)==0){
        baseX=baseX+3*nrZmiany2;
        basex=basex-3*nrZmiany2;
        baseY+=1;
        basey-=1;
        nrZmiany2++;
        nrZmiany=1;
    }else{
        if(nrZmiany==1){
            baseX-=1;
            baseY-=1;
            basex+=1;
            basey+=1;
        }else if(nrZmiany==2){
            baseX-=1;
            baseY+=1;
            basex+=1;
            basey-=1;
        }
    }
}


void loadTexture(){


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

            if (!menu.loadFromFile("img\\menu.png"))
            {
                ms_error(220, "nie zaladowano menu.png", true);
            }

            Menu.setTexture(menu);
            Menu.setPosition(sf::Vector2f(0, 0));
            Menu.setScale(sf::Vector2f(1, 1));

}

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x/ float(window.getSize().y));
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}


void consoleHiding(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            ShowWindow( hWnd, SW_HIDE );
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            ShowWindow( hWnd, SW_SHOW );
        }
}



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

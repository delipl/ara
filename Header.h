    #include <math.h>
    #include <windows.h>

    #define board_size_y 34
    #define coIleTurMaSieZapadac 5

    Pole background_fields[17][34];
    Pole *front_fields;

    static const float VIEW_HEIGHT = 1000.0f;

    //HWND hWnd = GetConsoleWindow();

    int figure_x = 0;
    int figure_y = 0;
    int target_x = 0;
    int target_y = 0;

    std::string actual_mode = "play"; //aktualny tryb dzialania myszki: "play", "edit"

    sf::Vector2i mouse_position;
    bool mouse_pressed = 0;

    std::string actual_name = "pawn";
    int actual_owner = 0;

    sf::SoundBuffer buffer;
    sf::Sound sound;


    bool isMenu=0;
    bool isSaving=0;
    int opponentOwner;

    //======do AI========\\

    int aiFX;
    int aiFY;
    int aiTX;
    int aiTY;

    //==================\\

    sf::RenderWindow window(sf::VideoMode(VIEW_HEIGHT, VIEW_HEIGHT), "A.R.A.");
    sf::Sprite Kursor;



void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x/ float(window.getSize().y));
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}


/*
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
*/


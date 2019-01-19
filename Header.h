    #include "Load_Textures.h"
	#include <math.h>

    #define board_size_y 34

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

    int tura = 1;
	

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x/ float(window.getSize().y));
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}


void consoleHiding()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		ShowWindow( hWnd, SW_HIDE );
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		ShowWindow( hWnd, SW_SHOW );
	}
}

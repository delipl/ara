// ###Te biblioteki trzeb bedzie dolaczyc do ostatecznej wersji
#include "pole.h"
#include <fstream>
#include <cstdlib>
#include <string>
// ###

void LoadSave(int save_number, Pole *fields)
{
    int board_size_y = 34;

    /*
    sf::Texture texture_pawn;
    sf::Texture texture_ghost;
    sf::Texture texture_cav;
    sf::Texture texture_king;
    sf::Texture texture_tower;
    sf::Texture texture_charge;
    sf::Texture texture_mystery;
    sf::Texture texture_notexist;
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
    */

    //Mam wszystkie textury

    std::fstream file;  // plik
    std::string line;

    if(save_number == 0)
    {
        file.open("Saves/save0.txt", std::ios::in);
    }
    else if(save_number == 1)
    {
        file.open("Saves/save1.txt", std::ios::in);
    }
    else if(save_number == 2)
    {
        file.open("Saves/save2.txt", std::ios::in);
    }// ###W przypadku, gdy bedzie potrzebne wiecej zapisow, tu trzeba dodac odpowiednie elseif'y

    if(file.good() == false)
    {
        // ###Tu musi sie znalezc odpowiednie powiadomienie o tym, ze wystapil problem z plikiem
        std::cout<<"cos jest nie tak z plikiem"<<"\n";
        // ###
    }

    int length;

    std::string figure_name;
    int figure_x;
    int figure_y;
    int figure_owner;
    int j;

    // ###To jest pierwsza linia, trzeba ustawic aktualnego gracza
    getline(file, line);
    int actual_player = int(line[0]) - int('0');
    std::cout<<actual_player<<"\n";
    // ###

    while(getline(file, line))
    {
        length = line.length();

        figure_name = "";
        figure_x = 0;
        figure_y = 0;
        figure_owner = 0;

        j = 0;
        while((line[j] != ';') && (j < length))
        {
            figure_name += line[j];
            j++;
        }
        j++;
        while((line[j] != ';') && (j < length))
        {
            figure_x = figure_x * 10 + int(line[j]) - int('0');
            j++;
        }
        j++;
        while((line[j] != ';') && (j < length))
        {
            figure_y = figure_y * 10 + int(line[j]) - int('0');
            j++;
        }
        j++;
        figure_owner = int(line[j]) - int('0');

        fields[figure_x * board_size_y + figure_y].owner = figure_owner;  // stawiam pionka
        fields[figure_x * board_size_y + figure_y].name = figure_name;    // stawiam pionka


        /*
        if(fields[figure_x * board_size_y + figure_y].name == "pawn")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_pawn);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "tower")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_tower);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "ghost")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_ghost);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "cav")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_cav);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "king")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_king);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "mystery")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_mystery);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "charge")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_charge);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "notexist")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_notexist);
        }
        fields[figure_x * board_size_y + figure_y].setScale(sf::Vector2f(0.2f, 0.2f));
        */

        // Mam textury i pozycje i skale
    }
    //std::cout<<"jest ok!\n";

    file.close();
}

void SaveGame(int save_number, Pole *fields)
{
    int board_size_y = 34;

    std::fstream file;  // plik

    if(save_number == 0)
    {
        file.open("Saves/save0.txt", std::ios::out);
    }
    else if(save_number == 1)
    {
        file.open("Saves/save1.txt", std::ios::out);
    }
    else if(save_number == 2)
    {
        file.open("Saves/save2.txt", std::ios::out);
    }// ###W przypadku, gdy bedzie potrzebne wiecej zapisow, tu trzeba dodac odpowiednie elseif'y

    // ###Tu trzeba dodac aktualnego gracza
    file<<"0\n";
    // ###

    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            if(fields[i * board_size_y + j].name == "empty")
            {
                continue;
            }
            else
            {
                file<<fields[i * board_size_y + j].name<<";"<<i<<";"<<j<<";"<<fields[i * board_size_y + j].owner<<"\n";
            }
        }
    }

    file.close();
}

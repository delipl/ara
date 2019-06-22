// ###Te biblioteki trzeb bedzie dolaczyc do ostatecznej wersji
#include "textures.h"
#include <fstream>
#include <cstdlib>
#include <string>
// ###
float scale=0;

    //loadSettings
    int fieldSizeX = 0;
    int fieldSizeY = 0;
    float fieldScaleX = 0;
    float fieldScaleY = 0;
    int soundVolume = 0;
    int musicVolume = 0;
    int difficultyAI = 0;
    int turaLength = 0;

    #define coIleTurMaSieZapadac 2
    int tura;
    int nrTura=1;
    int oldTura =1;
    int nrZmiany=1;
    int nrZmiany2=1;
    int baseX=8;
    int baseY=16;
    int basex=8;
    int basey=16;

    #include "mapRemoving.h"

int saveChosing(){
    std::fstream file;  // plik
    std::string line;

    file.open("Saves/a.txt");
    getline(file, line);
    int returning = int(line[0])-('0');
    file.close();
    return returning;

}

int loadSettings(){
    std::fstream file;  // plik
    std::string line;

    file.open("settings.txt", std::ios::in);
    getline(file, line);
    int length = line.length();

    int i = 0;
    while((length > i) && (line[i] != ';'))
    {
        fieldSizeX = fieldSizeX * 10 + int(line[i]) - int('0');
        i++;
    }
    i++;
    while((length > i) && (line[i] != ';'))
    {
        fieldSizeY = fieldSizeY * 10 + int(line[i]) - int('0');
        i++;
    }
    i++;
    while((length > i) && (line[i] != ';'))
    {
        soundVolume = soundVolume * 10 + int(line[i]) - int('0');
        i++;
    }
    i++;
    while((length > i) && (line[i] != ';'))
    {
        musicVolume = musicVolume * 10 + int(line[i]) - int('0');
        i++;
    }
    i++;
    while((length > i) && (line[i] != ';'))
    {
        difficultyAI = difficultyAI * 10 + int(line[i]) - int('0');
        i++;
    }
    i++;
    while((length > i) && (line[i] != ';'))
    {
        turaLength = turaLength * 10 + int(line[i]) - int('0');
        i++;
    }

    if((fieldSizeX < 1) || (fieldSizeY < 1) || (soundVolume < 0) || (soundVolume > 100) || (musicVolume < 0) || (musicVolume > 100) || (difficultyAI < 0) || (turaLength < 0))
    {
        ms_error(82, "loadSettings -> kupa", 1);
        file.close();
        return 0;
    }
    fieldScaleX = Background.getSize().x / fieldSizeX;
    fieldScaleY = Background.getSize().y / fieldSizeY;

    file.close();
    return 0;
}

int LoadSave(int save_number, Pole *fields) //0 -> dobrze, 1 -> cos sie powaznie zepsulo, 2 -> lekki blad
{
    int board_size_y = 34;
    std::string names[8] = {"pawn", "ghost", "tower", "cav", "mystery", "charge", "king", "notexist"};
    int returning = 0;

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
    }
    else if(save_number == 3)
    {
        file.open("Saves/save3.txt", std::ios::in);
    }
    else if(save_number == 4)
    {
        file.open("Saves/save4.txt", std::ios::in);
    }
    else if(save_number == 5)
    {
        file.open("Saves/save5.txt", std::ios::in);
    }// ###W przypadku, gdy bedzie potrzebne wiecej zapisow, tu trzeba dodac odpowiednie elseif'y

    if(file.good() == false)
    {
        ms_error(84, "Load_From_File/LoadSave/file.good() == false", 1);
        file.close();
        return 1;
    }

    int length;

    std::string figure_name;
    int figure_x;
    int figure_y;
    int figure_owner;
    int j;

    // ###To jest pierwsza linia, trzeba ustawic aktualnego gracza
    getline(file, line);
    if(line.length() == 0)
    {
        ms_error(101, "Load_From_File/LoadSave/file is broken!!!", 1);
        file.close();
        return 1;
    }

    nrTura = 0;

    for(int i = 0; i < line.length(); i ++)
    {
        nrTura = nrTura * 10 + int(line[i]) - int('0');
    }
    tura = nrTura % 2+1;
    //std::cout<<nrTura<<"\n";

    for(int i = 1; i < nrTura; i ++)
    {
        if(i==1){
            fields[baseX*34+baseY].name="notexist";
            fields[baseX*34+baseY].owner=0;
            baseX+=1;
            baseY-=1;
            basex-=1;
            basey+=1;
        }
        if(oldTura+coIleTurMaSieZapadac<=i){
            //std::cout<<nrZmiany<<"\n";
            //std::cout<<nrZmiany2<<"\n";

            //background_fields[baseX][baseY].setPosition(1000,1000);
            fields[baseX*34+baseY].name="notexist";
            fields[baseX*34+baseY].owner=0;
            //background_fields[basex][basey].setPosition(1000,1000);
            fields[basex*34+basey].name="notexist";
            fields[basex*34+basey].owner=0;
            algorytmBase();



            oldTura=i;

            nrZmiany++;
            //std::cout<<nrZmiany-2<<std::endl;

        }
    }

    // ###tu nie dzia³a zapisywanie tury

    bool good = 0;
    int i = 0;

    while(getline(file, line))
    {
        i++;
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

        // Sprawdzanie, czy w pliku sa dobre dane

        good = 0;
        for(int i = 0; i < 8; i ++)
        {
            if(figure_name == names[i])
            {
                good = 1;
                break;
            }
        }
        if((figure_x < 0) || (figure_x > 16) || (figure_y < 0) || (figure_y > 33))
        {
            good = 0;
        }

        if(!good)
        {
            char *intStr = itoa(i, intStr, 3);
            std::string str = std::string(intStr);
            std::string text = "Load_From_File/LoadSave/something wrong with " + str + " line of file";
            ms_error(164, text);
            returning = 2;
        }
        else
        {
            fields[figure_x * board_size_y + figure_y].owner = figure_owner;  // stawiam pionka
            fields[figure_x * board_size_y + figure_y].name = figure_name;    // stawiam pionka
            setFigureTexture(&fields[figure_x * board_size_y + figure_y]);
            fields[figure_x * board_size_y + figure_y].setScale(sf::Vector2f(scale, scale));
        }
    }

    file.close();
    return returning;
}

int SaveGame(int save_number, Pole *fields) //0 -> dobrze, 1 -> cos sie powaznie zepsulo, 2 -> lekki blad
{
    int board_size_y = 34;
    int returning = 0;

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
    }else if(save_number == 3)
    {
        file.open("Saves/save3.txt", std::ios::out);
    }else if(save_number == 4)
    {
        file.open("Saves/save4.txt", std::ios::out);
    }else if(save_number == 5)
    {
        file.open("Saves/save5.txt", std::ios::out);
    }// ###W przypadku, gdy bedzie potrzebne wiecej zapisow, tu trzeba dodac odpowiednie elseif'y
    file<<nrTura<<"\n";

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
    return 0;
}

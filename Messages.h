#include <iostream>
#include <windows.h>

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);



void ms_error(int number, std::string description, bool pause = 0)
{
 // font is a sf::Font

    SetConsoleTextAttribute(hOut, FOREGROUND_RED);
    std::cout<<"ERROR: "<<number<<"\n";
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
    std::cout<<description<<"\n";




    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    if(pause)
    {
        system("PAUSE");
    }
}

void ms_message(std::string description, bool pause = 0)
{
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
    std::cout<<"MESSAGE:\n";
    std::cout<<description<<"\n";
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    if(pause)
    {
        system("PAUSE");
    }
}

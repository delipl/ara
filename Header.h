#include "lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#include "lib/SFML-2.5.1/include/SFML/Window.hpp"
#include <iostream>
//#include <Windows.h



class Pole:public sf::Sprite{
        public:
            std::string name;
            int owner;  //0-puste           1-gracz 1            2- gracz 2

    };

#include "Figures.h"

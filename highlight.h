/*
    Kawaleria       - cav
    Zagadka         - mystery

    pole przepaœci  - notexist
    pole puste      - empty
*/



bool highlight(int x, int y){
            //Pionek
            if (front_fields[x* 34 + y].name == "pawn"){
                for(int k = x-1; k <= x+1; k++){
                    for (int l = y-4; l<= y+4; l++){

                        if(CanMove(front_fields, x, y, k, l)
                        && front_fields[k* 34 + l].name == "empty")
                        background_fields[k][l].setColor(sf::Color::Green);
                         if(canAttack(front_fields, x, y, k, l)
                            && front_fields[34*figure_x+y].owner !=  front_fields[k * 34 + l].owner
                            && front_fields[k * 34 + l].owner != 0)
                            background_fields[k][l].setColor(sf::Color::Red);
                    }
                }
            }

            //duch
            else if(front_fields[x* 34 + y].name == "ghost"){
                for(int k = x-2; k < x+3; k++){
                    for (int l = y - 4; l< y+5; l++){  
                        if(CanMove(front_fields, x, y, k, l)
                        && front_fields[k* 34 + l].name == "empty")
                        background_fields[k][l].setColor(sf::Color::Green);
                        if(canAttack(front_fields, x, y, k, l)
                            && front_fields[34*figure_x+y].owner !=  front_fields[k * 34 + l].owner
                            && front_fields[k * 34 + l].owner != 0)
                            background_fields[k][l].setColor(sf::Color::Red);
                    }
                }
            }

            //krolik
            else if(front_fields[x* 34 + y].name == "king"){
                for(int k = x-1; k < x+1; k++){
                    for (int l = y-2; l < y+2; l++){
                        if(CanMove(front_fields, x, y, k, l)
                        && front_fields[k* 34 + l].name == "empty")
                        background_fields[k][l].setColor(sf::Color::Green);
                        if(canAttack(front_fields, x, y, k, l)
                            && front_fields[34*figure_x+y].owner !=  front_fields[k * 34 + l].owner
                            && front_fields[k * 34 + l].owner != 0)
                            background_fields[k][l].setColor(sf::Color::Red);
                    }
                }
            }

            //wieza
            else if(front_fields[x* 34 + y].name == "tower"){
                for(int k = x-4; k < x+4; k++){
                    for (int l = y-4; l < y+4; l++){
                        if(CanMove(front_fields, x, y, k, l)
                        && front_fields[k* 34 + l].name == "empty")
                        background_fields[k][l].setColor(sf::Color::Green);
                        if(canAttack(front_fields, x, y, k, l)
                            && front_fields[34*figure_x+y].owner !=  front_fields[k * 34 + l].owner
                            && front_fields[k * 34 + l].owner != 0)
                            background_fields[k][l].setColor(sf::Color::Red);
                    }
                }
            }

            //szarza
            else if(front_fields[x* 34 + y].name == "charge"){
                for(int k = x-2; k < x+2; k++){
                    for (int l = 0; l < 33; l++){
                        if(CanMove(front_fields, x, y, k, l)
                        && front_fields[k* 34 + l].name == "empty")
                        background_fields[k][l].setColor(sf::Color::Green);
                        if(canAttack(front_fields, x, y, k, l)
                            && front_fields[34*figure_x+y].owner !=  front_fields[k * 34 + l].owner
                            && front_fields[k * 34 + l].owner != 0)
                            background_fields[k][l].setColor(sf::Color::Red);
                    }
                }
            }


            //dla zagadki i kawalerii nie mam pomyslow
            else{// Tu dzia³a ale wolmo!!!!!!!!!!
                 for(int k = 0; k < 17; k++){
                    for (int l = 0; l< 34; l++){
                        //pokoloruj canMove na pustym polu
                        if(CanMove(front_fields, x, y, k, l)
                            && front_fields[k* 34 + l].name == "empty")
                            background_fields[k][l].setColor(sf::Color::Green);
                        //pokoloruj czerwonym na polu przeciwnika
                        if(canAttack(front_fields, x, y, k, l)
                            && front_fields[34*figure_x+y].owner !=  front_fields[k * 34 + l].owner
                            && front_fields[k * 34 + l].owner != 0)
                            background_fields[k][l].setColor(sf::Color::Red);

                    }
                }
            }
    return 1;
}

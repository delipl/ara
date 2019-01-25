/*
    Kawaleria       - cav
    Zagadka         - mystery

    pole przepaœci  - notexist
    pole puste      - empty
*/



bool highlight(int x, int y){
            //Pionek

            if (front_fields[x* 34 + y].name == "pawn"){
                std::cout<<x<<"x"<<y<<"\n";
                    for(int k = x-1; k <= x+1; k++){
                        for (int l = y-4; l<= y+4; l++){
                            if(k>-1&&k<17&&l>=0&&l<34){
                                if(((k%2==0&&l%2==0)||k%2==1&&l%2==1)&&front_fields[k*34+l].name!="notexist"){

                                        if(canAttack(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Red);
                                        else if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                                }
                            }
                        }
                    }
            } else if(front_fields[x* 34 + y].name == "ghost"){
                for(int k = x-2; k <= x+3; k++){
                    for (int l = y - 4; l<= y+5; l++){
                        if(k>-1&&k<17&&l>=0&&l<34){
                            if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                            if(canAttack(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Red);
                        }

                    }
                }
            }

            //krolik
            else if(front_fields[x* 34 + y].name == "king"){
                for(int k = x-1; k <= x+1; k++){
                    for (int l = y-2; l <= y+2; l++){
                        if(k>-1&&k<17&&l>=0&&l<34){
                            if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                            if(canAttack(front_fields, x, y, k, l)) background_fields[k][l].setColor(sf::Color::Red);
                        }
                    }
                }
            }

            //wieza
            else if(front_fields[x* 34 + y].name == "tower"){
                for(int k = x-4; k <= x+4; k++){
                    for (int l = y-4; l < y+4; l++){
                        if(k>-1&&k<17&&l>=0&&l<34){
                            if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                            if(canAttack(front_fields, x, y, k, l)) background_fields[k][l].setColor(sf::Color::Red);
                        }
                    }
                }
            }

            //szarza
            else if(front_fields[x* 34 + y].name == "charge"){
                for(int k = x-2; k <= x+2; k++){
                    for (int l = 0; l <= 33; l++){
                        if(k>-1&&k<17&&l>=0&&l<34){
                            if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                            if(canAttack(front_fields, x, y, k, l)) background_fields[k][l].setColor(sf::Color::Red);
                        }
                    }
                }
            }

            else{// Tu dzia³a ale wolmo!!!!!!!!!!
                 for(int k = 0; k < 17; k++){
                    for (int l = 0; l< 34; l++){
                        //pokoloruj canMove na pustym polu
                        if(((k%2==0&&l%2==0)||k%2==1&&l%2==1)&&front_fields[k*34+l].name!="notexist"){
                            if(canAttack(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                        }
                    }
                }
            }
    return 1;
}

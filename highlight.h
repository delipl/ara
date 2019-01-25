/*
    Kawaleria       - cav
    Zagadka         - mystery

    pole przepaœci  - notexist
    pole puste      - empty
*/



bool highlight(int x, int y){
            //Pionek

            if (front_fields[x* 34 + y].name == "pawn"){
                 if(x==0){
                    for(int k = x; k <= x+1; k++){
                        for (int l = y-4; l<= y+4; l++){
                            if(canAttack(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);

                        }
                    }
                 }


                    int a;
                    int b;
                    if(x<4||x>16){
                        a=0;
                    }else{
                        a=1;
                        b=4;
                    }
                    for(int k = x-1; k <= x+1; k++){
                        for (int l = y-4; l<= y+4; l++){

                            if(canAttack(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                        }
                    }
            }

            else{// Tu dzia³a ale wolmo!!!!!!!!!!*/
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

/*
    Kawaleria       - cav
    Zagadka         - mystery

    pole przepaœci  - notexist
    pole puste      - empty
*/



bool highlight(int x, int y){
            
            //pionek
            if (front_fields[x* 34 + y].name == "pawn"){
                        for (int l = y-4; l<= y+4; l++){
                            if(l>=0&&l<34){
                                if((x%2==l%2)&&front_fields[x*34+l].name!="notexist"){

                                        if(canAttack(front_fields, x, y, x, l))background_fields[x][l].setColor(sf::Color::Red);
                                        else if(CanMove(front_fields, x, y, x, l))background_fields[x][l].setColor(sf::Color::Green);
                                }
                            }
                        }
                        int a;
                        tura==1?a=1:a=-1;
                        if(x>0){
                            if(canAttack(front_fields, x, y, x-1, y+a))background_fields[x-1][y+a].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, x-1, y+a))background_fields[x-1][y+a].setColor(sf::Color::Green);
                        }
                        if(x<16){
                            if(canAttack(front_fields, x, y, x+1, y+a))background_fields[x+1][y+a].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, x+1, y+a))background_fields[x+1][y+a].setColor(sf::Color::Green);
                        }
            } 

            //duch
            else if(front_fields[x* 34 + y].name == "ghost"){
                for(int k = x-2; k <= x+2; k++){
                    for (int l = y - 4; l<= y+4; l++){
                        if(k>-1&&k<17&&l>=0&&l<34){
                            if(canAttack(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                        }

                    }
                }
            }

            //krolik
            else if(front_fields[x* 34 + y].name == "king"){
                for(int k = x-1; k <= x+1; k++){
                    for (int l = y-2; l <= y+2; l++){
                        if(k>-1&&k<17&&l>=0&&l<34){
                            if(canAttack(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                        }
                    }
                }
            }

            //wieza
            else if(front_fields[x* 34 + y].name == "tower"){
                for(int k = x-2; k <= x+2; k++){
                    for (int l = y-4; l <= y+4; l++){
                        if(k>-1&&k<17&&l>=0&&l<34){
                            if(CanMove(front_fields, x, y, k, l))background_fields[k][l].setColor(sf::Color::Green);
                        }
                    }
                int nx=x+2;
                int ny=y+2;
                while(nx<17&&ny<34&&nx<x+4){
                    nx++;
                    ny++;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                }
                nx=x-2;
                ny=y-2;
                while(nx>0&&ny>0&&nx>x-4){
                    nx--;
                    ny--;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                }
                nx=x+2;
                ny=y-2;
                while(nx<17&&ny>0&&nx<x+4){
                    nx++;
                    ny--;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                }
                nx=x-2;
                ny=y+2;
                while(nx>0&&ny<34&&nx>x-4){
                    nx--;
                    ny++;
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                }
                for(int i=y+6; i<=y+8; i+=2){
                    if(canAttack(front_fields, x, y, x, i))background_fields[x][i].setColor(sf::Color::Red);
                }
                for(int i=y-8; i<=y-6; i+=2){
                    if(canAttack(front_fields, x, y, x, i))background_fields[x][i].setColor(sf::Color::Red);
                }
                }
            }

            //szarza
            else if(front_fields[x* 34 + y].name == "charge"){
                    for (int l = 0; l < 34; l++){
                        if(l>=0&&l<34){
                            if(canAttack(front_fields, x, y, x, l))background_fields[x][l].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, x, l))background_fields[x][l].setColor(sf::Color::Green);
                        }
                    }
                    if(x-2>0){
                        if(CanMove(front_fields, x, y, x-2, y))background_fields[x-2][y].setColor(sf::Color::Green);
                    }
                    if(x+2>0){
                        if(CanMove(front_fields, x, y, x+2, y))background_fields[x+2][y].setColor(sf::Color::Green);
                    }
            }

            //kawaleria
            else if(front_fields[x* 34 + y].name == "cav"){
                int nx=x+1;
                int ny=y+1;
                while(nx<=16&&ny<=33){
                    if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx++;
                    ny++;
                }
                nx=x-1;
                ny=y-1;
                while(nx>=0&&ny>=0){
                    if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx--;
                    ny--;
                }
                nx=x+1;
                ny=y-1;
                while(nx<=16&&ny>=0){
                    if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx++;
                    ny--;
                }
                nx=x-1;
                ny=y+1;
                while(nx>=0&&ny<=33){
                    if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx--;
                    ny++;
                }


            //zagadka
            }else if(front_fields[x* 34 + y].name == "mystery"){
                int nx=x+1;
                int ny=y+1;
                while(nx<17&&ny<34){
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                    else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx++;
                    ny++;
                }
                nx=x-1;
                ny=y-1;
                while(nx>=0&&ny>=0){
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                    else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx--;
                    ny--;
                }
                nx=x+1;
                ny=y-1;
                while(nx<17&&ny>=0){
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                    else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx++;
                    ny--;
                }
                nx=x-1;
                ny=y+1;
                while(nx>=0&&ny<34){
                    if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                    else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                    nx--;
                    ny++;
                }
                for(int i=0; i<34; i++){
                    if(canAttack(front_fields, x, y, x, i))background_fields[x][i].setColor(sf::Color::Red);
                    else if(CanMove(front_fields, x, y,x, i))background_fields[x][i].setColor(sf::Color::Green);
                }


            }
    return 1;
}

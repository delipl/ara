#include "Load_From_File.h"
/*
    Pionek          - pawn
    Duch            - ghost
    Kawaleria       - cav
    Król            - king
    Wie¿a           - tower
    Szar¿a          - charge
    Zagadka         - mystery

    pole przepaœci  - notexist
    pole puste      - empty
*/

int abs(int x)
{
    return x > 0 ? x: -x;
}
bool CanMove(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{

    Pole board[17][34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            board[i][j] = wsk_to_board[i * 34 + j];
        }
    }

    if(board[x][y].name=="charge"){
        if(board[targetX][targetY].name=="empty"){
            if( y==targetY && abs(targetX-x)==2 ) return 1;
            if( x==targetX){
                for(int i=y; i<targetY; )
                for(int i=y; i<targetY; i++){
                  if(!(board[x][i].name=="empty"||board[x][i].name=="notexist")) return 0;
                }return 1;
            }
        }
    }

    if(board[x][y].name=="tower"){
         if(board[targetX][targetY].name=="empty"){
            if(targetX==x){
                if(abs(targetY-y)==2) return 1;
                if(targetY-y==4 && board[x][y+2].name=="empty") return 1;
                if(targetY-y==-44 && board[x][y-2].name=="empty") return 1;
            }
            if(abs(targetX-x)==1 && abs(targetY-y)==1) return 1;
            if(abs(targetX-x)==2 && abs(targetY-y)==2) return 1;

         }else return 0;
	}

    if(board[x][y].name=="pawn")
    {
        if(board[targetX][targetY].name=="empty")
            {
                /*
                if(targetX == x && targetY == y + 1     ||
                   targetX == x + 2 && targetY == y + 1 ||
                   targetX == x - 2 && targetY == y + 1) return 1;
                else return 0;
                */
                int a = board[x][y].owner * 2 - 1;
                if((targetX == x) && (targetY == y + 2 * a)) return 1;
                else if((targetX == x + 1) && (targetY == y + a)) return 1;
                else if((targetX == x - 1) && (targetY == y + a)) return 1;
                else return 0;

            }
        else return 0;
    }

    if(board[x][y].name=="king")
    {
        if(board[targetX][targetY].name=="empty")
        {
            if((abs(targetX-x)==1 && abs(targetY-y)==1) || (targetX = x && abs(targetY-y)==2)) return 1;
            else return 0;
        }
        else return 0;
    }

    if(board[x][y].name=="ghost"){
        if(board[targetX][targetY].name=="empty"){
            return  (abs(targetY - x) == 3 && abs(targetY - y) == 1) ||
                    (abs(targetY - x) == 1 && abs(targetY - y) == 3) ||
                    (abs(targetY - x) == 2 && abs(targetY - y) == 0) ?
                    true: false;
        }
        else return 0;
    }

    //kawaleria
    if(board[x][y].name=="cav"){
        if(board[targetX][targetY].name == "empty"){

            if(x > targetX && y < targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j >= 0; --j){
                        //przeskakiwanie przez wrogow zrobie w canAttack()
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;

                    }
                }
                return 1;
            }

            if(x > targetX && y > targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j < 33; ++j){
                        //przeskakiwanie przez wrogow zrobie w canAttack()
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

            if(x < targetX && y > targetY){
                for(int i = x; i >= 0; --i){
                    for (int j = y; j < 33; ++j){
                        //przeskakiwanie przez wrogow zrobie w canAttack()
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

            if(x < targetX && y < targetY){
                for(int i = x; i >= 0;i--){
                    for (int j = y; j >= 0; --j){
                        //przeskakiwanie przez wrogow zrobie w canAttack()
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

        }
        else return 0;
    }

    //zagadka
    if(board[x][y].name=="mystery"){
        if(board[targetX][targetY].name == "empty"){
             if(x > targetX && y < targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j >= 0; --j){
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;

                    }
                }
                return 1;
            }

            if(x > targetX && y > targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j < 33; ++j){
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

            if(x < targetX && y > targetY){
                for(int i = x; i >= 0; --i){
                    for (int j = y; j < 33; ++j){
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

            if(x < targetX && y < targetY){
                for(int i = x; i >= 0;i--){
                    for (int j = y; j >= 0; --j){
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

            if((targetX-x) == 0 && targetY > y){
                for (int j = y; j < 33; ++j){
                        if (board[x][j].name != "empty" && board[x][j].name != "notexist") return 0;
                    }
                return 1;
            }
            if((targetX-x) == 0 && targetY < y){
                for (int j = y; j >= 0; --j){
                        if (board[x][j].name != "empty" && board[x][j].name != "notexist") return 0;
                    }
                return 1;
            }
        }
    }
    return 0;
}
//if(canAttack(fields, gsdfhgf);





bool canAttack(Pole *wsk_to_board, int x, int y, int targetX, int targetY){

    Pole board[17][34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            board[i][j] = wsk_to_board[i * 34 + j];
        }
    }
    if(board[x][y].name != "empty" && board[x][y].name != "notexist" && board[x][y].owner != board[targetX][targetY].owner){ //wskazane pole jest figura przeciwnika

        //duch
        if(board[x][y].name == "ghost"){
            return  (abs(targetY - x) == 3 && abs(targetY - y) == 1) ||
                    (abs(targetY - x) == 1 && abs(targetY - y) == 3) ||
                    (abs(targetY - x) == 2 && abs(targetY - y) == 0) ?
                    true: false;
        }

        //kawaleria
        //=======================================[CAVALERY COMBAT ABILITY]=========================
        if(board[x][y].name == "cav"){
            if(x > targetX && y < targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j >= 0; --j){
                        if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i+1][j+1].name == "empty") // kiedy zabija jednego
                                return 1;
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist")      && board[i+1][j-1].name == "empty" &&
                                (board[i-2][j+2].name != "empty" && board[i][j].name != "notexist") && board[i-1][j+1].name == "empty" &&
                                                                                                    i == targetX && j == targetY)// kiedy zabija dwoch
                                return 1;

                    }
                    return 0;
                }

                if(x > targetX && y < targetY){
                    for(int i = x; i < 17;i++){
                        for (int j = y; j < 33; ++j){
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i+1][j+1].name == "empty") // kiedy zabija jednego
                                return 1;
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist")      && board[i+1][j+1].name == "empty" &&
                                (board[i-2][j-2].name != "empty" && board[i][j].name != "notexist") && board[i-1][j-1].name == "empty" &&
                                                                                                    i == targetX && j == targetY)// kiedy zabija dwoch
                                return 1;
                        }
                    }
                    return 0;
                }

                if(x > targetX && y < targetY){
                    for(int i = x; i >= 0 ;i--){
                        for (int j = y; j < 33; ++j){
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i-1][j+1].name == "empty") // kiedy zabija jednego
                                return 1;
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist")      && board[i-1][j+1].name == "empty" &&
                                (board[i-2][j-2].name != "empty" && board[i][j].name != "notexist") && board[i+1][j-1].name == "empty" &&
                                                                                                    i == targetX && j == targetY)// kiedy zabija dwoch
                                return 1;
                        }
                    }
                    return 0;
                }

                if(x > targetX && y < targetY){
                    for(int i = x; i >= 0 ;i--){
                        for (int j = y; j >= 0; --j){
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i-1][j-1].name == "empty") // kiedy zabija jednego
                                return 1;
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist")      && board[i-1][j-1].name == "empty" &&
                                (board[i+2][j+2].name != "empty" && board[i][j].name != "notexist") && board[i+1][j+1].name == "empty" &&
                                                                                                    i == targetX && j == targetY)// kiedy zabija dwoch
                                return 1;

                        }
                    }
                    return 0;
                }

            }

        //================================================================

        //krol
        if(board[x][y].name == "king"){
            if((abs(targetX-x) == 1 && abs(targetY-y) == 1) || (targetX = x && abs(targetY-y) == 2)) return 1;
            else return 0;
        }

        //szarza
        if(board[x][y].name == "charge"){
            if(targetY < y){
                for (int j = y; j >= targetY; j--){
                    //if(board[y][j].owner == board[x][y].owner) board[y][j].name = "empty"; //<- w attack()
                    if(board[x][j].name != "empty" && board[x][j].name != "notexist" && j == targetY && targetX == x){
                        return 1;
                    }
                }
            return 0;
            }
            if(targetY > y){
                for (int j = y; j <= targetY; j++){
                    //if(board[y][j].owner == board[x][y].owner) board[y][j].name = "empty"; //<- w attack()
                    if(board[x][j].name != "empty" && board[x][j].name != "notexist" && j == targetY && targetX == x){
                        return 1;
                    }
                }
            return 0;
            }
        }

        if(board[x][y].name=="tower"){
                if(x==targetX && abs(targetY-y)<6 && abs(targetY-y)>1) return 1;
                if(abs(targetX-x)==2 && abs(y-targetY)==2) return 1;
                if(abs(targetX-x)==3 && abs(y-targetY)==3) return 1;
                if(abs(targetX-x)==4 && abs(y-targetY)==4) return 1;
                if(abs(targetX-x)==5 && abs(y-targetY)==5) return 1;
                return 0;
            }
        if(board[x][y].name=="pawn"){
            int a;
            board[x][y].owner==1 ? a=1: a=-1;
            if( abs(targetX==x) && a*(targetY-y)==1 ) return 1;
            if( abs(targetX-x==1) &&  abs(targetY-y==1)) return 1;
        }
        if(board[x][y].name=="mystery"){
            if(x > targetX && y < targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j >= 0; --j){
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;

                    }
                }
                return 1;
            }

            if(x > targetX && y > targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j < 33; ++j){
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

            if(x < targetX && y > targetY){
                for(int i = x; i >= 0; --i){
                    for (int j = y; j < 33; ++j)
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                }
                return 1;
            }

            if(x < targetX && y < targetY){
                for(int i = x; i >= 0;i--){
                    for (int j = y; j >= 0; --j){
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                }
                return 1;
            }

            if((targetX-x) == 0 && targetY > y){
                for (int j = y; j < 33; ++j){
                       if (board[x][j].name != "empty" && board[x][j].name != "notexist") return 0;
                    }
                return 1;
            }
            if((targetX-x) == 0 && targetY < y){
                for (int j = y; j >= 0; --j){
                    if (board[x][j].name != "empty" && board[x][j].name != "notexist") return 0;
                }
                return 1;
            }

        }
    }
    else return 0;
}
}

void Move(Pole *board, int x, int y, int targetX, int targetY)
{
    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {

    }

    board[targetX * 34 + targetY].name = board[x * 34 + y].name;
    board[targetX * 34 + targetY].owner = board[x * 34 + y].owner;
    board[x * 34 + y].name = "empty";
    board[x * 34 + y].owner = 0;
}

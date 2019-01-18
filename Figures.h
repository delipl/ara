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

    if(board[x][y].name=="charge")
    {
        if((y == targetY) && (abs(targetX - x) == 2)) return 1;
        if(x == targetX)
        {
            if(y > targetY)
            {
                for(int i = targetY; i <= y; i ++)
                {
                    if((board[x][i].name == "empty") || (board[x][i].owner == board[x][y].owner))
                    {
                        continue;
                    }
                    return 0;
                }
                return 1;
            }
            else
            {
                for(int i = y; i <= targetY; i ++)
                {
                    if((board[x][i].name == "empty") || (board[x][i].owner == board[x][y].owner))
                    {
                        continue;
                    }
                    return 0;
                }
                return 1;
            }
        }
    }

    if(board[x][y].name=="tower")
    {
        if(targetX==x)
        {
            if(abs(targetY-y) == 2) return 1;
            if(abs(targetY-y) == 4)
            {
                if(board[x][(targetY + y) / 2].name == "empty") return 1;
                else return 0;
            }
        }
        if(abs(targetX-x)==1 && abs(targetY-y)==1) return 1;
        if(abs(targetX-x)==2 && abs(targetY-y)==2)
        {
            if(board[(x + targetX) / 2][(y + targetY) / 2].name == "empty") return 1;
            else return 0;
        }
        else return 0;
	}

    if(board[x][y].name=="pawn")
    {
        int a;
        if(board[x][y].owner==1) a = 1;
        else a = -1;

        if((targetX == x) && (targetY == y + 2 * a)) return 1;
        else if((targetX == x + 1) && (targetY == y + a)) return 1;
        else if((targetX == x - 1) && (targetY == y + a)) return 1;
        else return 0;
    }

    if(board[x][y].name=="king")
    {
        if((abs(targetX - x) == 1) && (abs(targetY - y) == 1)) return 1;
        if((targetX == x) && (abs(targetY - y) == 2)) return 1;
        return 0;
    }

    if(board[x][y].name=="ghost")
    {
        if((abs(targetX - x) == 1) && (abs(targetY - y) == 3)) return 1;
        if((abs(targetX - x) == 2) && (abs(targetY - y) == 0)) return 1;
        else return 0;
    }

    //kawaleria
    if(board[x][y].name=="cav")
    {
        int d_x;
        int d_y;
        if(targetX > x) d_x = 1;
        else d_x = -1;
        if(targetY > y) d_y = 1;
        else d_y = -1;

        if(abs(targetX - x) != abs(targetY - y))
        {
            return 0;
        }

        int opponent_owner;
        if(board[x][y].owner == 1)
        {
            opponent_owner = 2;
        }
        else
        {
            opponent_owner = 1;
        }

        for(int i = 1; i < abs(targetX - x); i ++)
        {
            if(board[i * d_x + x][i * d_y + y].name == "notexist")
            {
                return 0;
            }
            if(board[i * d_x + x][i * d_y + y].name != "empty")
            {
                if((targetX == i * d_x + d_x + x) && (targetY == i * d_y + d_y + y))
                {
                    return 1;
                }
                if((board[i * d_x + x][i * d_y + y].owner == opponent_owner) &&
                   (board[(i + 1) * d_x + x][(i + 1) * d_y + y].name == "empty") &&
                   (board[(i + 2) * d_x + x][(i + 2) * d_y + y].owner == opponent_owner) &&
                   (targetX == (i + 3) * d_x + x) && (targetY == (i + 3) * d_y + y))
                {
                    return 1;
                }
                else return 0;
            }
        }
        return 1;
    }

    //zagadka
    if(board[x][y].name=="mystery")
    {
        int d_x;
        int d_y;
        int changes;

        if(targetX - x == 0)
        {
            d_x = 0;
            if(targetY > y) d_y = 2;
            else d_y = -2;

            changes = (targetY - y) / 2;
        }
        else
        {
            if(targetX > x) d_x = 1;
            else d_x = - 1;

            if(targetY > y) d_y = 1;
            else d_y = -1;

            changes = targetY - y;
        }

        for(int i = 1; i < changes; i ++)
        {
            if(board[i * d_x + x][i * d_y + y].owner == board[x][y].owner)
            {
                return 0;
            }
        }
        return 1;
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

void Move(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    /*
    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {
        ms_error(392, "Figures/Move/something wrong with file dupa.png");
        return;
    }
    */

    if((wsk_to_board[x * 34 + y].name == "cav") || (wsk_to_board[x * 34 + y].name == "charge"))
    {
        Pole board[17][34];

        for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                board[i][j] = wsk_to_board[i * 34 + j];
            }
        }

        int d_x;
        int d_y;

        if(board[x][y].name == "charge")
        {
            if(targetY != y)
            {
                if(targetY > y) d_y = 1;
                else d_y = -1;

                for(int i = 1; i < (targetY - y); i ++)
                {
                    board[x][i * d_y + y].name = "empty";
                    board[x][i * d_y + y].owner = 0;
                    //board[x][i * d_y + y].setTexture(Background);
                }
            }
        }
        else if(board[x][y].name == "cav")
        {
            int opponent_owner;
            if(board[x][y].owner == 1) opponent_owner = 2;
            else opponent_owner = 1;

            if(targetX > x) d_x = 1;
            else d_x = -1;

            if(targetY > y) d_y = 1;
            else d_y = -1;

            if(board[targetX - d_x][targetY - d_y].owner == opponent_owner)
            {
                    board[targetX - d_x][targetY - d_y].name = "empty";
                    board[targetX - d_x][targetY - d_y].owner = 0;
                    //board[targetX - d_x][targetY - d_y].setTexture(Background);
                    if(board[targetX - (2 * d_x)][targetY - (2 * d_y)].name == "empty")
                    {
                        if(board[targetX - (3 * d_x)][targetY - (3 * d_y)].owner == opponent_owner)
                        {
                            board[targetX - (3 * d_x)][targetY - (3 * d_y)].name = "empty";
                            board[targetX - (3 * d_x)][targetY - (3 * d_y)].owner = 0;
                            //board[targetX - (3 * d_x)][targetY - (3 * d_y)].setTexture(Background);
                        }
                    }
            }
        }
    }

    wsk_to_board[targetX * 34 + targetY].name = wsk_to_board[x * 34 + y].name;
    wsk_to_board[targetX * 34 + targetY].owner = wsk_to_board[x * 34 + y].owner;
    //wsk_to_board[targetX * 34 + targetY].setTexture(wsk_to_board[x * 34 + y].getTexture());
    //wsk_to_board[x * 34 + y].setTexture(Background);
    wsk_to_board[x * 34 + y].name = "empty";
    wsk_to_board[x * 34 + y].owner = 0;
}

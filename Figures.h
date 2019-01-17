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
bool CanMove(Pole board[17][34], int x, int y, int targetX, int targetY)
{
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
    }else return 0;

    if(board[x][y].name=="tower"){
         if(board[targetX][targetY].name=="empty"){
            if(targetX==x){
                if(abs(targetY-y)==2) return 1;
                if(targetY-y==4&&board[x][y+2].name=="empty") return 1;
                if(targetY-y==-44&&board[x][y-2].name=="empty") return 1;
            }
            if(abs(targetX-x)==1 && abs(targetY-y)==1) return 1;
            if(abs(targetX-x)==2 && abs(targetY-y)==2) return 1;

         }else return 0;
	}

    if(board[x][y].name=="pawn")
    {
        if(board[targetX][targetY].name=="empty")
            {
                if(targetX == x && targetY == y + 1 ||
                   targetX == x + 2 && targetY == y + 1 ||
                   targetX == x - 2 && targetY == y + 1) return 1;
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
}


bool canAttack(Pole board[17][34], int x, int y, int targetX, int targetY){

    if(board[x][y].name=="ghost"){
        if(board[targetX][targetY].name != "empty" && board[targetX][targetY].name != "notexist")
            return  (abs(targetY - x) == 3 && abs(targetY - y) == 1) ||
                    (abs(targetY - x) == 1 && abs(targetY - y) == 3) ||
                    (abs(targetY - x) == 2 && abs(targetY - y) == 0) ?
                    true: false;
        else return 0;
    }
    //=======================================[CAVALERY COMBAT ABILITY]=========================
    if(board[x][y].name == "cav"){
        if(board[x][y].name != "empty" && board[x][y].name != "notexist"){

            if(x > targetX && y < targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j >= 0; --j){
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i+1][j-1].name == "empty"){ // kiedy zabija jednego

                                if((board[i+2][j-2].name != "empty" && board[i+2][j-2].name != "notexist") && board[i+3][j-3].name == "empty" && i+2 == targetX && j-2 == targetY){ // kiedy zabija dwoch
                                    board[i][j].name = "empty";             //zabijam kogoś po drodze
                                    return 1;
                                }
                                return 1;
                            }

                    }
                }
                return 0;
            }
            if(x > targetX && y < targetY){
                for(int i = x; i < 17;i++){
                    for (int j = y; j < 33; ++j){
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i+1][j+1].name == "empty"){ // kiedy zabija jednego

                                if((board[i+2][j+2].name != "empty" && board[i+2][j+2].name != "notexist") && board[i+3][j+3].name == "empty" && i+2 == targetX && j+2 == targetY){ // kiedy zabija dwoch
                                    board[i][j].name = "empty";             //zabijam kogoś po drodze
                                    return 1;
                                }
                                return 1;
                            }

                    }
                }
                return 0;
            }
            if(x > targetX && y < targetY){
                for(int i = x; i >= 0 ;i--){
                    for (int j = y; j < 33; ++j){
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i-1][j+1].name == "empty"){ // kiedy zabija jednego

                                if((board[i-2][j+2].name != "empty" && board[i-2][j+2].name != "notexist") && board[i-3][j+3].name == "empty" && i-2 == targetX && j+2 == targetY){ // kiedy zabija dwoch
                                    board[i][j].name = "empty";             //zabijam kogoś po drodze
                                    return 1;
                                }
                                return 1;
                            }

                    }
                }
                return 0;
            }
            if(x > targetX && y < targetY){
                for(int i = x; i >= 0 ;i--){
                    for (int j = y; j >= 0; --j){
                            if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i-1][j-1].name == "empty"){ // kiedy zabija jednego

                                if((board[i-2][j-2].name != "empty" && board[i-2][j-2].name != "notexist") && board[i-3][j-3].name == "empty" && i-2 == targetX && j-2 == targetY){ // kiedy zabija dwoch
                                    board[i][j].name = "empty";             //zabijam kogoś po drodze
                                    return 1;
                                }
                                return 1;
                            }

                    }
                }
                return 0;
            }


        }
        else return 0;
    }
    //================================================================

    if(board[x][y].name=="king")
    {
        if(board[targetX][targetY].name != "empty" && board[x][y].name != "notexist")
        {
            if((abs(targetX-x) == 1 && abs(targetY-y) == 1) || (targetX = x && abs(targetY-y) == 2)) return 1;
            else return 0;
        }
        else return 0;
    }


}

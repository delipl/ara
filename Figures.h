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
    if(board[x][y].name=="pawn")
    {
        if(board[targetX][targetY].name=="empty")
            {
                if(targetX == x && targetY == y + 1     ||
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

    if(board[x][y].name=="mystery"){
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

            if((targetX-x) == 0 && targetY > y){
                for (int j = y; j < 33; ++j){
                        //przeskakiwanie przez wrogow zrobie w canAttack()
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                return 1;
            }
            if((targetX-x) == 0 && targetY < y){
                for (int j = y; j >= 0; --j){
                        //przeskakiwanie przez wrogow zrobie w canAttack()
                        if (board[i][j].name != "empty" && board[i][j].name != "notexist") return 0;
                    }
                return 1;
            }
        }
    }

}


bool canAttack(Pole board[17][34], int x, int y, int targetX, int targetY){


    if(board[x][y].name != "empty" && board[x][y].name != "notexist" && board[x][y].owner != board[targetX][targetY]){ //wskazane pole jest figura przeciwnika
        
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
                                if((board[i][j].name != "empty" && board[i][j].name != "notexist") && board[i+1][j-1].name == "empty"){ // kiedy zabija jednego
                                
                                    if((board[i+2][j-2].name != "empty" && board[i+2][j-2].name != "notexist") && board[i+3][j-3].name == "empty" && i+2 == targetX && j-2 == targetY) // kiedy zabija dwoch
                                        board[i][j].name = "empty";             //zabijam kogoś po drodze
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

        //krol
        if(board[x][y].name=="king"){
            if((abs(targetX-x) == 1 && abs(targetY-y) == 1) || (targetX = x && abs(targetY-y) == 2)) return 1;
            else return 0; 
        }
    else return 0;
}
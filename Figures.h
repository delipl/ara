/*
    Pionek          - pawn
    Duch            - ghost
    Kawaleria       - cav
    Król            - king
    Wie¿a           - tower
    Szar¿a          - charge
    Zagadka         - mystery

    pole przepaœci  - notexist
    polec puste     - empty
*/

int abs(int x){
    return x > 0 ? x: -x;
}

bool CanMove(Pole board[17][34], int x, int y, int targetX, int targetY){
    if(board[x][y].name=="charge"){
        if(board[targetX][targetY].name=="empty") return 1;

        else return 0;
    }
    if(board[x][y].name=="tower"){
         if(board[targetX][targetY].name=="empty") return 1;

         else return 0;
    }
    if(board[x][y].name=="ghost"){
        if(board[targetX][targetY].name=="empty"){
            return abs(targetY - x) == 3 && abs(targetY - y) == 1? true: false ||
        }

        else return 0;
    }


}

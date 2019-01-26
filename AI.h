struct ruch{
        int x;
        int y;
        int tx;
        int ty;
};


int Wartosc(std::string a){

    if(a=="pawn")return 1;
    else if(a=="tower")return 7;
    else if(a=="ghost")return 5;
    else if(a=="cav")return 4;
    else if(a=="charge")return 3;
    else if(a=="mystery")return 10;
    else if(a=="king")return 100;
    else std::cout<<"cos poszlo bardzo zle z zliczaniem figur!!!!!!";



}

int zliczWartosciP(Pole *wsk_to_board){

    Pole board[17*34+34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if((i%2==0&&j%2==0)||i%2==1&&j%2==1)
            board[i*34+j] = wsk_to_board[i * 34 + j];
        }
    }

    int pW=0;
    for(int k = 0; k < 17; k++){
        for (int l = 0; l< 34; l++){
            if(((k%2==0&&l%2==0)||k%2==1&&l%2==1)&&board[k*34+l].name!="notexist"){
                    if(board[k*34+l].owner==2) pW+=Wartosc(board[k*34+l].name);
            }
        }
    }
    return pW;
}
int zliczWartosciAI(Pole *wsk_to_board){
    Pole board[17*34+34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if((i%2==0&&j%2==0)||i%2==1&&j%2==1)
            board[i*34+j] = wsk_to_board[i * 34 + j];
        }
    }

    int aiW=0;
    for(int k = 0; k < 17; k++){
        for (int l = 0; l< 34; l++){
            if(((k%2==0&&l%2==0)||k%2==1&&l%2==1)&&front_fields[k*34+l].name!="notexist"){
                    if(front_fields[k*34+l].owner==1) aiW+=Wartosc(front_fields[k*34+l].name);
            }
        }
    }
    return aiW;
}

void wroc(Pole *wsk_to_board){
    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if((i%2==0&&j%2==0)||i%2==1&&j%2==1)
            front_fields[i*34+j] = wsk_to_board[i * 34 + j];
        }
    }
}

ruch znajdzRuch(Pole *wsk_to_board, int player){
    ruch Ruch;
    Pole board[17*34+34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if((i%2==0&&j%2==0)||i%2==1&&j%2==1)
            board[i*34+j] = wsk_to_board[i * 34 + j];
        }
    }

    bool r=0;
    bool tru;

    int actualWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
    int bestWartosc=0;
    int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
    for(int x = 0; x < 17; x++){

        for (int y = 0; y< 34; y++){

            if((x%2==y%2)&&front_fields[x*34+y].name!="notexist"){

                if(front_fields[x*34+y].owner==1){

                    if (front_fields[x* 34 + y].name == "pawn"){
                                for (int l = y-4; l<= y+4; l++){
                                    if(l>=0&&l<34){
                                        if((x%2==l%2)&&front_fields[x*34+l].name!="notexist"){

                                                if(canAttack(front_fields, x, y, x, l)||(CanMove(front_fields, x, y, x, l)))
                                                    Action(front_fields, x, y, x, l);
                                                    int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                                    if(newWartosc>=bestWartosc){
                                                        bestWartosc=newWartosc;
                                                        Ruch.x=x;
                                                        Ruch.y=y;
                                                        Ruch.tx=x;
                                                        Ruch.ty=l;
                                                        r=1;

                                                    }
                                                    wroc(board);

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
                    } else if(front_fields[x* 34 + y].name == "ghost"){
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
                            for (int l = 0; l <= 33; l++){
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
                    }else if(front_fields[x* 34 + y].name == "cav"){
                        int nx=x+1;
                        int ny=y+1;
                        while(nx<=16&&ny<=33){
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
                        while(nx<=16&&ny>=0){
                            if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                            nx++;
                            ny--;
                        }
                        nx=x-1;
                        ny=y+1;
                        while(nx>=0&&ny<=33){
                            if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                            nx--;
                            ny++;
                        }

                    }else if(front_fields[x* 34 + y].name == "mystery"){
                        int nx=x;
                        int ny=y;
                        while(nx<17&&ny<34){
                            nx++;
                            ny++;
                            if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                        }
                        nx=x;
                        ny=y;
                        while(nx>0&&ny>0){
                            nx--;
                            ny--;
                            if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                        }
                        nx=x;
                        ny=y;
                        while(nx<17&&ny>0){
                            nx++;
                            ny--;
                            if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                        }
                        nx=x;
                        ny=y;
                        while(nx>0&&ny<34){
                            nx--;
                            ny++;
                            if(canAttack(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y, nx, ny))background_fields[nx][ny].setColor(sf::Color::Green);
                        }
                        for(int i=0; i<34; i++){
                            if(canAttack(front_fields, x, y, x, i))background_fields[x][i].setColor(sf::Color::Red);
                            else if(CanMove(front_fields, x, y,x, i))background_fields[x][i].setColor(sf::Color::Green);
                        }




                    }
                }
            }
        }
    }
    if(!r){
        Ruch.x=0;
        Ruch.y=0;
        Ruch.tx=0;
        Ruch.ty=0;
    }
    return Ruch;
}


int AI(Pole *wsk_to_board){

    std::cout<<"teraz ruszam sie ja!!!\n";
    ruch bestRuch=znajdzRuch(front_fields, 1);

    aiFX=bestRuch.x;
    aiFY=bestRuch.y;
    aiTX=bestRuch.tx;
    aiTY=bestRuch.ty;
}




int Wartosc(std::string a){

    if(a=="pawn")return 1;
    else if(a=="tower")return 7;
    else if(a=="ghost")return 5;
    else if(a=="cav")return 4;
    else if(a=="charge")return 3;
    else if(a=="mystery")return 10;
    else if(a=="king")return 100;
    else return 2000000000000000000000000000000;



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


int AI(Pole *wsk_to_board){

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




    std::cout<<"teraz ruszam sie ja!!!\n";
    for(int k = 0; k < 17; k++){

        for (int l = 0; l< 34; l++){

            if((k%2==l%2)&&board[k*34+l].name!="notexist"){

                if(front_fields[k*34+l].owner==1){

                    for(int i = 0; i < 17; i++){

                        for (int j = 0; j< 34; j++){


                            if((i%2==j%2)&&front_fields[i*34+j].name!="notexist"&&front_fields[i*34+j].owner!=1){
                                if(front_fields[k*34+l].owner==1){
                                    tru=0;
                                    if(CanMove(front_fields, k, l, i ,j)){
                                        Action(front_fields, k, l, i, j);
                                        newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);

                                        tru=1;
                                    }else if(canAttack(front_fields, k, l, i, j)){
                                        Action(front_fields, k, l, i, j);
                                        newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);

                                        tru=1;
                                    }

                                    wroc(board);
                                    if(newWartosc>actualWartosc&&tru){
                                            std::cout<<"hejka\n";
                                            aiFX=k;
                                            aiFY=l;
                                            aiTX=i;
                                            aiTY=j;
                                            r=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(!r){
        aiFX=0;
        aiFY=0;
        aiTX=0;
        aiTY=0;
    }

}


int Wartosc(std::string a){

    if(a=="pawn")return 1;
    else if(a=="tower")return 7;
    else if(a=="ghost")return 5;
    else if(a=="cav")return 4;
    else if(a=="charge")return 3;
    else if(a=="mystery")return 10;
    else if(a=="king")return 100;



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

    aiW=0;
    for(int k = 0; k < 17; k++){
        for (int l = 0; l< 34; l++){
            //pokoloruj canMove na pustym polu
            if(((k%2==0&&l%2==0)||k%2==1&&l%2==1)&&front_fields[k*34+l].name!="notexist"){
                    if(front_fields[k*34+l].owner==2) pW+=Wartosc(front_fields[k*34+l].name);
            }
        }
    }
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

    aiW=0;
    for(int k = 0; k < 17; k++){
        for (int l = 0; l< 34; l++){
            //pokoloruj canMove na pustym polu
            if(((k%2==0&&l%2==0)||k%2==1&&l%2==1)&&front_fields[k*34+l].name!="notexist"){
                    if(front_fields[k*34+l].owner==1) aiW+=Wartosc(front_fields[k*34+l].name);
            }
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
    int actualWartoscP=zliczWartosciP(board);
    int actualWartoscAI=zliczWartosciAI(board);
    int newWartoscP;

        std::cout<<"teraz ruszam sie ja!!!\n";
        for(int k = 0; k < 17; k++){
            for (int l = 0; l< 34; l++){
                if((k%2==l%2)&&board[k*34+l].name!="notexist"){
                    if(board[k*34+l].owner==1){


                        for(int i = 0; i < 17; i++){
                            for (int j = 0; j< 34; j++){
                                if((i%2==j%2)&&board[i*34+j].name!="notexist"){
                                    if (canAttack(board, k, l ,i, j)){
                                        //std::cout<<"bilem u siebie!!!\n";

                                        Action(board, k, l, i, j);
                                        newWartoscP=zliczWartosciP(board);
                                        if(newWartoscP>=actualWartoscP){
                                            aiFX=k;
                                            aiFY=l;
                                            aiTX=i;
                                            aiTY=j;
                                            std::cout<<k<<" "<<l<<" "<<i<<" "<<j<<" \n";
                                            return 0;
                                        }
                                    }
                                    else if (CanMove(board, k, l ,i, j)){
                                        //std::cout<<"ruszaalem u siebie!!!\n";
                                        Action(board, k, l, i, j);
                                        newWartoscP=zliczWartosciP(board);
                                        if(newWartoscP>=actualWartoscP){
                                            aiFX=k;
                                            aiFY=l;
                                            aiTX=i;
                                            aiTY=j;
                                            std::cout<<k<<" "<<l<<" "<<i<<" "<<j<<" \n";
                                            return 0;
                                        }
                                    }

                                }
                            }
                        }


                    }

                }

            }
        }

        std::cout<<"juz sie ruszylem!!!\n";

}


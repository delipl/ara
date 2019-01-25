

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

    pW=0;
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

    aiW=0;
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
    int actualWartoscP=zliczWartosciP(front_fields);
    std::cout<<"WartoscP: "<<actualWartoscP<<"\n";
    int actualWartoscAI=zliczWartosciAI(front_fields);
    int newWartoscP;
    int newWartoscAI;
    int bestWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
    int nBestWartosc;
    bool a=0;


        std::cout<<"teraz ruszam sie ja!!!\n";
        for(int k = 0; k < 17; k++){

            for (int l = 0; l< 34; l++){

                if((k%2==l%2)&&board[k*34+l].name!="notexist"){

                    if(front_fields[k*34+l].owner==1){


                        for(int i = 0; i < 17; i++){

                            for (int j = 0; j< 34; j++){


                                if((i%2==j%2)&&front_fields[i*34+j].name!="notexist"){


                                    if(canAttack(board, k, l, i, j)||CanMove(board, k, l, i, j)){

                                        newWartoscP=actualWartoscP;
                                        newWartoscAI=actualWartoscAI;

                                        nBestWartosc=newWartoscP-newWartoscAI;
                                        //std::cout<<"Newbest1: "<<nBestWartosc<<"\n";
                                        if(!Action(front_fields, k, l, i, j)){
                                                ms_error(32, "co ewidentnie zle(pojscie w myslach)");
                                                std::cout<<"Z: "<<k<<"x"<<l<<" na: "<<i<<"x"<<j<<"\n";
                                        }
                                        for(int m = 0; m < 17; m++){
                                            for (int n = 0; n< 34; n++){

                                                if((m%2==n%2)&&board[m*34+n].name!="notexist"){

                                                    if(front_fields[m*34+n].owner==2){
                                                            //std::cout<<"Znalazlem pionka przeciwnika w tym wypadku: "<<front_fields[m*34+n].name<<"\n";
                                                            if(front_fields[m*34+n].name!="cav"){
                                                                if(canAttack(front_fields, m, n, i, j)||CanMove(front_fields, m, n, i, j)){
                                                                   if(!Action(front_fields, m, n, i, j))ms_message("lolo");
                                                                }
                                                            }
                                                    }
                                                }
                                             }
                                        }


                                        newWartoscP=zliczWartosciP(front_fields);
                                        newWartoscAI=zliczWartosciAI(front_fields);
                                        nBestWartosc=newWartoscAI-newWartoscP;
                                        std::cout<<" Newbest: "<<nBestWartosc<<"\n";
                                        std::cout<<" best: "<<bestWartosc<<"\n";

                                        wroc(board);



                                        if(nBestWartosc>bestWartosc){
                                            bestWartosc=nBestWartosc;
                                            newWartoscP=actualWartoscP;
                                            newWartoscAI=zliczWartosciAI(front_fields);

                                            std::cout<<"jeste\n";
                                            aiFX=k;
                                            aiFY=l;
                                            aiTX=i;
                                            aiTY=j;
                                            a=1;

                                        }

                                    }




                                }
                            }
                        }


                    }

                }

            }

        }
        if(!a){
            for(int k = 0; k < 17; k++){

                for (int l = 0; l< 34; l++){

                    if((k%2==l%2)&&board[k*34+l].name!="notexist"){

                        if(board[k*34+l].owner==1){


                            for(int i = 0; i < 17; i++){

                                for (int j = 0; j< 34; j++){


                                    if((i%2==j%2)&&board[i*34+j].name!="notexist"){


                                        if(canAttack(board, k, l, i, j)||CanMove(board, k, l, i, j)){

                                            newWartoscP=actualWartoscP;
                                            newWartoscAI=actualWartoscAI;

                                            nBestWartosc=newWartoscP-newWartoscAI;
                                            //std::cout<<"Newbest1: "<<nBestWartosc<<"\n";
                                            if(!Action(front_fields, k, l, i, j))ms_error(32, "co ewidentnie zle(pojscie w myslach)");
                                            newWartoscP=zliczWartosciP(front_fields);
                                            newWartoscAI=zliczWartosciAI(front_fields);
                                            nBestWartosc=newWartoscAI-newWartoscP;
                                            std::cout<<" Newbest: "<<nBestWartosc<<"\n";
                                            std::cout<<" best: "<<bestWartosc<<"\n";

                                            wroc(board);



                                            if(nBestWartosc>=bestWartosc){
                                                bestWartosc=nBestWartosc;
                                                newWartoscP=actualWartoscP;
                                                newWartoscAI=zliczWartosciAI(front_fields);

                                                std::cout<<"jeste\n";
                                                aiFX=k;
                                                aiFY=l;
                                                aiTX=i;
                                                aiTY=j;
                                                a=1;
                                                return 1;

                                            }

                                        }




                                    }
                                }
                            }


                        }

                    }

                }

            }
        }
        std::cout<<"Poleglem!!!\n";
        return 0;

}


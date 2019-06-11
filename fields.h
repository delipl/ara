int posuniecieX = 0;
int posuniecieY = 0;

void backgroundFields(){

    front_fields = new Pole [578];
    // Przygotowanie tablic



    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            front_fields[i * board_size_y + j].name = "empty";
            front_fields[i * board_size_y + j].owner = 0;

            if(i%2==j%2)
            {
                int a=rand()%3;
                if(a==0)background_fields[i][j].setTexture(Background);
                else if(a==1)background_fields[i][j].setTexture(Background2);
                else if(a==2)background_fields[i][j].setTexture(Background3);
                background_fields[i][j].setScale(sf::Vector2f(scale, scale));
                //background_fields[i][j].setOrigin(sf::Vector2f(0.1, 0.1));
                background_fields[i][j].setPosition(sf::Vector2f(i*texture_kingD.getSize().x*0.79*scale+posuniecieX,j*texture_kingD.getSize().x*scale*0.45+posuniecieY));
                front_fields[i * board_size_y + j].setScale(sf::Vector2f(scale, scale));
                //front_fields[i * board_size_y + j].setOrigin(sf::Vector2f(0.1, 0.1));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(i*texture_kingD.getSize().x*0.79*scale+posuniecieX,j*texture_kingD.getSize().x*0.45*scale+posuniecieY));
            }
            else
            {
                background_fields[i][j].setPosition(sf::Vector2f(10000, 10000));
                background_fields[i][j].setOrigin(sf::Vector2f(0.1, 0.1));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(10000, 10000));
                //front_fields[i * board_size_y + j].setOrigin(sf::Vector2f(0.1, 0.1));
            }
        }
    }

    for (int i = 0; i<8;++i)
    {
        for (int j = 0; j<8; ++j)
        {
            if((j-i)>=0)
            {
                background_fields[i][j-i].setPosition(sf::Vector2f(10000, 10000));
                background_fields[i][26+j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + j-i].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + 26+j].setPosition(sf::Vector2f(10000, 10000));
            }
            else
            {
                background_fields[9+i][j].setPosition(sf::Vector2f(10000, 10000));
                background_fields[9+i][32-j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[(9+i) * board_size_y + j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[(9+i) * board_size_y + 32-j].setPosition(sf::Vector2f(10000, 10000));
            }
        }
    }

    for(int i = 8; i < 17; i ++)
    {
        background_fields[i][33].setPosition(sf::Vector2f(10000, 10000));
        front_fields[i * board_size_y + 33].setPosition(sf::Vector2f(10000, 10000));
    }
}

frontFields(){

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            setFigureTexture(&front_fields[i * board_size_y + j]);
            background_fields[i][j].setTexture(Background);
        }
    }
}

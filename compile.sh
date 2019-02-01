#!/bin/bash

g++ -c main.cpp
g++ main.o -o sfml-app.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
echo ara
cd araMenu/ 

g++ -c main.cpp
g++ main.o -o sfml-app.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
echo araMenu
cd ../
./sfml-app.o
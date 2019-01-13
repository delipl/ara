#include <stdio.h>
#include "Board.cpp"

int m = 10;
int n = 10;

class Board{
public:
	int x;
	int y;
	char name;
	/*~Board(){
 		printf("Umarlem\n");
	}*/
};
class Empty: public Board{
public:
	Empty(){
		printf("hello im empty\n");
	}
};

class Figure : public Board{
public:
	bool owner;
};

class Ghost: public Figure{
public:
	Ghost(int a, int b){
		this->x = a;
		this->y = b;
	};
}
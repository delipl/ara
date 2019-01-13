int m = 10;
int n = 10;
#include <stdio.h>
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
	Figure(){
		printf("hello im figure\n");
	}

};


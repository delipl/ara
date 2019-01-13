int m = 10;
int n = 10;
#include <stdio.h>
class Board{
public:
	int x = m;
	int y = n;
	//int cords [x][y];
};
class Empty: Board{
public:
	Empty(){
		printf("stworzono \n"); 
	};
};
#pragma once
#include<iostream>

using namespace std;
class game
{
public:
	game();
	void playgame();
private:
	int getxcoord();
	int getycoord();
	bool placemarker(int x, int y, int currentcoordinate);
	bool checkforvictory(char currentcoordinate);
	void clearboard();
	void printboard();
	char board[3][3];
};


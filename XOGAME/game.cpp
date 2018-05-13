#include "game.h"
#include<iostream>
using namespace std;

game::game()
{
}
void game::playgame() {
	clearboard();
	char player1 = 'X';
	char player2 = 'O';
	char currentlayer = player1;
	bool isdone = 1;
	int x, y,turn=0;

	

	while (isdone)
	{
		printboard();
		x = getxcoord();
		y = getycoord();
		if (placemarker(x, y, currentlayer) == 0) {
			cout << "That spot is occupied!" << endl;
			continue;
		}
		turn++;
		if (checkforvictory(currentlayer) == true) {
			cout << "The game is over! Player " << currentlayer << " has won!" << endl;
			break;
		}
		if (turn == 9) {
			cout << "this a tile game !" << endl;
			break;
		}


		if (currentlayer == player1)currentlayer = player2;
		else currentlayer = player1;
	}

}
int game::getxcoord() {
	int x;
	bool good = 1;
	while (good)
	{
		cout << "Enter the X coordinate = ";
		cin >> x;
		if (x < 1 || x>3) {
			cout << "Invalid coordinate!" << endl;
		}
		else
		{
			good = 0;
		}
	}
	return x - 1;
}
int game::getycoord() {
	int y;
	bool good = 1;
	while (good)
	{
		cout << "Enter the Y coordinate = ";
		cin >> y;
		if (y < 1 || y>3) {
			cout << "Invalid coordinate!" << endl;
		}
		else {
			good = 0;
		}
	}
	return y - 1;
}
bool game::placemarker(int x, int y, int currentcoordinate) {
	if (board[x][y] != ' ') {
		return false;
	}
    board[x][y] = currentcoordinate;
	return true;
}
bool game::checkforvictory(char currentcoordinate) {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == currentcoordinate && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == currentcoordinate && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return true;
		}
	}
	if ((board[0][0] == currentcoordinate) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		return true; //We won!
	}

	//Check top right diagonal
	if ((board[2][0] == currentcoordinate) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
		return true; //We won!
	}
	return false;
}
void game::clearboard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}
void game::printboard() {
	cout << endl;
	cout << " |1 2 3|" << endl;
	for (int i = 0; i < 3; i++) {
		cout << " -------" << endl;
		cout << i + 1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|" << endl;
	}
	cout << " -------" << endl;
}
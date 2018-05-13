#include<iostream>
#include<string>
using namespace std;
#include"game.h"
int main()
{
	
	char input;
	string s1, s2;
	bool good = true;
	game play;
	


	cout << "Welcome To TicTacToe Game !" << endl;
	while (good)
	{
		play.playgame();
		cout << "Would you like to play again? (Y/N): ";
		cin >> input;
		if (input == 'N' || input == 'n') {
			break;
		}
	}

	cout << endl;
    system("PAUSE");
	return 0;
}
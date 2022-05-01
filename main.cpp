#include "Ai.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Choose a gamemode:" << endl << "1) Player vs Player" << endl << "2) Player vs AI" << endl << "Choice: ";
	int choice;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Wrong input! Choose a number 1 or 2: ";
		cin >> choice;
	}

	if (choice == 1)
	{
		TicTacToe game;
		game.GameTwoPlayers();
	}
	else
	{
		Ai game;
		game.AiGame();
	}

	return 0;
}
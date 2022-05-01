#include "TicTacToe.h"
#include <iostream>
#include <iomanip>
using namespace std;

void TicTacToe::Add(int position, int playerNr)
{
	game_state[(position - 1) / size][(position - 1) % size] = playerNr == 1? player1 : player2;
}

bool TicTacToe::IsFull()
{

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (game_state[i][j] == ' ')
				return false;
	return true;
}

char TicTacToe::GameEnd() // draw == 0, player1 won == 1, player2 / Ai won== 2, game continues == 3
{

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (game_state[i][j] != ' ')
			{
				if (i > 0 && i < size - 1)
				{
					if ((game_state[i - 1][j] == game_state[i][j]) && (game_state[i][j] == game_state[i + 1][j]))
					{
						if (game_state[i][j] == player1) return 1;
						else return 2;
					}
				}

				if (j > 0 && j < size - 1)
				{
					if ((game_state[i][j - 1] == game_state[i][j]) && (game_state[i][j] == game_state[i][j + 1]))
					{
						if (game_state[i][j] == player1) return 1;
						else return 2;
					}
				}

				if (i == j)
				{
					if (i > 0 && i < size - 1)
						if ((game_state[i - 1][j - 1] == game_state[i][j]) && (game_state[i][j] == game_state[i + 1][j + 1]))
						{
							if (game_state[i][j] == player1) return 1;
							else return 2;
						}
				}

				if (i + j == size - 1)
				{
					if (i != 0 && j != 0)
					{
						if ((game_state[i + 1][j - 1] == game_state[i][j]) && (game_state[i][j] == game_state[i - 1][j + 1]))
						{
							if (game_state[i][j] == player1) return 1;
							else return 2;
						}
					}
				}
			}
		}
	if (IsFull()) return 0;
	else return 3;
}

void TicTacToe::PrintPositions()
{
	cout << "Positions in a grid: " << endl;
	for (int i = 1; i <= size * size; i++)
	{
		if ((i - 1) % size == 0)
		{
			if (i != 1)
			{
				cout << endl;
				for (int x = 1; x <= 3 * size + 2; x++)
					if (x % 4 == 0)
						cout << '|';
					else
						cout << '-';
				cout << endl;
			}
			cout << ' ' << i << ' ';
		}
		else
			cout << "| " << i << ' ';
	}
	cout << endl << endl;
}

void TicTacToe::PrintGrid()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == 0)
				cout << ' ' << game_state[i][j] << ' ';
			else
				cout << "| " << game_state[i][j] << ' ';
		}

		cout << endl;
		if (i != size - 1)
		{
			for (int x = 1; x <= 3 * size + 2; x++)
				if (x % 4 == 0)
					cout << '|';
				else
					cout << '-';
		}
		cout << endl;
	}
	cout << endl;
}

void TicTacToe::PlayerTurn(int playerNr)
{
	cout << "Your turn Player " << playerNr << '(' << (playerNr == 1 ? player1 : player2) << ")!" << endl;
	bool isAvailable;
	int choice;
	do
	{
		isAvailable = false;
		cout << "Choose a position: ";
		cin >> choice;
		if (choice > 0 && choice <= size * size)
		{
			if (game_state[(choice - 1) / size][(choice - 1) % size] == ' ')
				isAvailable = true;
			else
				cout << "The chosen position has to be empty!\n";
		}
		else
			cout << "The chosen position has to be between 0 and "<< size <<"!\n";

	} while (choice < 1 || choice > size * size || !isAvailable);

	Add(choice, playerNr);
}

void TicTacToe::GameTwoPlayers()
{
	cout << "Player 1 is " << player1 << " and player 2 is " << player2 << endl << "Good Luck!" << endl;
	system("pause");
	system("cls");
	int currentPlayer = 1, state = 3;
	while (state == 3)
	{
		PrintPositions();
		PrintGrid();
		PlayerTurn(currentPlayer);
		currentPlayer = currentPlayer == 1 ? 2 : 1;
		state = GameEnd();
		system("cls");
	}

	PrintGrid();
	switch (state)
	{

	case 0:
		cout << "It's a draw!" << endl;
		break;
	case 1:
		cout << "Player 1 Won!" << endl;
		break;
	case 2:
		cout << "Player 2 Won!" << endl;
		break;
	}
	system("pause");
}

TicTacToe::TicTacToe()
{
	player1 = 'x';
	player2 = 'o';

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			game_state[i][j] = ' ';
}
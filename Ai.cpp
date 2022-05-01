#include "Ai.h"
#include <iostream>
using namespace std;

void Ai::AiGame()
{
	cout << "Player is " << player1 << " and Ai is " << player2 << endl << "Good Luck!" << endl;
	system("pause");
	system("cls");
	int currentPlayer = 1, state = 3;
	while (state == 3)
	{
		PrintPositions();
		PrintGrid();
		currentPlayer == 1? PlayerTurn(currentPlayer) : AiMove();
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
		cout << "Player Won!" << endl;
		break;
	case 2:
		cout << "Computer Won!" << endl;
		break;
	}
	system("pause");
}

void Ai::AiMove()
{
	int max = -10000, temp, i_max = 0, j_max = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (game_state[i][j] == ' ')
			{
				game_state[i][j] = player2;
				temp = MinMax(false);
				game_state[i][j] = ' ';
				if (temp > max)
				{
					max = temp;
					i_max = i;
					j_max = j;
				}
			}
		}
	}
	game_state[i_max][j_max] = player2;
}

int Ai::MinMax(bool isMax)
{
	int czy_koniec = GameEnd();

	if (czy_koniec == 0)
		return 0;

	if (czy_koniec == 2)
		return 10 * (1 + SpacesLeft());

	if (czy_koniec == 1)
		return -10 * (1 + SpacesLeft());


	if (isMax)
	{
		int max = -10000, temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (game_state[i][j] == ' ')
				{
					game_state[i][j] = player2;
					temp = MinMax(false);
					game_state[i][j] = ' ';
					if (temp > max)
						max = temp;
				}
			}
		}
		return max;
	}

	else
	{
		int min = 10000, temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (game_state[i][j] == ' ')
				{
					game_state[i][j] = player1;
					temp = MinMax(true);
					game_state[i][j] = ' ';
					if (temp < min)
						min = temp;
				}
			}
		}
		return min;
	}
}

int Ai::SpacesLeft()
{
	int temp = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (game_state[i][j] == ' ')
				temp++;
	return temp;
}
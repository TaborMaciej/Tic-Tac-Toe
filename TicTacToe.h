#pragma once
class TicTacToe
{
public:
	void GameTwoPlayers();
	void PrintGrid();
	void PrintPositions();
	TicTacToe();

protected:
	void Add(int position, int playerNr);
	bool IsFull();
	char GameEnd();

	void PlayerTurn(int playerNr);

	static constexpr int size = 3;
	char game_state[size][size];
	char player1;
	char player2;

};


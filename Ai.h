#pragma once
#include "TicTacToe.h"

class Ai : public TicTacToe
{
public:
	void AiGame();

private:
	void AiMove();
	int MinMax(bool isMax);
	int SpacesLeft();
};


#include "AIShell.h"
#include <iostream>


AIShell::AIShell(int numCols, int numRows, bool gravityOn, int** gameState, Move lastMove)
{
	this->deadline = 0;
	this->numRows = numRows;
	this->numCols = numCols;
	this->gravityOn = gravityOn;
	this->gameState = gameState;
	this->lastMove = lastMove;
}


AIShell::~AIShell()
{

	//delete the gameState variable.
	for (int i = 0; i<numCols; i++) {
		delete[] gameState[i];
	}
	delete[] gameState;

}

Move AIShell::makeMove() {
	//this part should be filled in by the student to implement the AI
	//Example of a move could be: Move move(1, 2); //this will make a move at col 1, row 2


	//this will move to the left-most column possible.
	for (int col = 0; col<numCols; col++) {
		for (int row = 0; row<numRows; row++) {
			if (gameState[col][row] == NO_PIECE) {
				Move m(col, row);
				return m;
			}
		}
	}
	Move m(0, 0);
	return m;

}

bool AIShell::BoardFull()
{
	int count = 0;
	for (int col = 0; col < numCols; col++)
	{
		for (int row = 0; row < numRows; rows++)
		{
			if (gameState[col][row] == NO_PIECE) // empty space 
				count++;
		}
	}
	return count != 0; //if returns 0 means board is full else not 
}

/*Move AIShell::possibleMoves()
{
int **list;
for (int col = 0; col < numCols; col++)
{
for (int row = 0; row < numRows; row++ + )
{
if (gameState[col][row]==NO_PIECE)
}
}
}*/ ///TRY TO MAKE A LIST OR SOMETHING TO KEEP TRACK
void AIShell::Winner()
{
	// check board to see if there is a player 
	// with k moves (chips) on the board in order
	// if KEEP TRACK
}

Move AIShell::MiniMax(int maximaizing_player)
{
	Move move;
	for (int i = 0;)///create some sort of lisr to keep track of possible moves 
	{
		auto piece = gameState[col][row];//piece is an int??
		if (piece == AI_PIECE)
		{
			Min(HUMAN_PIECE);
		}
		else
			Max(AI_PIECE);
	}
}

Move AIShell::Max(int maxplayer)
{
	// if its a tie
	if (BoardFull() && Winner())
	{
		return 0

	}
	else if (Winner() != 0)
	{
		Heuristic()
	}
	else
	{
		///apply max implwmemtation
	}
}

Move AIShell::Min(int minplayer)
{
	if (BoardFull() && Winner())
	{
		return 0

	}
	else if (Winner() != 0)
	{
		Heuristic()
	}
	else
	{
		///apply min implwmemtation
	}

}

int Heuristic()
{

}
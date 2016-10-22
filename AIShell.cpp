#include "AIShell.h"
#include <iostream>
using namespace std;


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

Move AIShell::possibleMoves() 
{
	int best;
	int found = 0;
	int score[numCols][numRows];
	for (int i = 0; i <= numCols; i++)
	{
		for (int j = 0; j <= numRows; j++)
		{
			score[i][j] = 0;
		}
	}

	for (int i = 0; i <= numCols; i++)
	{
		if (score[])
	}
}
/*{
int **list;
for (int col = 0; col < numCols; col++)
{
for (int row = 0; row < numRows; row++ + )
{
if (gameState[col][row]==NO_PIECE)
}
}
}*/ ///TRY TO MAKE A LIST OR SOMETHING TO KEEP TRACK
// it should return alist like thing so that you can call i.row and i.col 

void AIShell::Winner()
{
	// check board to see if there is a player 
	// with k moves (chips) on the board in order
	// if KEEP TRACK
	
}

Move AIShell::MiniMax(int maximaizing_player)
{
	//int depth = 3;
	Move move;
	for (int i = 0; i < cutoff; i++)///create some sort of lisr to keep track of possible moves 
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
		return 0;

	}
	else if (Winner() != 0)
	{
		return Heuristic();
	}
	else
	{
		///apply max implwmemtation
		int score = -9999;
		for (int i = 0; possibleMoves()[i] != NULL; i++)
		{
			auto player = gameState[i.col][i.row];
			if (player == AI_PIECE)
				score = max(score, Min(HUMAN_PIECE));
			else
				score = max(score, Min(AI_PIECE));
		}
		return score;
	}
}

Move AIShell::Min(int minplayer)
{
	if (BoardFull() && Winner())
	{
		return 0;

	}
	else if (Winner() != 0)
	{
		return Heuristic();
	}
	else
	{
		///apply min implwmemtation
		int score = 9999;
		for (int i = 0; possibleMoves()[i] != NULL; i++)
		{
			auto player = gameState[i.col][i.row];
			if (player == AI_PIECE)
				score = min(score, Max(HUMAN_PIECE));
			else
				score = min(score, Max(AI_PIECE));
		}
		return score;
}

int checkhorizontal(int** gameState)
{
	int check[numRows];
	int count = 0;
	for (int row = 1; row < numRow; row++)
	{
		int prev = gameState[0][row]; // initally it should be the first piece
		for (int col = 0; col < numCol; col++)
		{
			if (prev == -1)//human 
			{
				if 
			}
			if (prev == 1)// ai
			{

			}
			/*if (gameState[col][row] == prev) // if the current piece is equal to the prev
			{
				// then 
				/*go thru each piece in each row and see if there is are any k in a row
				*/
			//}
				
			else
			{

			}
			prev = gameState[col][row];
		}
	}
}

int checkvertical()
{

}

int Heuristic()
{
	int step = 0;
	int **track;
	for (int col = 0; col < numCols; col++)
	{
		for (int row = 0; row < numRows; row++)
		{
			if (gameState[col][row] == AI_PIECE)
			{

			}
			if (gameState[col][row] == AI_PIECE)
			{
				
			}
		}
	}
}
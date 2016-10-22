 #include "AIShell.h"
#include <iostream>
using namespace std;



int** copyState(int** gameState, int numCols, int numRows)
{
    int** result = new int*[numCols];
    for(int i = 0; i < numCols; i++)
        result[i] = new int[numRows];
    
    for (int i = 0; i < numCols; i++)
        for (int j = 0; j < numRows; j++)
            result[i][j] = gameState[i][j];
    return result;
}

void printState(int** gameState, int numCols, int numRows)
{
      int** print = copyState(gameState, numCols, numRows);
      for (int i = 0; i < numCols; i++)
      {
          std::cout << " " << i << "|" << print[i][0]; 
          for (int j = 0; j < numRows; j++)
          {
              std::cout << print[i][j];
          }
          cout << "|" << endl;
      }
      std::cout << " +----------------+ " << std::endl;
}

Move decision(int** gameState, int depth, bool maxplayer, int numCols, int numRows, int player, int k)
{
     //starting point
     Move m(0,0);
     int best_score;
     for (int i = 0; i < numRows; i++){
         for (int j = 0; j < numCols; j++){
             if (gameState[i][j] == 0)
             {
     //decision score
                int score = minimax(gameState, depth, true, numCols, numRows, player, k);
                if (score > best_score)
                {
                   best_score = score;
                   Move m(i,j);          
                }
             }
         }
     }
     return m;
}

int minimax(int** gameState, int depth, bool maxplayer, int numCols, int numRows, int player, int k)
{
  if (depth == 0)
     return heuristic_assist(gameState, numCols, numRows, k, player);
     
  if (maxplayer)
  {
    int best = -99999;
    for (int i = 0; i < numCols; i++){
        for (int j = 0; j < numRows; j++){
            gameState[i][j] = 1; 
            int v = minimax(gameState, depth -1, false, numCols, numRows, player, k);
            best = max(best, v);   
        }
    }
    return best;
  }
  else //for min player
  {
     int best = 99999;
     for (int i = 0; i < numCols; i++){
        for (int j = 0; j < numRows; j++){
            gameState[i][j] = 1; 
            int v = minimax(gameState, depth -1, true, numCols, numRows, player, k);
            best = min(best, v);   
        }
    } 
    return best;
  }
     
}


/*
Move minimaxdecision(int** gameState, int depth, int ply, int numCols, int numRows, int k)//doesnt check opponent move right now
{
    printState(gameState, numCols, numRows);
    Move m(0,0); //starting
    //check all avaliable move and pick the best move possible for the current move
    int best_score = -99999;
    //returns the score
    //std::pair<int score, Move move> decision = maxvaluedecision(gameState, depth, ply, move);//best move for max out of the best possible min moves
    for (int i = 0; i < numCols; i++)
        for (int j =0; j < numRows; j++){
            std::cout << "position: ( " << i << ", " << j << ")" << std::endl;
            if (gameState[i][j] == 0) //this is max
            { //no move should be place
                   //depth += 1;
                int score = maxvaluedecision(gameState, depth, ply, numCols, numRows, k);
                if (score > best_score)
                {
                   gameState[i][j] = 1;//value is kept 
                   best_score = score;
                   m.col = i;
                   m.row = j;
                   std::cout << "best: ( " << m.col << ", " << m.row << " )" << std::endl;
                }
            }
        }
    
    return m;
}


int minvaluedecision(int** gameState, int depth, int ply, int numCols, int numRows, int k)
{
    int min_score = 99999;
    //if cut off then return the eval(state)
    if (depth == ply)
    {
        //evaluate current
        int player = -1; //? prob dont need this
        //heuristic comes in
        return heuristic_assist(gameState, numCols, numRows, k, player);
    }
    
    else
    {
        //for all legal space that can make move
        //find the min value from all the max value
        for (int i = 0; i < numCols; i++)
            for (int j = 0; j < numRows; j++)
                if (gameState[i][j] == 0)//if move is possible
                {
                    gameState[i][j] = 1;//this move is temp
                    //make pair
                    int score = min(min_score, (minvaluedecision(gameState, depth + 1, ply, numCols, numRows, k)));
                    if (score < min_score)
                    {
                        min_score = score;
                        //move.col = i; move.row = j; //assumption of min move placed
                    }
                    //gameState[i][j] = 0; //restore temp
                }
    }
    return min_score;//min is returned so max can pick the max from it.
        //return std::make_pair(score, move);//return both the score and move associated as pair
    //otherwise find the min for the next set of avaliable move (the weakest move)
    //for all avaliable legal move
    //set the value = min(v, maxvaluedecision(result(state, action))
    //return the value

}

int maxvaluedecision(int** gameState, int depth, int ply, int numCols, int numRows, int k)//takes the max
{
    int max_score = -99999;
    //if cut off then return the eval(state)
    if (depth == ply)
    {
        //evaluate current
        int player = 1;
        //heuristic comes in
        return heuristic_assist(gameState, numCols, numRows, k, player); // allows jump to step B.
    }
    
    else
        {
        //for all legal space that can make move
        for (int i = 0; i < numCols; i++)
            for (int j =0; j < numRows; j++)
                if (gameState[i][j] == 0)
                {
                    gameState[i][j] = 1;//temp move
        //find the max value from all the min value
                    int score = max(max_score, (minvaluedecision(gameState, depth + 1, ply, numCols, numRows, k)));
                    //step B. complete until all positions are check for best result
                    if (score > max_score)
                    {
                        max_score = score;
                        //move.col = i; move.row = j;//assumption of max move
                    }
                    //gameState[i][j] = 0;//restore temp
                }
        }
    return max_score;//max is returned so min can pick the min from it
        //return std::make_pair(score, move);//return both the score and move associated as pair
    //find the max for the next set of avaliable move (the best move)
    //for all avaliable legal move
    //set the value = max(v, minvaluedecision(result(state, action))
    //return the value

}
*/
int heuristic_assist(int** gameState, int numCols, int numRows, int k, int player)
{
    int max_score = heuristic_evaluation(gameState, numCols, numRows, k, 1);//for AI
    int min_score = heuristic_evaluation(gameState, numCols, numRows, k, -1);//for opponent
    std::cout << "heuristic score (max, min): " << max_score << ", " << min_score << std::endl;
    if (player == 1)
    {
        std::cout <<"Player" << std::endl;
        return max_score - min_score;
    }
    else if (player == -1)
    {
         std::cout << "Opponent" << std::endl;
        return min_score - max_score;
    }
}


int heuristic_evaluation(int ** gameState, int numCols, int numRows, int k, int player)
{
    int score = 0;
    int** current = copyState(gameState, numCols, numRows);
    for(int colPos = 0; colPos < numCols; colPos++){
        for (int rowPos = 0; rowPos < numRows; rowPos++){
            if (gameState[colPos][rowPos] !=0)//not empty
            {
                continue;
            }
            current[colPos][rowPos] = player;//set on temp
            if (checkWin(current, player, colPos, rowPos, k, numRows, numCols))
            {
                std::cout << "check win" << std::endl;
                score++;//if there is a min then
            }
            current[colPos][numRows] = 0;//remove after check
        }
    }
    return score;
}

bool checkWin(int** gameState, int currPlayer, int colPos,
              int rowPos, int k, int numRows, int numCols){
    if(checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                      -1, -1)) {//225 deg
        return true;
    }
    if (checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                       -1, 0)) {//270 deg
        return true;
    }
    if (checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                       -1, 1)) {//315 deg
        return true;
    }
    if (checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                       0, 1)) {//360 deg/0 deg
        return true;
    }
    if (checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                       1, 1)) { //45deg
        return true;
    }
    if (checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                       1, 0)) { //90 deg
        return true;
    }
    if (checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                       1, -1)) { //135 deg
        return true;
    }
    if (checkWinHelper(gameState, currPlayer, colPos, rowPos, k, numRows, numCols,
                       0, -1)) {//180 deg
        return true;
    }
    return false;
}

bool checkWinHelper(int** gameState, int currPlayer, int colPos,
                    int rowPos, int k, int numRows, int numCols, int colD, int rowD ) {
    for (int i = 1; i < k; i++) { //check 1->k because 1 is 1 piece away from origin, which is already "good"
        int newCol = colPos + colD * i;
        int newRow = rowPos + rowD * i;
        if (!((newCol) < numCols && (newCol) >= 0)
            || !((newRow) < numRows && (newRow) >= 0)
            || gameState[newCol][newRow] != currPlayer)
            return false;
        //return false if new colpos or rowpos is invalid or new space not occupied by currPlayer (and therefore not a win pos)
    }
    return true;
}

AIShell::AIShell(int numCols, int numRows, bool gravityOn, int** gameState, Move lastMove)
{
    this->deadline=0;
    this->numRows=numRows;
    this->numCols=numCols;
    this->gravityOn=gravityOn;
    this->gameState=gameState;
    this->lastMove=lastMove;
}


AIShell::~AIShell()
{
    
    //delete the gameState variable.
    for (int i =0; i<numCols; i++){
        delete [] gameState[i];
    }
    delete [] gameState;
    
}

Move AIShell::makeMove(){
    //this part should be filled in by the student to implement the AI
    //Example of a move could be: Move move(1, 2); //this will make a move at col 1, row 2
    
    
    //Move minmaxRootWithState(int**gameState, int player, int ply);
    //ply is the depth
    
    //int depth = 0;//starting depth = 0
    //int ply = 3; //cut off decision for each point is at 3
    int depth = 3;
    int player = 1;
    int** state = copyState(gameState, numCols, numRows);//get the game state before proceeding
    //return minimaxdecision(state, depth, ply, numCols, numRows, this->k);
    decision(state, depth, true, numCols, numRows, player, this-> k);
}

//max is the first player

//Actions = list of avaliable legal moves

//players = one that has the move

//Result(s,a): transition model defines the result of a move (state, action)

//terminal stage: determine the end game

//utility function (s, a): helper and gives numerical value of terminal state s for player p
// win(+1), lose(-1), draw(0)

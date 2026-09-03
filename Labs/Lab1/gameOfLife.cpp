#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], int boardSize)
{
    for(int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = new Cell;

            board[i][j]->y = i;
            board[i][j]->x = j;
            board[i][j]->state = 0;
            board[i][j]->numLiveNeighbors = 0;
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize)
{
    ifstream file("board2.txt");
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            char alive;
            file >> alive;

            if (alive == '1')
            {
                board[i][j]->state = 1;
            }
            else
            {
                board[i][j]->state = 0;
            }
        }
    }

    file.close();
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            printf(" %d ", board[i][j]->state);
        }
        printf("\n");
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{
    curCell->numLiveNeighbors = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            int y = curCell->y + i;
            int x = curCell->x + j;

            if (y >= 0 && y < boardSize && x >= 0 && x < boardSize)
            {
                curCell->numLiveNeighbors += board[y][x]->state;
            }
        }
    }
}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
//FIXME: Rewrite this function using a diffrent way to achieve the same thing
bool updateCellState(Cell* board[][10], int boardSize) 
{
    int newstate[10][10];

    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            findNumNeighbors(board, boardSize, board[i][j]);
            if (board[i][j]->state == 1)
            {
                if (board[i][j]->numLiveNeighbors == 2 || board[i][j]->numLiveNeighbors == 3)
                {
                    newstate[i][j] = 1;
                }
                else
                {
                    newstate[i][j] = 0;
                }
            }
            else
            {
                if (board[i][j]->numLiveNeighbors == 3)
                {
                    newstate[i][j] = 1;
                }
                else
                {
                    newstate[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j]->state = newstate[i][j];
        }
    }
    return true;
}
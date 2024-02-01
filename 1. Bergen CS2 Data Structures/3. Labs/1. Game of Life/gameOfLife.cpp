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
    // for (size_t i = 0; i < 10, i++) // Loops through the function 10 times
    // {
    //     for (size_t k = 0; k < boardSize; i++) // Loops through the function boardSize times
    //     {
    //         //
    //     }
    // }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    std::size_t fileOption = 0;
    std::cout << "Which file would you like to read? Options are 1, 2, and 3:";
    std::cin >> fileOption;

}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{

}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumLiveNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{

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
bool updateBoardState(Cell* board[][10], int boardSize) 
{
    return false;
}
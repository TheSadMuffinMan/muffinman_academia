// DO NOT CHANGE THIS FILE
#include <iostream>
#include <string>
#include "gameOfLife.h"

using namespace std;

int main(int argc, char* argv[])
{
    int stage = 0;
    bool boardChanged = true;
    size_t boardSize = 10;
    Cell* board[10][10];

    initCells(board, boardSize);
    readBoard(board, boardSize);

    printCells(board, boardSize);

    // while(boardChanged)
    // {
    //     clearScreen();
    //     cout << "Stage: " << stage << endl;

    //     printCells(board, boardSize);
    //     boardChanged = updateBoardState(board, boardSize);

    //     cin.get();
    //     stage++;
    // }

    // Clean up board if cells were allocated on the heap
    for (int i = 0; i < 10; i++)
    {
        for (size_t k = 0; k < boardSize; k++)
        {
            delete board[i][k];
        }
    }

    return 0;
}
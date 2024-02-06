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
    for (int i = 0; i < 10; i++) // i synonymous with y values
    {
        for (int k = 0; k < boardSize; k++) // k synonymous with x values/boardSize
        {
            Cell* newCell = new Cell;
            newCell-> y = i;
            newCell-> x = k;
            newCell->state = 0;
            newCell->numLiveNeighbors = 0;
            board[i][k] = newCell;
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
    std::size_t fileOption = 0;
    std::cout << "Which file would you like to read? Options are 1, 2, and 3: ";
    std::cin >> fileOption;

    ifstream inputStream; // Creates the input stream to pull our data from the txt files
    if (fileOption == 1)
    {
        inputStream.open("board0.txt");
    }
    else if (fileOption == 2)
    {
        inputStream.open("board1.txt");
    }
    else if (fileOption == 3)
    {
        inputStream.open("board2.txt");
    }
    else
    {
        cout << "readBoard() ***BROKE***" << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        string tempString;
        getline(inputStream, tempString); // WORKING

        for (int k = 0; k < boardSize; k++)
        {
            int temp;
            temp = tempString.at(k); // If the char is 0, function returns 48. If 1, returns 49. Manually changes it back to 1s and 0s.
            if (temp == 48)
            {
                temp = 0;
            }
            else
            {
                temp = 1;
            }
            board[i][k]->state = temp;
        }
    }

    inputStream.close(); // Closes the file
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < 10; i++) // Y value loop
    {
        for (int k = 0; k < boardSize; k++) // X value/boardsize loop
        {
            cout << board[i][k]->state;
        }
    cout << endl;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumLiveNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{
    for (int i = 0; i <= 8; i++)
    {
        //
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
bool updateBoardState(Cell* board[][10], int boardSize) 
{
    // Loop goes through every cell and counts the number of alive neighbors it has but DOES NOT UPDATE ANYTHING
    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < boardSize; k++)
        {
            Cell* curCell;
            curCell->x = i;
            curCell->y = k;

            findNumLiveNeighbors(board, boardSize, curCell);
        }
    }

    // Loop implements the logic of the game for each cell
    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < boardSize; k++)
        {
            if (board[i][k]->state == 0) // If a cell is dead
            {
                if (board[i][k]->numLiveNeighbors == 3) // And if a cell has 3 neighbors
                {
                    board[i][k]->state = 1; // REVIIIIIIIVE
                    return true;
                }
            }

            if (board[i][k]->state == 1) // If a cell is alive
            {
                if (board[i][k]->numLiveNeighbors < 2) // And it has 1 or less alive neighbors (underpopulation)
                {
                    board[i][k]->state = 0;
                    return true;
                }
                else if (board[i][k]->numLiveNeighbors > 3) // And it has 4 or more alive neighbors (overpopulation)
                {
                    board[i][k]->state = 0;
                    return true;
                }
            }
        }
    }
    return false;
}

// Old numLiveNeighbors() logic:
/*
    if ((curCell->x == 0) && (curCell->y == 0)) // If curCell is (0,0)/Top left corner
    {
        if (board[(curCell->x) + 1][curCell->y]->state == 1) // Checks cell below corner
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][(curCell->y) + 1]->state == 1) // Checks bottom right diagonal cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[curCell->x][(curCell->y) + 1]->state == 1) // Checks right cell
        {
            curCell->numLiveNeighbors++;
        }
    }

    if ((curCell->x == 0) && (curCell->y == 9)) // If curCell is (0,9)/Top right
    {
        if (board[curCell->x][(curCell->y) - 1]->state == 1) // Checks left cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][(curCell->y) - 1]->state == 1) // Checks lower left diagonal cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][curCell->y]->state == 1) // Checks the below cell
        {
            curCell->numLiveNeighbors++;
        }
    }

    if ((curCell->x == 9) && (curCell->y == 0)) // If curCell is (9,0)/Bottom left
    {
        if (board[(curCell->x) - 1][curCell->y]->state == 1) // Checks above cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) - 1][(curCell->y) + 1]->state == 1) // Checks upper right diagonal cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[curCell->x][(curCell->y) + 1]->state == 1) // Checks the right cell
        {
            curCell->numLiveNeighbors++;
        }
    }

    if ((curCell->x == 9) && (curCell->y == 9)) // If curCell is (9,9)/Bottom right
    {
        if (board[curCell->x][(curCell->y) - 1]->state == 1) // Checks left cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) - 1][(curCell->y) - 1]->state == 1) // Checks upper left diagonal cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) - 1][curCell->y]->state == 1) // Checks the above cell
        {
            curCell->numLiveNeighbors++;
        }
    }

    if (((curCell->x == 0) && (curCell->y != 0)) && ((curCell->x == 0) && (curCell->y != 9))) // If a cell is on the top row but NOT the corners
    {
        if (board[(curCell->x) + 1][(curCell->y) - 1]->state == 1) // Checks the lower left diag
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][curCell->y]->state == 1) // Checks the middle lower
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][(curCell->y) + 1]->state == 1) // Checks the lower right diag
        {
            curCell->numLiveNeighbors++;
        }
    }

    if (((curCell->y == 0) && (curCell->x != 0)) && ((curCell->y == 0) && (curCell->x != 9))) // If a cell is on the left column but NOT the corners
    {
        if (board[(curCell->x) - 1][(curCell->y) + 1]->state == 1) // Checks the upper right diag
        {
            curCell->numLiveNeighbors++;
        }

        if (board[curCell->x][(curCell->y) + 1]->state == 1) // Checks the middle right
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][(curCell->y) + 1]->state == 1) // Checks the lower right diag
        {
            curCell->numLiveNeighbors++;
        }
    }

    if (((curCell->x == 9) && (curCell->x != 0)) && ((curCell->x == 9) && (curCell->y != 9))) // If a cell is on the bottom row but NOT the corners
    {
        if (board[(curCell->x) - 1][(curCell->y) - 1]->state == 1) // Checks the upper left diag
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) - 1][curCell->y]->state == 1) // Checks the upper middle
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) - 1][(curCell->y) + 1]->state == 1) // Checks the upper right diag
        {
            curCell->numLiveNeighbors++;
        }
    }

    if (((curCell->y == 9) && (curCell->x != 0)) && ((curCell->y == 9) && (curCell->x != 9))) // If a cell is on the right column but NOT the corners
    {
        if (board[(curCell->x) - 1][(curCell->y) - 1]->state == 1) // Checks the upper left diag
        {
            curCell->numLiveNeighbors++;
        }

        if (board[curCell->x][(curCell->y) - 1]->state == 1) // Checks the left middle
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][(curCell->y) - 1]->state == 1) // Checks the lower left diag
        {
            curCell->numLiveNeighbors++;
        }
    }


    if (((curCell->x >= 1) && (curCell->x <= 8)) && ((curCell->y >= 1) && (curCell->y <= 8))) // If the curCell is a middle cell
    {
        if (board[(curCell->x) - 1][(curCell->y) - 1]->state == 1) // Checks the [(x-1),(y-1)]/top left cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) - 1][curCell->y]->state == 1) // Checks the [(x-1),y]/top middle cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) - 1][(curCell->y) + 1]->state == 1) // Checks the [(x-1),(y+1)]/top right cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[curCell->x][(curCell->y) - 1]->state == 1) // Checks the [x,(y-1)]/middle left cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[curCell->x][(curCell->y) + 1]->state == 1) // Checks the [x,(y+1)]/middle right cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][(curCell->y) - 1]->state == 1) // Checks the [(x+1),(y-1)]/bottom left cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][curCell->y]->state == 1) // Checks the [(x+1),y]/bottom middle cell
        {
            curCell->numLiveNeighbors++;
        }

        if (board[(curCell->x) + 1][(curCell->y) + 1]->state == 1) // Checks the [(x+1),(y+1)]/bottom right cell
        {
            curCell->numLiveNeighbors++;
        }
    }

*/
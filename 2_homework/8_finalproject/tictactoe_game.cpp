/*
Name: Anthony Streich
Date: 12 May 23
NAME/FUNCTION OF PROGRAM
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

enum Status { EMPTY, XINBOX, OINBOX };

using namespace std;

// struct box {
//     int stuff;
// };

void printBoard(int[]);

int main(int argc, char *argv[]) {
    int board[8];
    board[0] = 0;
    board[1] = 0;
    board[2] = 0;
    board[3] = 0;
    board[4] = 0;
    board[5] = 0;
    board[6] = 0;
    board[7] = 0;
    board[8] = 0;

    printBoard(board); // Prints the board
    

    return 0;
}

void printBoard(int board[]) {
    cout << " _____ _____ _____" << endl;
    cout << "|1    |2    |3    |" << endl;
    cout << "|  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;

    // Second row
    cout << " _____ _____ _____" << endl;
    cout << "|4    |5    |6    |" << endl;
    cout << "|  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;

    // Second three
    cout << " _____ _____ _____" << endl;
    cout << "|7    |8    |9    |" << endl;
    cout << "|  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;

}
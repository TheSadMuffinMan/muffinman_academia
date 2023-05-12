/*
Name: Anthony Streich
Date: 12 May 23
NAME/FUNCTION OF PROGRAM
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;

// struct box {
//     int stuff;
// };

void userXorO(bool&);
void printBoard(char[]);
void promptMove(bool, char[]);
void compMove(bool, char[]);
void checkWin(char[]);

int main(int argc, char *argv[]) {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // This is setting every char to a blank space

    bool userIsX = false;
    userXorO(userIsX); // Determines if the user is X or O 
    printBoard(board); // Prints the board

    promptMove(userIsX, board);
    printBoard(board);

    // promptMove(!userIsX, board);
    compMove(userIsX, board);
    printBoard(board);

    promptMove(userIsX, board);
    printBoard(board);

    compMove(userIsX, board);
    printBoard(board);

    promptMove(userIsX, board);
    printBoard(board);
    checkWin(board);

    compMove(userIsX, board);
    printBoard(board);
    checkWin(board);


    return 0;
}

void printBoard(char board[]) {
    cout << " \n _____ _____ _____" << endl;
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
    cout << "|_____|_____|_____|\n" << endl;
}

void userXorO(bool &userIsX) {
    cout << "REMEMBER, X always goes first." << endl;
    cout << "X or O? " << endl;
    string tempUserInput;
    cin >> tempUserInput;
    if (tempUserInput == "X" || tempUserInput == "x") {
        userIsX = true;
        cout << "DEBUG userisX = " << userIsX << endl;
    }
}

void promptMove(bool userIsX, char board[]) {
    int userSelection;
    cout << "Where would you like to move? " << endl;
    cin >> userSelection;

    if (userIsX == true) {
        board[userSelection - 1] = 'X';
    } else {
        board[userSelection - 1] = 'O';
    }
    cout << "DEBUG board[userSelection - 1]= " << board[userSelection - 1];
}

void compMove(bool userIsX, char board[]) {
    int userSelection;
    cout << "**DEBUG***Where would you like the \"computer\" to move? " << endl;
    cin >> userSelection;

    if (userIsX == true) {
        board[userSelection - 1] = 'O';
    } else {
        board[userSelection - 1] = 'X';
    }
    cout << "DEBUG board[userSelection - 1] = " << board[userSelection - 1];
}

int checkWin(char board[]) {
    if ((board[0] == board[1]) && (board[1] == board[2])) {
        if (board[0] == 'X') {
            cout << "X Win" << endl;
            return 1;
        } else if {
            cout << "O Win" << endl;
            return 2;
        }
    } else if ((board[4] == board[5]) && )
    return 0; // No one won
}

/*
Name: Anthony Streich
Date: 12 May 23
NAME/FUNCTION OF PROGRAM
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;

void userXorO(bool&);
void printBoard(char[]);
void promptMove(bool, char[]);
void compMove(bool, char[]);
void game(bool, char[], int&);
int checkWin(char[]);

int main(int argc, char *argv[]) {
    int counter = 0;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // This is setting every char to a blank space

    bool userIsX = false;
    userXorO(userIsX); // Determines if the user is X or O 
    printBoard(board); // Prints the board

    game(userIsX, board, counter);

/* Old (but working) manual way of doing things
    promptMove(userIsX, board); // Prompts the user for a move
    printBoard(board); // Prints the board

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
*/
    return 0;
}

void printBoard(char board[]) {
    cout << " \n _______ _______ _______" << endl;
    cout << "|1      |2      |3      |" << endl;
    cout << "|   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl;

    // Second row
    cout << "|4      |5      |6      |" << endl;
    cout << "|   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl;

    // Second three
    cout << "|7      |8      |9      |" << endl;
    cout << "|   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   |" << endl;
    cout << "|_______|_______|_______|\n" << endl;
}

void userXorO(bool &userIsX) {
    cout << "REMEMBER, X always goes first." << endl;
    cout << "X or O? " << endl;
    string tempUserInput;
    cin >> tempUserInput;
    if (tempUserInput == "X" || tempUserInput == "x") {
        userIsX = true;
        // cout << "DEBUG userIsX = " << userIsX << endl;
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
    // cout << "DEBUG board[userSelection - 1]= " << board[userSelection - 1];
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
    // cout << "DEBUG board[userSelection - 1] = " << board[userSelection - 1];
}

int checkWin(char board[]) {
    if ((board[0] == board[1]) && (board[1] == board[2])) { // TOP ROW WIN
        if (board[0] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    } else if ((board[3] == board[4]) && (board[4] == board[5])) { // MIDDLE ROW WIN
        if (board[4] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    } else if ((board[6] == board[7]) && (board[7] == board[8])) { // BOTTOM ROW WIN
        if (board[6] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    } else if ((board[0] == board[3]) && (board[3] == board[6])) { // LEFT COLUMN WIN
        if (board[0] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    } else if ((board[1] == board[4]) && (board[4] == board[7])) { // MIDDLE COLUMN WIN
        if (board[1] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    } else if ((board[2] == board[5]) && (board[5] == board[8])) { // RIGHT COLUMN WIN
        if (board[2] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    } else if ((board[0] == board[4]) && (board[4] == board[8])) { // \ DIAGONAL WIN
        if (board[0] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    } else if ((board[2] == board[4]) && (board[4] == board[6])) { // / DIAGONAL WIN
        if (board[2] == 'X') {
            cout << "X WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "O WIN DETECTED" << endl;
            return 2; }
    }
    return 0; // No one won
}

void game(bool userIsX, char board[], int &counter) {
    if (userIsX == true) {
        do {
            promptMove(userIsX, board); // Prompts the user for a move
            printBoard(board); // Prints the board
            counter++;

            compMove(userIsX, board);
            printBoard(board);
            counter++;
        } while (counter <= 4); /* This only lets the program run 5 times, which is the minimum amount of times you have to play
        before the checker is needed */
    } else {
        do {
            promptMove(userIsX, board); // Prompts the user for a move
            printBoard(board); // Prints the board
            counter++;

            compMove(userIsX, board);
            printBoard(board);
            counter++;
        } while (counter <= 4); // Same as above
    }
}

/*
Name: Anthony Streich
Date: 12 May 23
Tic-Tac-Toe!
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <random>

using namespace std;

void printBoard(char[]);
void userXorO(bool&);
bool notValidMove(char[], int);
void promptMove(bool, char[], int&);
void compMove(bool, char[], int&);
void game(bool, char[], int&, int);
int checkWin(char[]);
void writeData(fstream&, char[], int);

int main(int argc, char *argv[]) {
    int counter = 0;
    srand(time(0)); // This initializes the random value by marking the exact time, which will create a unique seed.

    // int numberGames = 0;
    // int numberPlayerWin = 0;
    // int numberCompWin = 0;
    // int numberDraws = 0;

    int userSelection;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // This is setting every char to a blank space

    bool userIsX = false;
    userXorO(userIsX); // Determines if the user is X or O 
    printBoard(board); // Prints the board

    game(userIsX, board, counter, userSelection);

    fstream fs;
    fs.open("files/fstemp.txt", fstream::in | fstream::out | fstream::app);
    fs.seekg(0);
    writeData(fs, board, counter);
    fs.close();

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

// NEED TO ADD CASE TO ENSURE INPUT IS AN INT
bool notValidMove(char board[], int userSelection) { /* This is the function that checks input */
    if ((board[userSelection - 1] == 'X') || (board[userSelection - 1] == 'O')) { /* Checks to see if anything has already been
    put there */
        cout << "There is already a character there. Please input a different box.\n";
        return true;
    } else if ((userSelection >= 10) || (userSelection <= 0)) { /* Checks to see if input is between 1-9 */
        cout << "Your selection is not within 1 to 9. Please try again.\n";
        return true;
    } else { // Otherwise, the input is valid and is accepted by the program
        return false;
    }
}

void promptMove(bool userIsX, char board[], int &userSelection) {
    cout << "Where would you like to move? " << endl;
    cin >> userSelection;
    
    while (notValidMove(board, userSelection) == true) {
        cin >> userSelection;
    }
        
    if (userIsX == true) {
        board[userSelection - 1] = 'X';
    } else {
        board[userSelection - 1] = 'O'; }
}
    // cout << "DEBUG board[userSelection - 1] = " << board[userSelection - 1];

void compMove(bool userIsX, char board[], int &userSelection) {
    // cout << "**DEBUG***Where would you like the \"computer\" to move? " << endl;
    // cin >> userSelection;

    userSelection = ((rand()%9));
    cout << "***DEBUG*** userSelection: " << userSelection << endl;

    while (notValidMove(board, userSelection) == true) {
        cin >> userSelection;
    }

    if (userIsX == true) {
        board[userSelection - 1] = 'O';
    } else {
        board[userSelection - 1] = 'X';
    }
    // cout << "DEBUG board[userSelection - 1] = " << board[userSelection - 1];
}


int checkWin(char board[]) {
    if ((board[0] != ' ') && (board[0] == board[1]) && (board[1] == board[2])) { // TOP ROW WIN
        if (board[0] == 'X') {
            cout << "***DEBUG*** X TOP ROW WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O TOP ROW WIN DETECCTED" << endl;
            return 2; }
    } else if ((board[3] != ' ') && (board[3] == board[4]) && (board[4] == board[5])) { // MIDDLE ROW WIN
        if (board[4] == 'X') {
            cout << "***DEBUG*** X MIDDLE ROW WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O MIDDLE ROW WIN DETECTED" << endl;
            return 2; }
    } else if ((board[6] != ' ') && (board[6] == board[7]) && (board[7] == board[8])) { // BOTTOM ROW WIN
        if (board[6] == 'X') {
            cout << "***DEBUG*** X BOTTOM ROW WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O BOTTOM ROW WIN DETECTED" << endl;
            return 2; }
    } else if ((board[0] != ' ') && (board[0] == board[3]) && (board[3] == board[6])) { // LEFT COLUMN WIN
        if (board[0] == 'X') {
            cout << "***DEBUG*** X LEFT COLUMN WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O LEFT COLUMN WIN DETECTED" << endl;
            return 2; }
    } else if ((board[1] != ' ') && (board[1] == board[4]) && (board[4] == board[7])) { // MIDDLE COLUMN WIN
        if (board[1] == 'X') {
            cout << "***DEBUG*** X MIDDLE COLUMN WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O MIDDLE COLUMN WIN DETECTED" << endl;
            return 2; }
    } else if ((board[2] != ' ') && (board[2] == board[5]) && (board[5] == board[8])) { // RIGHT COLUMN WIN
        if (board[2] == 'X') {
            cout << "***DEBUG*** X RIGHT COLUMN WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O RIGHT COLUMN WIN DETECTED" << endl;
            return 2; }
    } else if ((board[0] != ' ') && (board[0] == board[4]) && (board[4] == board[8])) { // \ DIAGONAL WIN
        if (board[0] == 'X') {
            cout << "***DEBUG*** X LTR DIAGONAL WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O LTR DIAGONAL WIN DETECTED" << endl;
            return 2; }
    } else if ((board[2] != ' ') && (board[2] == board[4]) && (board[4] == board[6])) { // / DIAGONAL WIN
        if (board[2] == 'X') {
            cout << "***DEBUG*** X / DIAGONAL WIN DETECTED" << endl;
            return 1;
        } else {
            cout << "***DEBUG*** O / DIAGONAL WIN DETECTED" << endl;
            return 2;
        } 
    } return 0; // No one won
}

void game(bool userIsX, char board[], int &counter, int userSelection) {
    if (userIsX == true) {
        while ((checkWin(board) != '0') && (checkWin(board) != '1') && (checkWin(board) != '2')) {
            promptMove(userIsX, board, userSelection); // Prompts the user for a move
            printBoard(board); // Prints the board
            counter++;

            if (counter >= 9) { // Ensures that the loop does not exceed 9 iterations
                break;
            } else if (checkWin(board) == 1) { // Ensures the loop breaks if a draw is detected
                cout << "X Win\n";
                break;
            } else if (checkWin(board) == 2) { // Ensures the loops breaks if an X win is detected
                cout << "O win\n";
                break;
            } else if (counter == 8) {
                cout << "Draw\n";
                break;
            }
                // } else if (checkWin(board) == 0) { // Ensures the loop breaks if an O win is detected
                //     cout << "No winner, draw\n";
                //     break;

            compMove(userIsX, board, userSelection);
            printBoard(board);
            checkWin(board);

            counter++;
            if (counter >= 9) { // Ensures that the loop does not exceed 9 iterations
                break;
            } else if (checkWin(board) == 1) { // Ensures the loop breaks if a draw is detected
                cout << "X Win\n";
                break;
            } else if (checkWin(board) == 2) { // Ensures the loops breaks if an X win is detected
                cout << "O win\n";
                break;
            } else if (counter == 8) {
                cout << "Draw\n";
                break;
            }
                // } else if (checkWin(board) == 0) { // Ensures the loop breaks if an O win is detected
                //     cout << "No winner, draw\n";
                //     break;

            cout << "\n***DEBUG*** counter: " << counter << endl;
        }

    } else { // All of this code is just a copy of the code above, except for O's
        while ((checkWin(board) != '0') && (checkWin(board) != '1') && (checkWin(board) != '2')) {
            promptMove(userIsX, board, userSelection); // Prompts the user for a move
            printBoard(board); // Prints the board
            checkWin(board);

            counter++;
            if (counter <= 8) { // Ensures that the loop does not exceed 9 iterations
                break;
            } else if (checkWin(board) == 0) {
                cout << "Draw\n";
                break;
            } else if (checkWin(board) == 1) {
                cout << "X win\n";
                break;
            } else if (checkWin(board) == 2) {
                cout << "O win\n";
                break;
            }

            compMove(userIsX, board, userSelection);
            printBoard(board);
            checkWin(board);

            counter++;
            if (counter <= 9) { // Ensures that the loop does not exceed 9 iterations
                break;
            } else if (checkWin(board) == 0) { // If the loop returns 0, it's a draw
                cout << "Draw\n";
                break;
            } else if (checkWin(board) == 1) { // If the loop returns 1, it's an X win
                cout << "X win\n";
                break;
            } else if (checkWin(board) == 2) { // If the loop returns 2, it's an O win
                cout << "O win\n";
                break;
            }

            cout << "\n***DEBUG*** counter: " << counter << endl;
        }

    }
}

void writeData(fstream& fout, char board[], int counter) {
    for(int i = 0; i < counter; i++) {
        cout << "board[" << i << "]: " << board[i] << endl;
    }
}
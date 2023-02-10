/* Howdy!

Name: Anthony Streich
9 Feb 2023

This program is meant to replicated the various stages of the classic game, hangman.

Uh.. Other programming info?
*/

#include <iostream>

using namespace std;

int main() {
    cout << "Greetings gamer, please enter your full name: ";
    string full_name;
    getline(cin, full_name);

    cout << "Welcome " << full_name << ".\n" << endl;
    cout << "The hangman game is under construction, maybe you\'ll get to play it in a few weeks…" << endl;
    cout << "This is what various stages of the hangman game will look like… \n \n";


    string line_1 = " |----------------- \n";
    string line_2 = " |/        	|  \n";
    string line_3 = " |\n";
    string line_4 = " |\n";
    string line_5 = " |\n";
    string line_6 = " |\n";
    string line_7 = " |\n";
    string line_8 = " |\n";
    string line_9 = "  ===========\n";
 
    cout << line_1 << line_2 << line_3 << line_4 << line_5 << line_6 << line_7 << line_8 << line_9;


    return 0;
}
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

    string line_3_dead = " |             O\n";
    string line_4_dead = " |             |\n";
    string line_4_dead_left = " |            /|\n";
    string line_4_dead_right = " |            /|\\ \n";
    string line_5_dead = " |\n";
    string line_6_dead = " |\n";
 

    cout << "This is Stage 0.\n";
    cout << line_1 << line_2 << line_3 << line_4 << line_5 << line_6 << line_7 << line_8 << line_9;

    cout << "This is Stage 5.\n";
    cout << line_1 << line_2 << line_3_dead << line_4_dead << line_4_dead_left << line_4_dead_right;

    return 0;
}
/*
    StdIO Lab
    ASCII Art - using literals and variables
    
    Updated By: Anthony Streich #FIXME1
    Date: 8 February 23 #FIXME2
    
    This program produces an ASCII art on the console.
    Algorithm steps: 
    1. Use variables to store data/values
    2. Write a series of cout statements to print the data/values
*/

#include <iostream> //library for input and output
#include <string> //library for string data
 
using namespace std; //resolve cout, cin, and endl names
 
//main entry point of the program
int main()
{
    //FIXME3: declare a variable to store name #fixed#
    string full_name;
    //FIXME4: prompt user to enter their name and store the value in variable #fixed#
    cout << "Hello, and welcome to my program. Please input your name: ";
    getline(cin, full_name);
    
    //FIXME5: greet the name using the variable as the following output #fixed#
    cout << "Nice meeting you, " << full_name << "! \n " << endl;
    //must output: Nice meeting you, <name>!

    cout << "Hope you like my Tom & Jerry ASCII art...\n\n";

    string line1 = "   |\\_/|   **********************    (\\_/)\n ";
    cout << line1;

    //FIXME6: use variable to print the second line line of the graphic #fixed#
    string line2 = " / @ @ \\  *     ASCII Lab      *   (='.'=) \n ";
    cout << line2;

    //FIXME7: print the third line of the graphics #fixed#
    string line3 = "( > 0 < ) * By: Anthony Streich* ( \" )_\( \" ) \n";
    cout << line3;

    //FIXME8: use variable to print the fourth line #fixed#
    string line4 = "   >>x<<   *      CSCI 111      * \n";
    cout << line4;

    //FIXME9: use variable to print the fifth line #fixed#
    string line5 = "  /  O  \\  ********************** \n";
    cout << line5;

    //Note: You can add more lines or print more ASCII arts of your choice if you'd like...

    char input;
    cout << "\nGood bye... hit any key to exit the program: ";
    cin.get(input); // HAD TO HAVE STUDENT AID HELP
    //FIXME10: make the console wait for user input
    return 0; //exit program by returning 0 status to the system
}
// Footer
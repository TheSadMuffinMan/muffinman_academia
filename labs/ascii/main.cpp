/*
    StdIO Lab
    ASCII Art - using literals and variables
    
    Updated By: Anthony Streich #FIXME1 FIXED
    Date: 8 February 23 #FIXME2 FIXED
    
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
    //FIXME3: FIXED declare a variable to store name
    string full_name;
    //FIXME4: FIXED prompt user to enter their name and store the value in variable
    cout << "Hello, and welcome to my program. Please input your name: ";
    cin >> full_name;
    
    //FIXME5: KINDA FIXED greet the name using the variable as the following output
    cout << "Nice meeting you, " << full_name << "! \n " << endl;
    //must output: Nice meeting you, <name>!

    cout << "Hope you like my Tom & Jerry ASCII art...\n\n";

    string line1 = "   |\\_/|   **********************    (\\_/)\n ";
    cout << line1;

    //FIXME6:  FIXED use variable to print the second line line of the graphic
    string line2 = " / @ @ \\  *     ASCII Lab      *   (='.'=) \n ";
    cout << line2;

//FIXME7: FIXED print the third line of the graphics
    string line3 = "( > 0 < ) * By: Anthony Streich* ( \" )_\( \" ) \n";
    cout << line3;

    //FIXME8: FIXED use variable to print the fourth line
    string line4 = "   >>x<<   *      CSCI 111      * \n";
    cout << line4;

    //FIXME9: FIXED use variable to print the fifth line
    string line5 = "  /  O  \\  ********************** \n";
    cout << line5;

    //Note: You can add more lines or print more ASCII arts of your choice if you'd like...

    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    //FIXME10: make the console wait for user input

    return 0; //exit program by returning 0 status to the system
}
// Footer
/*
Name: Anthony Streich
Date: 5 September 2023
SELF JEOPARDY, the stupid version
CURRENT ISSUES: 
*/

#include <iostream>
#include "selfJeopardyHeader.h"

#define clear() system("clear")

using namespace std;

int main(int argc, char *argv[])
{
    string tempVariable;
    clear();
    cout << "Program is ready to proceed. Press any key to continue. . ." << endl;
    getline(cin, tempVariable);

    clear();
    cout << "Welcome to. . ." << endl;
    cout << " _____ _____ _     ______     ___ _____ ___________  ___  ______________   __" << endl;
    cout << "/  ___|  ___| |    |  ___|   |_  |  ___|  _  | ___ \\/ _ \\ | ___ \\  _  \\ \\ / /" << endl;
    cout << "\\ `--.| |__ | |    | |_        | | |__ | | | | |_/ / /_\\ \\| |_/ / | | |\\ V / "<< endl;
    cout << " `--. \\  __|| |    |  _|       | |  __|| | | |  __/|  _  ||    /| | | | \\ /" << endl;
    cout << "/\\__/ / |___| |____| |     /\\__/ / |___\\ \\_/ / |   | | | || |\\ \\| |/ /  | |  " << endl;
    cout << "\\____/\\____/\\_____/\\_|     \\____/\\____/ \\___/\\_|   \\_| |_/\\_| \\_|___/   \\_/" << endl;
    cout << "\nPress any key to continue. . ." << endl;
    getline(cin, tempVariable);
    clear();

    printMenu();


    return 0;
}
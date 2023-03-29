/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
    string firstName;
    string lastName;
    string fullName;
    char someChar;

    cout << "What is your first name?: " << endl;
    getline(cin, firstName);

    cout << "What is your last name?: " << endl;
    getline(cin, lastName);

    fullName = firstName + lastName;

    cout << "Welcome " << fullName << endl;

    cout << "The length of your string is: " << fullName.length() << endl;
    for(size_t i = 0; i < fullName.length(); i++){
        // cout << "fullName[" << i << "]: " << fullName[i] << endl;
        fullName[i] = toupper(fullName[i]);
    }

    cout << "Your name in uppercase is: " << fullName << endl;
    
    return 0;
}
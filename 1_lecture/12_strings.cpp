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
    // char someChar;

    cout << "What is your first name?: " << endl;
    getline(cin, firstName);

    cout << "What is your last name?: " << endl;
    getline(cin, lastName);

    fullName = firstName + lastName;

    cout << "Welcome " << fullName << endl;
    cout << "The length of your string is: " << fullName.length() << endl;

/*
    // This is how to switch cases with strings
    for(size_t i = 0; i < fullName.length()+1; i++){
        cout << "fullName[" << i << "]: " << fullName[i] << endl;
        cout << "fullName.at(" << i << "):" << fullName.at(i) << endl;
        fullName[i] = toupper(fullName[i]);
    }
*/

/*
    // This will just add another set of characters to whatever you want to add it to.
    fullName.append(" is awesome!");
    cout << fullName << endl;
    fullName = fullName + " is awesome!"; // These two are functionally the same
*/

    // cout << "fullName.begin(): " << *fullName.begin() << endl;
    // for(auto i = fullName.begin(); i != fullName.end(); i++){
    //     cout << *i << endl;
    //     cout << "This character is at index: " << fullName.find(*i) << endl;
    // }

    cout << "e is at index: " << fullName.find('e', 0) << endl;
    cout << "e is at index: " << fullName.find('e', 2) << endl;
    cout << "e is at index: " << fullName.find('e', 4) << endl;


    inf foundIndex = 0;
    for(auto i = fullName.begin; i != fullName.end(); i++){
        foundIndex = fullName.find('e');
    }


    return 0;
}
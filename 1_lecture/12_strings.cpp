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
    string phrase;
    string searchStr;

    phrase = "How much wood could a woodchuck chuck if a woodchuck could chuck wood";

    string subStrWords[phrase.length()];

    cout << "What do you want to search for?: ";
    getline(cin, searchStr);

    int woodIndex = 0;
    for(size_t i = 0; i < phrase.length(); i++){
        i = phrase.find(searchStr, i);
        if(i != string::npos){
            cout << "Found at index: " << i << endl;
            subStrWords[woodIndex]= phrase.substr(i, 4);
            woodIndex++;
        } else {
            break;
        }
    }

    for(int i = 0; i <4; i++){
        cout << "subStrWords[" << i << "]: " << subStrWords[i] << endl;
    }
    
    return 0;
}

//     string firstName;
//     string lastName;
//     string fullName;
//     string fullLowerName;
//     string space = " ";
//     string searchStr;
//     // char someChar;

//     cout << "What is your first name?: " << endl;
//     getline(cin, firstName);

//     cout << "What is your last name?: " << endl;
//     getline(cin, lastName);

//     fullName = firstName + space + lastName;
//     fullLowerName = fullName;

//     cout << "Welcome " << fullName << endl;
//     cout << "The length of your string is: " << fullName.length()-1 << endl;

// /*
//     // This is how to switch cases with strings
//     for(size_t i = 0; i < fullName.length()+1; i++){
//         cout << "fullName[" << i << "]: " << fullName[i] << endl;
//         cout << "fullName.at(" << i << "):" << fullName.at(i) << endl;
//         fullName[i] = toupper(fullName[i]);
//     }
// */

// /*
//     // This will just add another set of characters to whatever you want to add it to.
//     fullName.append(" is awesome!");
//     cout << fullName << endl;
//     fullName = fullName + " is awesome!"; // These two are functionally the same
// */

//     // cout << "fullName.begin(): " << *fullName.begin() << endl;
//     // for(auto i = fullName.begin(); i != fullName.end(); i++){
//     //     cout << *i << endl;
//     //     cout << "This character is at index: " << fullName.find(*i) << endl;
//     // }

// /*
//     cout << "e is at index: " << fullName.find('e', 0) << endl;
//     cout << "e is at index: " << fullName.find('e', 2) << endl;
//     cout << "e is at index: " << fullName.find('e', 4) << endl;
// */

//     // int foundIndex = 0;
//     // for(auto i = fullName.begin; i != fullName.end(); i++){
//     cout << "What do you want to search for in your string?: ";
//     getline(cin, searchStr);


//     // This sets the case of the entire string to lower case, meaning that user input will not matter case-wise
//     for(size_t i = 0; i < fullName.length()+1; i++){
//         fullLowerName[i] = toupper(fullLowerName[i]);
//     }

//     for(size_t i = 0; i < searchStr.size(); i++) {
//         searchStr.at(i) = tolower(searchStr.at(i));
//     }

//     for(size_t i = 0; i < fullLowerName.length(); i++){
//         i = fullLowerName.find(searchStr, i);
//         if(i != string::npos){
//             cout << "Found character at index: " << i << endl;
//         } else {
//             break;
//         }
//     }

//     string tmpStr = fullName.substr(3, 9);
//     cout << "tmpStr: " << tmpStr << endl;


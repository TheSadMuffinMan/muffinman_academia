/*
Name: Anthony Streich
Lunch decision program!
*/

#include <iostream>
#include <string>

using namespace std;

void prompt_name(string&);
void greet_name();

int main() {
    string user_name;

    prompt_name(victims_name);
    greet_name(victims_name);

    return 0;
}

void prompt_name(string &name) {
    cout << "Please enter your full name: " << endl;
    getline(cin, name);
}

void greet_name(string name){
    cout << "Welcome " << name << " to our lunch picker!" << endl;
}
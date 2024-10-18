#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string name;
    cout << "Enter your first and last name: ";
    getline(cin, name);

    // Converts first/last to last/first
    int space = name.find(" "); // We are looking for the first space in the string
    if (space != string::npos)
    {
        string lastNameFirst = name.substr(space + 1);
        lastNameFirst += ", " + name.substr(0, space);
        name = lastNameFirst;
    }
    cout << "Hello, " << name << endl;

    return 0;
}
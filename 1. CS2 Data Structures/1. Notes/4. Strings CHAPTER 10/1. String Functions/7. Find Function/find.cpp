// <string> find()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string s1("Welcome to HTML");

    cout << s1.find("co") << endl; // Returns 3
    cout << s1.find("co", 6) << endl; // Returns string::npos
    cout << s1.find('o') << endl; // Returns 4
    cout << s1.find('o', 6) << endl; // Returns 9

    string s("abcdefag");
    cout << s.find("def") << " " << s.find("a", 3);

    return 0;
}
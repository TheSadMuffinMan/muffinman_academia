// <string> substr() and .at()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string s1("Welcome");

    cout << s1.substr(0, 1) << endl; // Returns 'W'
    cout << s1.substr(3) << endl; // Returns "come"
    cout << s1.substr(3, 3) << endl; // Returns "com"

    return 0;
}
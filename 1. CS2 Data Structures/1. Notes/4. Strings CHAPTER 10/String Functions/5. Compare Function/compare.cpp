// <string> compare()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string s1("Welcome");
    string s2("Welcomg");

    cout << s1.compare(s2) << endl; // Returns -1
    cout << s2.compare(s1) << endl; // Returns 1
    cout << s1.compare("Welcome") << endl; // Returns 0

    string s("abcdefg");
    cout << s.compare("abb") << endl;

    return 0;
}
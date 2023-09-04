// <string> .at() .erase() .empty()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string s1("Welcome");
    cout << s1.at(3) << endl; // s1.at(3) returns 'c'
    cout << s1.erase(2,3) << endl; // s1 is now "Weme"

    s1.clear(); // s1 is now empty
    cout << s1.empty() << endl; // s1.empty returns '1' (means statement is true)
    
    string s("abcdefg");
    s.erase(2, 3);
    cout << s << endl;

    return 0;
}
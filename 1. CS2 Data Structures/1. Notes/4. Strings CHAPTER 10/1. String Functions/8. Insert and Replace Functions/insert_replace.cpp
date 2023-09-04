// <string> insert() and replace()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string s1("Welcome to HTML");
    s1.insert(11, "C++ and ");
    cout << s1 << endl; // s1 becomes "Welcome to C++ and HTML"

    string s2("AA");
    s2.insert(1, 4, 'B');
    cout << s2 << endl; // s2 becomes "to ABBBBA"

    string s3("Welcome to HTML");
    s3.replace(11, 4, "C++");
    cout << s3 << endl; // s3 becomes "Welcome to C++"

    string s("abcdefg");
    s.insert(1, 3, 'w');
    cout << s << endl;

    return 0;
}
// <string> .at() .erase() .empty()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string s1("Welcome");
    cout << s1.length() << endl; // Length is 7
    cout << s1.size() << endl; // Size is 7
    cout << s1.capacity() << endl; // Capacity is 15

    s1.erase(1, 2);
    cout << s1.length() << endl; // Length is now 5
    cout << s1.size() << endl; // Size is now 5
    cout << s1.capacity() << endl; // Capacity is still 15

    return 0;
}
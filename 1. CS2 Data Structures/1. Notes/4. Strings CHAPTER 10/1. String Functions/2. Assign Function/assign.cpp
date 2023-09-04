// <string> assign()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string stringObject("Welcome");
    stringObject.assign("Dallas"); // Assigns "Dallas" to stringObject
    cout << stringObject << endl; // stringObject now becomes "Dallas"

    stringObject.assign("Dallas, Texas", 0, 5); // Assigns "Dalla" to stringObject
    cout << stringObject << endl; // stringObject now becomes "Dalla"

    stringObject.assign("Dallas, Texas", 5); // Assigns "Dalla" to stringObject
    cout << stringObject << endl; // stringObject now becomes "Dalla"

    stringObject.assign(4, 'G'); // Assigns "GGGG" to stringObject
    cout << stringObject << endl; // stringObject now becomes "GGGG"

    // string s("abc");
    // s.assign("welcome", 0, 3);
    // cout << s << endl;

    // string s("abc");
    // s.assign("welcome", 3);
    // cout << s << endl;

    string s("abc");
    s.assign(3, 'w');
    cout << s << endl;

    return 0;
}
// <string> append()

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string s1("Welcome");
    s1.append(" to C++"); // Appends " to C++" to s1
    cout << s1 << endl; // s1 now becomes "Welcome to C++"

    string s2("Weclcome");
    s2.append(" to C and C++", 0, 5); // Appends " to C" to s2
    cout << s2 << endl; // s2 now becomes "Welcome to C"

    string s3("Weclcome");
    s3.append(" to C and C++", 5); // Appends " to C" to s3
    cout << s3 << endl; // s3 now becomes "Welcome to C"

    string s4("Welcome");
    s4.append(4, 'G'); // Appends "GGGG" to s4
    cout << s4 << endl; // s4 now becomes WelcomeGGGG
    
    return 0;
}
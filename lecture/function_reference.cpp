/*
Name: Anthony Streich
Functions pass-by-reference/pass-by-value
*/

#include <iostream>

using namespace std;

template <class T1, class T2>
void prompt_sides(int&, int&);

int main() {
    float s1, s2;

    // cout << "The memory address inside of main for s1 is: " << &s1 << endl;
    prompt_sides<int, int>(s1, s2);

    // cout << "The memory address inside of main for s2 is: " << &s2 << endl;
    // prompt_sides(s2);

    cout << "You entered: " << s1 << " " << s2 << endl;

    return 0;
}


template <class T1, class T2)
void prompt_sides(int &side1, int &side2) {
    // cout << "The memory address inside the prompt_sides is :" << &side1 << endl;

    cout << "Please enter the sides of a rectangle: ";
    cin >> side1 >> side2;

    // return side1;
}
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a, b;
    cout << "\nA term: ";
    cin >> a;

    cout << "\nB term: ";
    cin >> b;

    int c = a * b;
    int cMod_a = c%a;
    int cMod_b = c%b;

    cout << "cMod_a: " << cMod_a << endl;
    cout << "cMod_b: " << cMod_b << endl;
    
    return 0;
}
#include <iostream>
using namespace std;

void findSmallest(int* a, int* b, int* c); // This function takes in 3 ints and sorts them from smallest to largest

int main(int argc, const char *argv[])
{
    int a, b, c;
    findSmallest(a, b, c);
}

void findSmallest(int* a, int* b, int* c)
{
    cout << "First int: ";
    int tempA;
    cin >> tempA;

    cout << "\nSecond int: ";
    int tempB;
    cin >> tempB;

    cout << "\nThird int: ";
    int tempC;
    cin >> tempC;

    int tempArray[3];
    if (tempA > tempB)
    {
        tempArray[1] = tempA;
    }

}

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int inputInt;
    std::cin >> inputInt;

    int arr[64];
    int i = 0;
    int r;

    while (inputInt != 0)
    {
        r = inputInt % 2;
        arr[i++] = r;
        inputInt /= 2;
    }

    return 0;
}
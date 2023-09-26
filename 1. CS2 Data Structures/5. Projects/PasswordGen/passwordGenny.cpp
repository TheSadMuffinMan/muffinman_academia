#include "passwordGennyHeader.h"

#include <iostream>
#include <string>
#include <random>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello. Max size is 20 chars. Allowed chars:" << endl;
    cout << "\t! $ ( ) . / : ; ? @" << endl;

    size_t pwSize = 1;
    bool pwSizeValid = false;

    while (pwSizeValid == false)
    {
        cout << "Input size_t pwSize: ";
        cin >> pwSize;

        if (pwSize >= 1 && pwSize <= 21)
        {
            pwSizeValid = true;
        }

        if (pwSizeValid == true)
        {
            break;
        }
    }
    
    // do
    // {
    //     cout << "pwSize: ";
    //     cin >> pwSize;

    //     if (pwSize >= 1 && pwSize <= 21)
    //     {
    //         pwSizeValid = true;
    //         break;
    //     }
    //     else
    //     {
    //         cout << "Invalid input. Try again." << endl;
    //         cin >> pwSize;
    //         // break;
    //     }
    // }
    // while (pwSizeValid == false);

    srand(time(0));


    // do
    // {
    //     cout << "pwSize: ";
    //     cin >> pwSize;
    // }
    // while (pwSize >= 1 && pwSize <= 20);
    
    // while (cin >> pwSize)
    // {
    //     if (pwSize >= 1 && pwSize <= 20)
    //     {
    //         cout << "Invalid input. Try again. ";
    //         cin >> pwSize;
    //     } else
    //     {
    //         break;
    //     }
    // }

    // while (pwSize >= 1 && pwSize <= 20)
    // {
    //     cout << "How large would you like your password to be? ";
    //     cin >> pwSize;
    //     break;
    // }

    cout << "pwSize value: " << pwSize << endl;

    cout << "\n\nEnd of program." << endl;
    return 0;
}
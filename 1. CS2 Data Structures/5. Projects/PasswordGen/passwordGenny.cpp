#include "passwordGennyHeader.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello. Max size is 20 chars. Allowed chars:" << endl;
    cout << "\t! $ ( ) . / : ; ? @" << endl;

    int pwSize = 1;
    cleanedPWSize(pwSize); // Checks user input and doesn't allow user to continue unless input is good

    srand(time(0)); // Initializes random seed to current time

    char pwArray[pwSize];
    // cout << "pwArray[] size: " << sizeof(pwArray) << endl;

    cout << "\n\nEnd of program." << endl;
    return 0;
}
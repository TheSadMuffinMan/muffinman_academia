#include "passwordGennyHeader.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello. No theoretical limit to #chars, but you need more than 9. Allowed chars:" << endl;
    cout << "\t! $ ( ) . / : ; ? @" << endl;

    int pwSize = 1;
    cleanedPWSize(pwSize); // Checks user input and doesn't allow user to continue unless input is good

    srand(time(NULL)); // Initializes random seed to current time

    cleanASCIIVal();

    vector<int> pwVector;
    for (int i = 0; i < pwSize; i++)
    {
        int tempVar;
        tempVar = cleanASCIIVal();
        pwVector.push_back(tempVar);
        cout << "pwVector[" << i << "] value: " << pwVector.at(i) << endl;
    }

    cout << "\n\nEnd of program." << endl;
    return 0;
}
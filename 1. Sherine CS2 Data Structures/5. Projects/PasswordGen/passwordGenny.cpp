#include "passwordGenny.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello. No theoretical limit to # chars. Allowed chars:" << endl;
    cout << "\t! $ ( ) / : ; ? @" << endl;

    int pwSize = 1;

    cleanedPWSize(pwSize); // Checks user input and doesn't allow user to continue unless input is good

    srand(time(NULL)); // Initializes random seed to current time

    vector<int> pwVector; // Creates the vector

    for (int i = 0; i < pwSize; i++) // Fills the vector with clean values
    {
        int tempVar;
        tempVar = cleanASCIIVal();
        pwVector.push_back(tempVar);
        // cout << "pwVector[" << i << "] value: " << pwVector.at(i) << endl;
    } // pwVector is now full of ints that correlate to ASCII values that I like

    pwVector.shrink_to_fit(); // Makes it so that our vector's size is appropriate
    // cout << "Size of pwVector: " << pwVector.size();

    for (int i = 0; i < pwVector.size(); i++) // Casting each value to an ASCII char and then printing it
    {
        cout << (char)pwVector.at(i);
    }

    cout << "\n\nEnd of program..." << endl;
    return 0;
}
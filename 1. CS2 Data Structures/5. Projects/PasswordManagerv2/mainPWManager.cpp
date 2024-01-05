#include "PWManager.h"
#include "PWObject.h"

using namespace std;

int main(int argc, char *argv[])
{
    welcomeFunction();
    populateArray();

    // Main program loop
    while(true)
    {
        printAllLabels();
    }
    return 0;
}
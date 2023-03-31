// PLAYGROUND

#include <iostream>
#include <string>

using namespace std;

bool keepRunning(char&);

int main(int argc, char *argv[]) {
    char quitChar = 0;
    keepRunning(quitChar);
    return 0;
}
bool keepRunning(char &quitChar){
    bool running = true;
    while(running == true){
        if(quitChar != 'y'){
            return false;
        }
    } return true;
}
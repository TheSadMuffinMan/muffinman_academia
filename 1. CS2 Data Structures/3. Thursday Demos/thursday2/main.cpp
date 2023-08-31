/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
CURRENT ISSUES: 
*/

#include <iostream>

using namespace std;

struct song
{ // This is ensuring the data fits in our struct by sizing the struct to the standard.
    char header[3];
    char songTitle[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[29];
    char trackNumber[1];
    char genre[1];
};

int main(int argc, char *argv[]) {
    
    song testSong;
    cout << "Size of song is: " << sizeof(testSong) << endl;

    return 0;
}
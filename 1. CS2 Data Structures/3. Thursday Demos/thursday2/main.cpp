/*
Name: Anthony Streich
Date: 31 August 23
Practicum 2
CURRENT ISSUES: Streams
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype> // Allows for binary file manipulation

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

int main(int argc, char *argv[])
{
    // song testSong;
    // cout << "Size of song is: " << sizeof(testSong) << endl;

    char fname[64], comment [29], ch;
    fstream fs;
    size_t fileLength;

    cout << "Please enter filename with a .mp3 extension: " << endl;
    cin.getline(fname, 64, '\n');

    if (strcmp(&fname[strlen(fname) - 4], ".mp3") != 0)
    {
        cerr << "File does not end with an .mp3 extension... Terminating." << endl;
        exit(1);
    }
    
    fs.open(fname, ios::in | ios::out | ios::binary);
    if(!fs.open())
    {
        cerr << "File could not be opened... Terminating" << endl;
        exit(2);
    }
    fs.seekg(0, ios::end);
    fileLength = fs.tellg();

    cout << "The file is " << fileLength << " bytes long." << endl;
    fs.seekg(-128, ios::end);

    return 0;
}
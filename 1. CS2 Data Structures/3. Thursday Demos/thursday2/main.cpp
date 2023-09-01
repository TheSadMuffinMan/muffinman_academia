/*
Name: Anthony Streich
Date: 1 September 23
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
    if(!fs.is_open())
    {
        cerr << "File could not be opened... Terminating" << endl;
        exit(2);
    }
    fs.seekg(0, ios::end);
    fileLength = fs.tellg();

    cout << "The file is " << fileLength << " bytes long." << endl;
    fs.seekg(-128, ios::end);
    cout << "Current read position: " << fs.tellg() << endl;

    song currentSong; // Creates an instance of the Struct song, and names it currentSong.

    fs.read(currentSong.header, 3); // This reads the fs stream and stores 3 chars into currentSong.header
    cout << "\ncurrentSong.header : " << currentSong.header << endl;

    fs.read(currentSong.songTitle, 30); // This reads the song title into currentSong.songTitle
    fs.read(currentSong.artist, 30);
    fs.read(currentSong.album, 30);
    fs.read(currentSong.year, 4);
    fs.read(currentSong.comment, 29);
    fs.read(currentSong.trackNumber, 1);
    fs.read(currentSong.genre, 1); // At this point, we have all the data "in" our struct


    return 0;
}
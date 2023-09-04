/* ***QUESTION 3*** Missed even tho my version is better lol
Assume that sentence is a variable of type string that has been assigned a value.
Assume furthermore that this value is a string consisting of words separated by single space characters with a period at the end.
For example: "This is a possible value of sentence."
Assume that there is another variable declared, secondWord, also of type string.
Write the statements needed so that the second word of the value of sentence is assigned to secondWord.
So, if the value of sentence were "Broccoli is delicious." your code would assign the value "is " to secondWord.
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string sentence, secondWord;
    cout << "Sentence: ";
    getline(cin, sentence);

    int space = sentence.find(" "); // We are looking for the first space in the string
    cout << "space: " << space << endl;

    int space2 = sentence.find(" ", space + 1);
    cout << "space2: " << space2 << endl;

    secondWord = sentence.substr(space, (space2 - space));
    cout << "secondWord: " << secondWord << endl;

    return 0;
}

/* BOOK SOLUTION BOOOOOOORING
int k = sentence.find(" ");
string temp = sentence.substr(k + 1);
secondWord = temp.substr(0, temp.find(" "));
*/
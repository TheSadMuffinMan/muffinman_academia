/*
Name: Anthony Streich
Date: 2 May 23
English 112 Companion Piece
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>
#include <random>

using namespace std;

using money_int = long long int; /* This creates a new type of variable that can hold really large values. This is needed because
a regular variable type of int cannot hold data that large, and the playerCharacters have A LOT of money. */

#define clear() system("clear") // This line defines the clear function so that it can be used in the terminal.

struct Character {
    int type;
    string name;
    int health;
    money_int money;
    int age;
    string occupation;
    string familyMembers;
    string status;
    bool alive = true;
};

void userInput(string&);
void gameInfo(string);
void populateInfo(Character&, int);
int characterSelection();
string populateGood(string[]);
string populateBad(string[]);
void printToonFull(Character);
void printStatus(Character);
void actionStage(string[], string[], Character&);
bool statusChecker(Character);

int main(int argc, char *argv[]) {
    string userName;
    Character playerCharacter;
    srand(time(0)); // This initializes the random value by marking the exact time, which will create a unique seed.
    string goodActions[5];
    string badActions[11];

    // clear(); // Clears the screen
    userInput(userName); // Takes user name
    gameInfo(userName); // Prints general game info

    int characterSelectionInt = characterSelection();
    populateInfo(playerCharacter, characterSelectionInt); // Function that creates all the characters
    populateGood(goodActions); // Function that populates the "good" array
    populateBad(badActions); // Function that populates the "bad" array
    printToonFull(playerCharacter); // Populates the toon info with struct information

    int counter = 0;
    while (statusChecker(playerCharacter) == true && counter < 2) {
        cin.get();
        actionStage(goodActions, badActions, playerCharacter);
        printToonFull(playerCharacter);
        counter++;
    }

    if (statusChecker(playerCharacter) == true) {
        cout << "\nCongrats! You win!" << endl;
    } else {
        cout << "\nUh oh, you died." << endl;
    }
    return 0;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter. " << endl;
    getline(cin, userName);
}

void gameInfo(string userName) {
    cout << "\nWelcome " << userName << " to my companion piece." << endl;
    cout << "This program is designed to tell a story that follows the lives of different people currently living in Russia." << endl;
    cout << "Hopefully these stories are able to bring better perspective to the ongoing conditions in Russia." << endl;
    cout << "The only input you will need is the numpad for character choice selections." << endl;
    cout << "It is important to note that this game is NOT fair, and every decision will have consequences." << endl;
    cout << " .\n .\n .\n .\n \nGood luck, and stay alive.\n\n" << endl;
}

int characterSelection() {
    int userSelection;
    cout << "Which character would you like to play as? 1-3 " << endl;
    cin >> userSelection;
    return userSelection;
}

void populateInfo(Character &playerCharacter, int characterSelectionInt) {
    if (characterSelectionInt == 1) {
        playerCharacter.type = 1; // Oligarch
        playerCharacter.name = "Bob";
        playerCharacter.health = 100;
        playerCharacter.money = 50001;
        playerCharacter.age = 50;
        playerCharacter.occupation = "Oil Tycoon";
        playerCharacter.familyMembers = "Wife, two sons, one daughter";
        playerCharacter.status = "Slightly overweight, happy, loyal to government.";
    } else if (characterSelectionInt == 2) {
        playerCharacter.type = 2; // Regular person
        playerCharacter.name = "Heather";
        playerCharacter.health = 100;
        playerCharacter.money = 500;
        playerCharacter.age = 20;
        playerCharacter.occupation = "Regular person";
        playerCharacter.familyMembers = "DEBUG";
        playerCharacter.status = "DEBUG";
    }
}

string populateGood(string goodActions[]) {
    goodActions[0] = "Money Increase";
    goodActions[1] = "Help Someone Else";
    goodActions[2] = "Quality time with Family";
    goodActions[3] = "STORY DEBUG1";
    goodActions[4] = "STORY DEBUG2";
    return "DEBUG";
}

string populateBad(string badActions[]) {
    badActions[0] = "Draft Notice";
    badActions[1] = "State Abduction";
    badActions[2] = "Health Failing";
    badActions[3] = "Mugging";
    badActions[4] = "Inclement Weather";
    badActions[5] = "Job Loss";
    badActions[6] = "Food Loss";
    badActions[7] = "Loss of Family";
    badActions[8] = "Severe Injury";
    badActions[9] = "Fight";
    badActions[10] = "Transportation Loss";
    return "DEBUG";
}

void printToonFull(Character playerCharacter) {
    cout << "\t\tCHARACTER ONE, RUSSIAN playerCharacter" << endl;
    cout << "\tName: " << playerCharacter.name << endl;
    cout << "\tHealth: " << playerCharacter.health << endl;
    cout << "\tMoney: " << playerCharacter.money << endl;   
    cout << "\tAge: " << playerCharacter.age << endl;
    cout << "\tOccupation: " << playerCharacter.occupation << endl;
    cout << "\tFamily Members: "<< playerCharacter.familyMembers << endl;
    cout << "\tCurrent Status: " << playerCharacter.status << endl; // This line is the first seperating line
    cout << "\tAlive Status: "<< playerCharacter.alive << endl;


// Finish this later
    // cout << "\t\tCHARACTER TWO" << endl;
    // cout << "\tName: " << endl;
    // cout << "\tAge: " << endl;
    // cout << "\tOccupation: " << endl;
    // cout << "\tFamily Members: " << endl; // This line is the second seperating line

    // cout << "\t\tCHARACTER THREE" << endl;
    // cout << "\tName: " << endl;
    // cout << "\tAge: " << endl;
    // cout << "\tOccupation: " << endl;
    // cout << "\tFamily Members: " << endl;
}

void printStatus(Character playerCharacter) {
    cout << "\tName: " << playerCharacter.name << endl;
    cout << "\tCurrent Health: " << playerCharacter.health << endl;
    cout << "\tCurrent Money: " << playerCharacter.money << endl;
    cout << "\tCurrent Status: " << playerCharacter.status << endl;
}

void actionStage(string goodActions[], string badActions[], Character &playerCharacter) {
    cout << "\t***STAGE ONE***\n";
    cout << "You are BOB, a Russian Oil Tycoon and a friend of the regime. ***CONTINUE STORY***" << endl;
    cout << "***ACTION***\n";

    int choice;
    // choice = ((rand()%10));
    choice = 0;
    cout << "DEBUG: choice: " << choice << endl;

    switch (choice) {
        case 0:
            cout << badActions[0]; // Draft notice
            cout << "Story stuff";
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 50000);
                cout << "Dodge the draft";
            } else if (playerCharacter.type == 2) {
                cout << "You have been notified that of your summons to the Russian Army." << endl;
                cout << "This will result in a -50 hp penalty." << endl;
                playerCharacter.health = (playerCharacter.health - 50);
            }
            break;
        case 1: // State abduction
            cout << badActions[1]; 
            cout << "DEBUG";
            break;
        case 2: // Health failing
            cout << "DEBUG"; 
            break;
        case 3: // Mugging
            cout << "DEBUG"; 
            break;
        case 4: // Inclement weather
            cout << "DEBUG"; 
            break;
        case 5: // Job Loss
            cout << "DEBUG";
            break;
        case 6: // Food Loss
            cout << "DEBUG";
            break;
        case 7: // Loss of family member
            cout << "DEBUG";
            break;
        case 8: // Severe injury
            cout << "DEBUG";
            break;
         case 9: // Fight
            cout << "DEBUG";
            break;
        case 10: // Transportation loss
            cout << "Transportation loss" << endl;
            break;
        case 11: // Money Increase
            cout << "Money increase" << endl;
            break;
        case 12: // Help someone else
            cout << "Help someone else"
            break;
        case 13: // Quality time with family
            cout << "Quality time with family" << endl;
            break;
        case 14: // DEBUG POSITIVE
            cout << "DEBUG";
            break;
        case 15: // DEBUG POSITIVE
            cout << "DEBUG";
            break;
    }
}

bool statusChecker(Character playerCharacter) {
    if (playerCharacter.health == 0) {
        return false;
    } else if (playerCharacter.money <= 0){
        return false;
    } else {
        return true;
    }
}
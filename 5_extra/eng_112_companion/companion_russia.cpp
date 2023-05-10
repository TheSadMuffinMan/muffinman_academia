/*
Name: Anthony Streich
Date: 8 May 23
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
    // string familyMembers;
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
// void printAllToons(Character);
void printStatus(Character);
void actionStage(string[], string[], Character&);
bool statusChecker(Character);

int main(int argc, char *argv[]) {
    string userName;
    Character playerCharacter;
    srand(time(0)); // This initializes the random value by marking the exact time, which will create a unique seed.
    string goodActions[5];
    string badActions[11];

    // clear(); // Clears the screen after each iteration
    userInput(userName); // Takes user name
    gameInfo(userName); // Prints general game info

    populateInfo(playerCharacter, characterSelection()); // Function that creates and displays both characters

    populateGood(goodActions); // Function that populates the "good" array
    populateBad(badActions); // Function that populates the "bad" array

    int counter = 0;
    while (statusChecker(playerCharacter) == true && counter < 2) {
        cin.get();
        actionStage(goodActions, badActions, playerCharacter);
        printStatus(playerCharacter);
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
    cout << "Please enter your name, and press enter. " << endl;
    getline(cin, userName);
}

void gameInfo(string userName) {
    cout << "\nWelcome " << userName << " to my companion piece." << endl;
    cout << "This program is designed to tell a story that follows the lives of different people currently living in Russia." << endl;
    cout << "Hopefully these stories are able to bring better perspective to the ongoing conditions in Russia." << endl;
    cout << "It is important to note that this game is NOT fair, mostly because I'm a terrible coder, but also because \nit is indicative of real life." << endl;
    cout << " \n \n \nGood luck, and stay alive.\n\n" << endl;
}

int characterSelection() {
    int userSelection;
    cout << "Which character would you like to play as? 1 or 2? " << endl;
    cin >> userSelection;
    return userSelection;
}

void populateInfo(Character &playerCharacter, int userSelection) {
    // cout << "Which character would you like to play as? " << endl;
    if (userSelection == 1) {
        playerCharacter.type = 1; // Oligarch
        playerCharacter.name = "Said Gutseriev";
        cout << "\n\n\tName: " << playerCharacter.name << "\n";
        playerCharacter.health = 100;
        cout << "\tHealth: " << playerCharacter.health << "\n";
        playerCharacter.money = 1700000000;
        cout << "\tMoney: " << playerCharacter.money << "\n";
        playerCharacter.age = 50;
        cout << "\tAge: " << playerCharacter.age << "\n";
        playerCharacter.occupation = "Oil Tycoon";
        cout << "\tOccupation: " << playerCharacter.occupation << "\n";
        playerCharacter.status = "No medical issues";
        cout << "\tStatus: " << playerCharacter.status << "\n";
    } else if (userSelection == 2) {
        playerCharacter.type = 2; // Regular person
        playerCharacter.name = "Dimitri";
        cout << "\n\n\tName: " << playerCharacter.name << "\n";
        playerCharacter.health = 80;
        cout << "\tHealth: " << playerCharacter.health << "\n";
        playerCharacter.money = 2500;
        cout << "\tMoney: " << playerCharacter.money << "\n";
        playerCharacter.age = 25;
        cout << "\tAge: " << playerCharacter.age << "\n";
        playerCharacter.occupation = "University Student";
        cout << "\tOccupation: " << playerCharacter.occupation << "\n";
        playerCharacter.status = "No medical issues\n";
        cout << "\tStatus: " << playerCharacter.status << "\n";
    }
}

string populateGood(string goodActions[]) {
    goodActions[0] = "Money Increase";
    goodActions[1] = "Help Someone Else";
    goodActions[2] = "Quality time with Family";
    goodActions[3] = "STORY DEBUG1";
    goodActions[4] = "STORY DEBUG2";
    return "Populate good DEBUG";
}

string populateBad(string badActions[]) {
    badActions[0] = "Draft Notice";
    badActions[1] = "State Abduction";
    badActions[2] = "Health Failing";
    badActions[3] = "Mugging";
    badActions[4] = "Inclement Weather";
    badActions[5] = "Bankruptcy";
    badActions[6] = "Food Loss";
    badActions[7] = "Loss of Family";
    badActions[8] = "Severe Injury";
    badActions[9] = "Fight";
    badActions[10] = "Transportation Loss";
    return "Populate bad DEBUG";
}

void printToonFull(Character playerCharacter) {
    // string nameUpper;
    // nameUpper = toupper(playerCharacter.name);
    cout << "\n\t\tCURRENT PLAYER CHARACTER" << endl;
    cout << "\tName: " << playerCharacter.name << endl;
    cout << "\tHealth: " << playerCharacter.health << endl;
    cout << "\tMoney: " << playerCharacter.money << endl;   
    cout << "\tAge: " << playerCharacter.age << endl;
    cout << "\tOccupation: " << playerCharacter.occupation << endl;
    cout << "\tCurrent Status: " << playerCharacter.status << endl;
    cout << "\tAlive Status: "<< playerCharacter.alive << endl;
}

void printStatus(Character playerCharacter) {
    cout << "\tName: " << playerCharacter.name << endl;
    cout << "\tCurrent Health: " << playerCharacter.health << endl;
    cout << "\tCurrent Money: " << playerCharacter.money << endl;
    cout << "\tCurrent Status: " << playerCharacter.status << endl;
}

void actionStage(string goodActions[], string badActions[], Character &playerCharacter) {
    int choice;
    cout << "\n***Manual Mode ON*** Which option would you like? 0-6" << endl;
    cin >> choice;

    // choice = ((rand()%6));
    // cout << "DEBUG: choice: " << choice << "\n" << endl;

    switch (choice) {
        case 0: // Draft notice
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 50000);
                cout << "Although you have been summoned for the draft, you are influential.\n";
                cout << "This will cost you some $50,000, but you are fine otherwise.\n" << endl;
            } else if (playerCharacter.type == 2) {
                cout << "You have been notified that of your summons to the Russian Army." << endl;
                cout << "This will result in a -50 hp penalty." << endl;
                playerCharacter.health = (playerCharacter.health - 50);
            }
            break;
        case 1: // State abduction. This action results in the loss of the game no matter who you are playing as.
            playerCharacter.money = 0;
            playerCharacter.status = "In captivity\n";
            playerCharacter.occupation = "In captivity\n";
            cout << "You have been abducted by the Russian Police. All of your assets have been seized.\n";
            cout << "No one is ever released from captivity.\n";
            playerCharacter.alive = false;
            break;
        case 2: // Health failing
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 100000);
                playerCharacter.health = (playerCharacter.health - 25);
                cout << "Although your health is decreasing, you are can travel to other countries for better care.\n";
                cout << "This will cost you some money and health, but you are fine otherwise.\n" << endl;
            } else if (playerCharacter.type == 2) {
                cout << "Your health is failing, and you have no means to change this." << endl;
                cout << "This will result in a -60 hp penalty and all of your money being used for care." << endl;
                playerCharacter.health = (playerCharacter.health - 60);
                playerCharacter.money = 0;
                playerCharacter.alive = false;
            }
            break;
        case 3: // Mugging
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 500);
                cout << "While out on a stroll outside your estate, you are mugged.\n";
                cout << "This will cost you a small bit of money, but the perp is caught and thrown in the gulag.\n" << endl;
            } else if (playerCharacter.type == 2) {
                cout << "You have been mugged, and have no means to prevent it from happening." << endl;
                cout << "This will result in -500 money, but you live to tell the tale." << endl;
                playerCharacter.money = (playerCharacter.money - 500);
            }
            break;
        case 4: // Inclement weather
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 1000);
                cout << "Uh oh, you've been caught outside in some incliment weather.\n";
                cout << "Replacing your clothes won't be cheap, but that's what your money is for!\n" << endl;
            } else if (playerCharacter.type == 2) {
                cout << "You're caught out in some incliment weather." << endl;
                cout << "You've been soaked, and are suffering from hypothermia. This results in -15 health." << endl;
                playerCharacter.health = (playerCharacter.health - 15);
            }
            break;
        case 5: // Bankruptcy
            if (playerCharacter.type == 1) {
                playerCharacter.money = 0;
                cout << "Your rights to the oil sites your family has controlled over the last century have been revoked.\n";
                cout << "You no longer have any money, and this means that your status as an oligarch is no more." << endl;
                playerCharacter.status = "DEAD";
                playerCharacter.alive = false;
            } else if (playerCharacter.type == 2) {
                cout << "You've lost all of your money.." << endl;
                playerCharacter.money = 0;
                playerCharacter.status = "DEAD";
                playerCharacter.alive = false;
            }
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
            cout << "Help someone else";
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
    if (playerCharacter.health <= 0) {
        return false;
    } else if (playerCharacter.money <= 0){
        return false;
    } else {
        return true;
    }
}

/*
I wanted to thank my tutor DJ so much for his help with the logic of this game. His guidance made this game possible!
*/
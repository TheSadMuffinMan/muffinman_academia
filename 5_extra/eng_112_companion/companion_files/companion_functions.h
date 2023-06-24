#include <iostream>
#include <string>
#include <random>

// ************************* I am NOT using namespace std **************************

using money_int = long long int; /* This creates a new type of variable that can hold really large values. This is needed because
a regular variable type of int cannot hold data that large, and the playerCharacters have A LOT of money. */

// This definition is different from (#include)s because it is defining a function to be used by the operating system, not Ubuntu.
// This line defines the clear function so that it can be used in the terminal.
// The internet has informed me that this is NOT a best security practice (mixing macros with c++ commands).
#define clear() (system("clear"), std::cout << "***** At any point, pressing \"CTRL\" + \"C\" will terminate the program. *****\n")

struct Character {
    int type;
    bool alive = true;
    std::string name;
    int health;
    money_int money;
    int age;
    std::string occupation;
    // std::string familyMembers;
    std::string status;
};

// These are my own defined functions
void userInput(std::string&);
void gameInfo();
void populateInfo(Character&, int);
int characterSelection();
std::string populateGood(std::string[]);
std::string populateBad(std::string[]);
void printToonFull(Character);
// void printAllToons(Character);
void printStatus(Character, std::string);
void actionStage(std::string[], std::string[], Character&);
bool statusChecker(Character);
void printMenu();

// void prerequisiteDeclarations(std::string& userName, Character& playerCharacter, std::string goodActions[5], std::string badActions[11]) {
//     std::string userName;
//     Character playerCharacter;
//     // ******* I'm not sure if this is initialized or not ************ RANDOM MIGHT NOT BE WORKING
//     srand(time(0)); // This initializes a random value by marking the exact time, which will create a unique seed.
//     std::string goodActions[5];
//     std::string badActions[11];
//     populateGood(goodActions); // Function that populates the "good" array
//     populateBad(badActions); // Function that populates the "bad" array

void userInput(std::string& userName) {
    // std::cout << "***** At any point, pressing \"CTRL\" + \"C\" will terminate the program. *****" << std::endl;
    std::cout << "\tPlease enter your name, and press enter. " << std::endl;
    getline(std::cin, userName);
    clear();
}

void gameInfo() {
    std::cout << "This program is designed to tell a story that follows the lives of different people currently living in Russia." << std::endl;
    std::cout << "Hopefully these stories are able to bring better perspective to the ongoing living conditions in Russia." << std::endl;
    std::cout << "It is important to note that this game is NOT fair, mostly because I'm a terrible coder, but also because \nit is indicative of real life." << std::endl;
    std::cout << "Good luck, and stay alive.\n" << std::endl;
    std::cout << "Press any button to return to the main menu. " << std::endl;
    std::cin.get();
}

int characterSelection() {
    int userSelection;
    std::cout << "Which character would you like to play as? 1 or 2? " << std::endl;
    std::cin >> userSelection;
    return userSelection;
}

void populateInfo(Character &playerCharacter, int userSelection) {
    // std::cout << "Which character would you like to play as? " << std::endl;
    if (userSelection == 1) {
        playerCharacter.type = 1; // Oligarch
        playerCharacter.name = "Said Gutseriev";
        std::cout << "\n\n\tName: " << playerCharacter.name << "\n";
        playerCharacter.health = 100;
        std::cout << "\tHealth: " << playerCharacter.health << "\n";
        playerCharacter.money = 1700000000;
        std::cout << "\tMoney: " << playerCharacter.money << "\n";
        playerCharacter.age = 50;
        std::cout << "\tAge: " << playerCharacter.age << "\n";
        playerCharacter.occupation = "Oil Tycoon";
        std::cout << "\tOccupation: " << playerCharacter.occupation << "\n";
        playerCharacter.status = "No medical issues";
        std::cout << "\tStatus: " << playerCharacter.status << "\n";
    } else if (userSelection == 2) {
        playerCharacter.type = 2; // Regular person
        playerCharacter.name = "Dimitri";
        std::cout << "\n\n\tName: " << playerCharacter.name << "\n";
        playerCharacter.health = 80;
        std::cout << "\tHealth: " << playerCharacter.health << "\n";
        playerCharacter.money = 2500;
        std::cout << "\tMoney: " << playerCharacter.money << "\n";
        playerCharacter.age = 25;
        std::cout << "\tAge: " << playerCharacter.age << "\n";
        playerCharacter.occupation = "University Student";
        std::cout << "\tOccupation: " << playerCharacter.occupation << "\n";
        playerCharacter.status = "No medical issues\n";
        std::cout << "\tStatus: " << playerCharacter.status << "\n";
    }
}

std::string populateGood(std::string goodActions[]) {
    goodActions[0] = "Money Increase";
    goodActions[1] = "Help Someone Else";
    goodActions[2] = "Quality time with Family";
    goodActions[3] = "STORY DEBUG1";
    goodActions[4] = "STORY DEBUG2";
    return "Populate good DEBUG";
}

std::string populateBad(std::string badActions[]) {
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
    // std::string nameUpper;
    // nameUpper = toupper(playerCharacter.name);
    std::cout << "\n\t\tCURRENT PLAYER CHARACTER" << std::endl;
    std::cout << "\tName: " << playerCharacter.name << std::endl;
    std::cout << "\tHealth: " << playerCharacter.health << std::endl;
    std::cout << "\tMoney: " << playerCharacter.money << std::endl;   
    std::cout << "\tAge: " << playerCharacter.age << std::endl;
    std::cout << "\tOccupation: " << playerCharacter.occupation << std::endl;
    std::cout << "\tCurrent Status: " << playerCharacter.status << std::endl;
    std::cout << "\tAlive Status: "<< playerCharacter.alive << std::endl;
}

void printStatus(Character playerCharacter, std::string userName) {
    std::cout << "User: " << userName << std::endl;
    std::cout << "\tName: " << playerCharacter.name << std::endl;
    std::cout << "\tCurrent Health: " << playerCharacter.health << std::endl;
    std::cout << "\tCurrent Money: " << playerCharacter.money << std::endl;
    std::cout << "\tCurrent Status: " << playerCharacter.status << std::endl;
}

void actionStage(std::string goodActions[], std::string badActions[], Character &playerCharacter) {
    int choice;
    std::cout << "\n***Manual Mode ON*** Which option would you like? 0-6" << std::endl;
    std::cin >> choice;

    // choice = ((rand()%6));
    // std::cout << "DEBUG: choice: " << choice << "\n" << std::endl;

    switch (choice) {
        case 0: // Draft notice
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 50000);
                std::cout << "Although you have been summoned for the draft, you are influential.\n";
                std::cout << "This will cost you some $50,000, but you are fine otherwise.\n" << std::endl;
            } else if (playerCharacter.type == 2) {
                std::cout << "You have been notified that of your summons to the Russian Army." << std::endl;
                std::cout << "This will result in a -50 hp penalty." << std::endl;
                playerCharacter.health = (playerCharacter.health - 50);
            }
            break;
        case 1: // State abduction. This action results in the loss of the game no matter who you are playing as.
            playerCharacter.money = 0;
            playerCharacter.status = "In captivity\n";
            playerCharacter.occupation = "In captivity\n";
            std::cout << "You have been abducted by the Russian Police. All of your assets have been seized.\n";
            std::cout << "No one is ever released from captivity.\n";
            playerCharacter.alive = false;
            break;
        case 2: // Health failing
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 100000);
                playerCharacter.health = (playerCharacter.health - 25);
                std::cout << "Although your health is decreasing, you are can travel to other countries for better care.\n";
                std::cout << "This will cost you some money and health, but you are fine otherwise.\n" << std::endl;
            } else if (playerCharacter.type == 2) {
                std::cout << "Your health is failing, and you have no means to change this." << std::endl;
                std::cout << "This will result in a -60 hp penalty and all of your money being used for care." << std::endl;
                playerCharacter.health = (playerCharacter.health - 60);
                playerCharacter.money = 0;
                playerCharacter.alive = false;
            }
            break;
        case 3: // Mugging
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 500);
                std::cout << "While out on a stroll outside your estate, you are mugged.\n";
                std::cout << "This will cost you a small bit of money, but the perp is caught and thrown in the gulag.\n" << std::endl;
            } else if (playerCharacter.type == 2) {
                std::cout << "You have been mugged, and have no means to prevent it from happening." << std::endl;
                std::cout << "This will result in -500 money, but you live to tell the tale." << std::endl;
                playerCharacter.money = (playerCharacter.money - 500);
            }
            break;
        case 4: // Inclement weather
            if (playerCharacter.type == 1) {
                playerCharacter.money = (playerCharacter.money - 1000);
                std::cout << "Uh oh, you've been caught outside in some incliment weather.\n";
                std::cout << "Replastd::cing your clothes won't be cheap, but that's what your money is for!\n" << std::endl;
            } else if (playerCharacter.type == 2) {
                std::cout << "You're caught out in some incliment weather." << std::endl;
                std::cout << "You've been soaked, and are suffering from hypothermia. This results in -15 health." << std::endl;
                playerCharacter.health = (playerCharacter.health - 15);
            }
            break;
        case 5: // Bankruptcy
            if (playerCharacter.type == 1) {
                playerCharacter.money = 0;
                std::cout << "Your rights to the oil sites your family has controlled over the last century have been revoked.\n";
                std::cout << "You no longer have any money, and this means that your status as an oligarch is no more." << std::endl;
                playerCharacter.status = "DEAD";
                playerCharacter.alive = false;
            } else if (playerCharacter.type == 2) {
                std::cout << "You've lost all of your money.." << std::endl;
                playerCharacter.money = 0;
                playerCharacter.status = "DEAD";
                playerCharacter.alive = false;
            }
            break;
        case 6: // Food Loss
            std::cout << "DEBUG";
            break;
        case 7: // Loss of family member
            std::cout << "DEBUG";
            break;
        case 8: // Severe injury
            std::cout << "DEBUG";
            break;
         case 9: // Fight
            std::cout << "DEBUG";
            break;
        case 10: // Transportation loss
            std::cout << "Transportation loss" << std::endl;
            break;
        case 11: // Money Increase
            std::cout << "Money increase" << std::endl;
            break;
        case 12: // Help someone else
            std::cout << "Help someone else";
            break;
        case 13: // Quality time with family
            std::cout << "Quality time with family" << std::endl;
            break;
        case 14: // DEBUG POSITIVE
            std::cout << "DEBUG";
            break;
        case 15: // DEBUG POSITIVE
            std::cout << "DEBUG";
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

void printMenu() {
    clear();

    std::cout << "\t\t***** MAIN MENU *****" << std::endl;
    std::cout << "\n\n\t[1] Game Start" << std::endl;
    std::cout << "\n\t[2] Game Rules\n" << std::endl;
}
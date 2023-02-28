/*
Name: Anthony Streich
Where should I eat lunch?
*/

#include <iostream>
#include <string>
#include <random>

using namespace std;

void promptName(string&);
void greetVictim(string);
void getInfo(int&, int&, int&);
string findFood(int, int, int);

int main() {
    string victimsName;
    int distance, price, temperature;
    string whereToGo;

    srand(time(0));

    promptName(victimsName);
    greetVictim(victimsName);
    getInfo(distance, price, temperature);

    whereToGo = findFood(distance, price, temperature);

    // We should never see this because the program will always return a value
    // But as a precaution, this debugging tool is included in the code
    if (whereToGo == "ERROR") {
        cout << "Something weird happened, got back ERROR with these parameters: \n" << endl;
        cout << "DEBUG Distance: " << distance << endl;
        cout << "DEBUG Price: " << price << endl;
        cout << "DEBUG Temperature: " << temperature << endl;
        return 1;
    }

    cout << "You are going to go to...: \n \n" << whereToGo << endl;

    return 0;
}

// This is where the actual decision will be made
string findFood(int distance, int price, int temperature) {
    /*
    food map:
    0-1 = Taco Bell
    1-5 = Texas Roadhouse
    5-20 = Hot Tomato
    20+ = Casa Bonito

    < 1 = The Caf
    1-10 = McD's
    10-30 = Olive Garden
    30+ = Red Lobster

    <30 = nowhere
    30-50 = Zoup
    50-100 = Cold Stone
    100+ = nowhere
    */

   // This makes a random number between 0-2, which then directs our program into whichever area it wants to go
    int randChoice = random()%3;

    // After the criteria has been selected, the program navigates to its respective area to make the decision for you
    // There are three different ways to write this, all demonstrated below
    switch(randChoice) {
        case 0:
            /*
                distance
                0-1 = Taco Bell
                1-5 = Texas Roadhouse
                5-20 = Hot Tomato
                20+ = Casa Bonito
            */
            if (distance < 1) 
                return "Taco Bell";
            else if (distance < 5) 
                return "Texas Roadhouse";
            else if (distance < 20) 
                return "Hot Tomato";
            else 
                return "Casa Bonito";
            break;

        case 1:
            /*
                price
                < 1 = The Caf
                1-10 = McD's
                10-30 = Olive Garden
                30+ = Red Lobster
            */
            if (price < 1) {
                return "The Caf";
            } else if (price < 10) {
                return "McDonald's";
            } else if (price < 30) {
                return "Olive Garden";
            } else {
                return "Red Lobster";
            }
            break;

        case 2:
            /*
                temperature
                <30 = nowhere
                30-50 = Zoup
                50-100 = Cold Stone
                100+ = nowhere
            */
            if (temperature < 30) return "Nowhere";
            else if (temperature < 50) return "Zoup";
            else if (temperature < 100) return "Cold Stone";
            else return "Nowhere";
            break;

        default:
            cout << "We should never get here...";
            return "ERROR";
    }

// If we actually wanted to pursue this way of logic, we would have 60+ options to hard code into it
// The comparison operators make this very difficult to happen, as every single option has to be explicitly coded
// Just don't do it this way unless you absolutely have to
/*
    if (distance < 1 && price < 1 && temperature < 30) {
        switch(randChoice) {
            case 0:
                return "Taco Bell";
                break;
            case 1:
                return "The Caf";
                break;
            case 2:
                return "nowhere";
                break;
        }
    }
    if (distance < 1)  {
        return "Taco Bell";
    } else if (distance < 5) {
        return "Texas Roadhouse";
    } else if (distance < 20) {
        return "Hot Tomato";
    } 
*/
}

void getInfo(int &distance, int &price, int &temperature) {
    cout << "How far do you want to travel? ";
    cin >> distance;

    cout << "How much do you want to spend? ";
    cin >> price;

    cout << "What is the temperature outside? ";
    cin >> temperature;
}

void promptName(string &name) {
    cout << "Please enter your full name: " << endl;
    getline(cin, name);
}

void greetVictim(string name) {
    cout << "Welcome " << name << " to our lunch picker..." << endl;
    cout << "Be afraid...be very afraid..." << endl;
}
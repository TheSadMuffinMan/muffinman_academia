// Lecture Monday 1-29
// Classes only exist in C++, not C.
// Class declarations always start with an upper case.
// Function prototypes fix the chicken and egg issue (makes it to where function order does not matter)
// The goal of OOP is to give the program the least amount of access to data as possible
// OOP (public/private data members) allows for easy data validation.

#include <iostream>

using namespace std;

class Dog
{   
    public:

        void speak();

        // Setters
        void setName(string);
        
        // Getters
        string getName();

    // Data types will ALWAYS be private to avoid global variables.
    // The underline signifies that the variable is a class member variable
    private:
        string _name;
        string _breed;
        float _weight;
        int _numLegs;
        char _gender;
};

int main(int argc, char *argv[])
{
    Dog dog1;

    dog1.setName("Hubrfiwronerkwrkjnern");

    dog1.speak();

    return 0;
}

void Dog::speak() // This/these function(s) are called your class method(s). Data types inside classes are naturally private.
{
    cout << _name << " barks." << endl;
}

// Setters
void Dog::setName(string inputName)
{
    while (!(inputName.length() < 10))
    {
        cout << "The name you have input is longer than 10 chars, try again" << endl;
        getline(cin, inputName);
    }
    _name = inputName;
}

// Getters
string Dog::getName()
{
    return _name;
}
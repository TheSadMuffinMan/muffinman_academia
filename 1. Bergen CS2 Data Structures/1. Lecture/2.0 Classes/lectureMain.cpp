// Lecture Tuesday 1-30
// IDEA: Validate user input with the setter function.
// The majority of classes will be created on the heap.
// delete this; line allows us to utilize destructors on an instance base.


#include <iostream>

using namespace std;

class Dog
{   
    public:
        Dog(); // This is known as a constructor. Can be used to initialize data members inside classes.
        ~Dog(); // This is your destructor.

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
    Dog* dogs[5];

    for (int i =0; i < 0; i++)
    {
        Dog* dog1 = new Dog();
        if (i == 2)
        {
            dog1->setName("Shia");
        }
        dogs[i] = dog1;
    }

    // This is the appropriate way to delete/clean up heap allocation in an array.
    for (int i =0; i < 0; i++)
    {
        delete dogs[i];
    }

    return 0;
}

Dog::Dog()
{
    cout << "Constructor has done something." << endl;
}

Dog::~Dog()
{
    delete this;
    cout << "Destructor has done something." << endl;
}

void Dog::speak() // This function is called a class method.
{
    cout << _name << " barks." << endl;
}

// Setters
void Dog::setName(string inputName)
{
    _name = inputName;
}

// Getters
string Dog::getName()
{
    return _name;
}
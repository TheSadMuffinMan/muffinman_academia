#include <iostream>
#include <string>

class StringStackClient
{
    public:
        StringStackClient();

        // Getters
        std::string* getStackAddress();
        std::string* getTop();
        int getN();
        int getStackCapacity();
        // Setters
        void setStackAddress(std::string*);
        void setN(int);
        void setStackCapacity(int);

        void push(std::string);
        bool isEmpty();
        std::string pop();
    
    private:
        std::string* _stackAddress, *_top; // Weird that you must include "*" with _top.
        int _numElements; // Used for number of elements inside _stackAddress.
        int _stackCapacity; // Tracks the total size of _stackAddress.

        void resizeArray();
};

// Default Constuctor. Stack capacitity starts at 4.
StringStackClient::StringStackClient()
{
    StringStackClient::setN(0);
    StringStackClient::setStackCapacity(4);
    _stackAddress = new std::string[getStackCapacity()];
}

void StringStackClient::push(std::string inputString)
{
    //
}


// Getters and Setters
std::string* StringStackClient::getStackAddress() {return _stackAddress;}
std::string* StringStackClient::getTop() {return _top;}

int StringStackClient::getN() {return _numElements;}
int StringStackClient::getStackCapacity() {return _stackCapacity;}
void StringStackClient::setStackAddress(std::string* newStringAddress) {_stackAddress = newStringAddress;}
void StringStackClient::setN(int inputN) {_numElements = inputN;}
void StringStackClient::setStackCapacity(int newCapacity) {_stackCapacity = newCapacity;}

// Function doubles the size of _stackAddress and copies all old contents into the new array.
void StringStackClient::resizeArray()
{
    // int newN = getN();
    int newCapacity = (getStackCapacity() * 2);
    std::string* newArray = new std::string[newCapacity];

    // Only need to loop through StackCapacity times as we will not need the rest of the array for now.
    for (int i = 0; i < getStackCapacity(); i++)
    {
        newArray[i] = getStackAddress()[i];
    }

    // Cleaning up memory.
    delete _stackAddress;

    setStackAddress(newArray);
}
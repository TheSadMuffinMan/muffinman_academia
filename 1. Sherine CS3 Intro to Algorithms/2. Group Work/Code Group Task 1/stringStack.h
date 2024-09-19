/*
For this implementation, we add elements to the end of the array to represent a stack structure.
    This means that we must read the array backwards to have a true stack.
*/

#include <iostream>
#include <string>

class StringStackClient
{
    public:
        StringStackClient();

        void push(std::string);
        bool isEmpty();
        std::string pop();
        void printStack();

        // Getters
        std::string* getStackAddress();
        int getNumElements();
        int getStackCapacity();
        // Setters
        void setStackAddress(std::string*);
        void setNumElements(int);
        void setStackCapacity(int);    

    private:
        std::string* _stackAddress;
        int _stackCapacity; // Tracks the total size of _stackAddress.
        int _numElements; // Used for number of elements inside _stackAddress.

        void resizeArray();
};

// Default Constuctor. Stack capacitity starts at 4.
StringStackClient::StringStackClient()
{
    StringStackClient::setNumElements(0);
    StringStackClient::setStackCapacity(4);
    _stackAddress = new std::string[getStackCapacity()];
    // _top = _stackAddress[0];
}

void StringStackClient::push(std::string inputString)
{
    int index = getNumElements(); // This is where the last element was placed.

    if (isEmpty() == true)
    {
        getStackAddress()[0] = inputString;
        setNumElements(1);
        return;
    }

    if (index >= getStackCapacity()) {resizeArray();} // Ensuring array is large enough to hold all of our data.

    
}

bool StringStackClient::isEmpty()
{
    if (_numElements > 0)
    {
        return false;
    } else
    {
        return true;
    }
}

// Function doubles the size of _stackAddress and copies all old contents into the new larger array.
void StringStackClient::resizeArray()
{
    int newCapacity = (getStackCapacity() * 2);
    std::string* newArray = new std::string[newCapacity];

    // Only need to loop through StackCapacity times as we will not need the rest of the array (for now).
    for (int i = 0; i < getStackCapacity(); i++)
    {
        newArray[i] = getStackAddress()[i];
    }

    // Cleaning up memory.
    delete _stackAddress;

    setStackCapacity(newCapacity);
    setStackAddress(newArray);
}

// Getters and Setters
std::string* StringStackClient::getStackAddress() {return _stackAddress;}
int StringStackClient::getNumElements() {return _numElements;}
int StringStackClient::getStackCapacity() {return _stackCapacity;}
void StringStackClient::setStackAddress(std::string* newStringAddress) {_stackAddress = newStringAddress;}
void StringStackClient::setNumElements(int inputN) {_numElements = inputN;}
void StringStackClient::setStackCapacity(int newCapacity) {_stackCapacity = newCapacity;}
// std::string StringStackClient::getTop() {return _top;}
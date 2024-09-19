#include <iostream>
#include <string>

class StringStackClient
{
    public:
        StringStackClient();
        StringStackClient(std::string*);

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
        std::string* _stackAddress, *_top; // Weird that you must include "*" on _top.
        int _N; // Used for number of elements inside _stackAddress.
        int _stackCapacity; // Tracks the total size of _stackAddress.

        void resizeArray();
};

// Default Constuctor.
StringStackClient::StringStackClient()
{
    StringStackClient::setN(0);
    StringStackClient::setStackCapacity(0);
}

// Non-Default Constructor, will be primary way of reading in a string.
StringStackClient::StringStackClient(std::string* inputString)
{
    //
}

void StringStackClient::push(std::string inputString)
{
    //
}


// Getters and Setters
std::string* StringStackClient::getStackAddress() {return _stackAddress;}
std::string* StringStackClient::getTop() {return _top;}

int StringStackClient::getN() {return _N;}
int StringStackClient::getStackCapacity() {return _stackCapacity;}
void StringStackClient::setStackAddress(std::string* newStringAddress) {_stackAddress = newStringAddress;}
void StringStackClient::setN(int inputN) {_N = inputN;}
void StringStackClient::setStackCapacity(int newCapacity) {_stackCapacity = newCapacity;}

// Function doubles the size of _stringAddress.
void StringStackClient::resizeArray()
{
    int newN = getN();
    int newCapacity = (getStackCapacity() * 2);
}
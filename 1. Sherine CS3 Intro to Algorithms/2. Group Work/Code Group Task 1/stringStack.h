#include <iostream>
#include <string>

class StringStackClient
{
    public:
        StringStackClient();
        void loadString(std::string*);

        // Getters
        std::string* getStringAddress();
        int getN();
        int getStringCapacity();

        // Setters
        void setStringAddress(std::string*);
        void setN(int);
        void setStringCapacity(int);
    
    private:
        std::string* _stringAddress;
        int _N, _stringCapacity;
};

// Default Constuctor.
StringStackClient::StringStackClient()
{
    StringStackClient::setN(0);
    StringStackClient::setStringCapacity(0);
}

void StringStackClient::loadString(std::string* inputString)
{
    //
}


// Getters and Setters
std::string* StringStackClient::getStringAddress() {return _stringAddress;}
int StringStackClient::getN() {return _N;}
int StringStackClient::getStringCapacity() {return _stringCapacity;}
void StringStackClient::setStringAddress(std::string* newStringAddress) {_stringAddress = newStringAddress;}
void StringStackClient::setN(int newN) {_N = newN;}
void StringStackClient::setStringCapacity(int newCapacity) {_stringCapacity = newCapacity;}
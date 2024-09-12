#include <iostream>

class unionClient
{
    public:
        unionClient(); // Default Constructor, does not do much.

        // Getters
        int* getIDArray() {return _idArray;}
        int* getSizeArray() {return _sizeArray;}

        // Setters
        void setIDArray(int* desiredGroup) {_idArray = desiredGroup;}
        void setSizeArray(int* desiredArray) {_sizeArray = desiredArray;}
    
    private:
        int* _idArray;
        int* _sizeArray;
};

// Default constructor.
unionClient::unionClient()
{
    //
}
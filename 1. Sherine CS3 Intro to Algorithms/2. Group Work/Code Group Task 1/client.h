#include <iostream>

#define N 1000

class unionClient
{
    public:
        unionClient(); // Default Constructor.

        // Getters
        int* getIDArray() {return _idArray;}
        int* getSizeArray() {return _sizeArray;}
        // Setters
        void setIDArray(int* desiredGroup) {_idArray = desiredGroup;}
        void setSizeArray(int* desiredArray) {_sizeArray = desiredArray;}

        int* Union(int, int); // Union operation. Joins two clients.
    
    private:
        int* _idArray;
        int* _sizeArray;
};

// Default constructor.
unionClient::unionClient()
{
    int tempIDArray[N], tempSizeArray[N];

    for (int i = 0; i < N; i++)
    {
        tempIDArray[i] = i;
        // This sets every node to "point" to itself, meaning that all nodes are not connected to anything.

        tempSizeArray[i] = i;
        // This sets the size of every node to 1 (because there have been no union operations yet).
    }

    unionClient::setIDArray(tempIDArray);
    unionClient::setSizeArray(tempSizeArray);
}

// Comment.
int* unionClient::Union(int p, int q)
{
    //
}
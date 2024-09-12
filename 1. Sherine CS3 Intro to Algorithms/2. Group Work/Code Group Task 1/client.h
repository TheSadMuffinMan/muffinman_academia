#include <iostream>
#include <chrono>

#define N 1000
typedef std::chrono::steady_clock Time;// Makes it to where we don't have to type this bs every time.
typedef std::chrono::milliseconds ms; // Ditto to above.

/*
***IMPORTANT***: Program memory is dynamically allocated (client is located on heap).
Each element inside client will frequently be referred to as a "Node".
*/
class unionClient
{
    public:
        unionClient();
        ~unionClient();

        // Getters
        int* getIDArray() {return _idArray;}
        int* getSizeArray() {return _sizeArray;}
        // Setters
        void setIDArray(int* desiredGroup) {_idArray = desiredGroup;}
        void setSizeArray(int* desiredArray) {_sizeArray = desiredArray;}

        void Union(int, int);
        int find(int);
        bool connected(int, int);
    
    private:
        int* _idArray; // Stores what "group" each node belongs to.
        int* _sizeArray; // Stores the path length to root for each node.
};

// Default constructor.
unionClient::unionClient()
{
    auto timeStart = Time::now();
    int* tempIDArray = new int[N];
    int* tempSizeArray = new int[N];

    for (int i = 0; i < N; i++)
    {
        tempIDArray[i] = i;
        // This sets every node to "point" to itself, meaning that all nodes are not connected to anything.

        tempSizeArray[i] = 1;
        // This sets the size of every node to 1 (because there have been no union operations yet).
    }

    unionClient::setIDArray(tempIDArray);
    unionClient::setSizeArray(tempSizeArray);
    auto timeStop = Time::now();
    auto duration = Time::duration(timeStop - timeStart);

    // NOTE: Chrono typically operates in nanoseconds, so I've converted it ms.
    ms durationMS = std::chrono::duration_cast<ms>(duration);
    
    std::cout << "Client with " << N << " nodes initialized in " << durationMS.count()
        << " ms." << std::endl;
}

// Default deconstructor.
unionClient::~unionClient()
{
    delete _idArray;
    delete _sizeArray;

    std::cout << "\nMemory cleaned up.";
}

// Utilizes the Quick Union with Path Compression Algorithm.
// GOAL: Join two nodes.
void unionClient::Union(int p, int q)
{
    int i = 0; // i == p's index.
    int j = 0; // j == q's index.

    for (int z = 0; z < (N -1); z++) // Looping through every node...
    {
        for (i = p; i != _idArray[i]; i = _idArray[i])
            _idArray[i] = _idArray[_idArray[i]]; // Halves the length of the path to root.

        for (j = q; j != _idArray[j]; j = _idArray[j])
            _idArray[j] = _idArray[_idArray[j]]; // Ditto to above, but for j.

        if (i == j) {continue;} // If the indexes are the same...

        if (_sizeArray[i] < _sizeArray[j]) // If i's group/_sizeArray are smaller than j's group/_sizeArray...
        {
            _idArray[i] = j;
            _sizeArray[j] += _sizeArray[i];
        }
        else
        {
            _idArray[j] = i;
            _sizeArray[i] += _sizeArray[j];
        }
    }
}

// Having private data members makes this a little clunky, but workable.
int unionClient::find(int p)
{
    return unionClient::getIDArray()[p]; // NEW KNOWLEDGE ACQUIRED. I didn't know you could do this :D

    /* OLD CODE. May need in future if the above line does not work.
    // int* tempArray = unionClient::getIDArray();
    // return tempArray[p];
    */
}

// GOAL: Determine whether or not nodes p & q are connected.
bool unionClient::connected(int p, int q)
{
    if (unionClient::getIDArray()[p] == unionClient::getIDArray()[q])
    {
        return true;
    } else {return false;}
}
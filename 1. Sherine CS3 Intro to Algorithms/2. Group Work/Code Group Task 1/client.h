#include <iostream>
#include <chrono>

#define N 1000
typedef std::chrono::steady_clock Time;// Makes it to where we don't have to type this bs every time.
typedef std::chrono::milliseconds ms; // Ditto to above.

/*
***IMPORTANT***: Program memory is dynamically allocated.
Each data element inside client will frequently be referred to as "Node".
*/
class UnionClient
{
    public:
        UnionClient();
        ~UnionClient();

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
UnionClient::UnionClient()
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

    UnionClient::setIDArray(tempIDArray);
    UnionClient::setSizeArray(tempSizeArray);
    auto timeStop = Time::now();
    auto duration = Time::duration(timeStop - timeStart);

    // NOTE: Chrono typically operates in nanoseconds, so I've converted it ms.
    // NOTE 2: It takes a data set of >1,000,000 to see time increment.
    ms durationMS = std::chrono::duration_cast<ms>(duration);

    std::cout << "Client with " << N << " nodes initialized in " << durationMS.count()
        << " ms." << std::endl;
}

// Default deconstructor.
UnionClient::~UnionClient()
{
    delete _idArray;
    delete _sizeArray;

    std::cout << "\nMemory cleaned up." << std::endl;
}

// Utilizes the Quick Union with Path Compression Algorithm.
void UnionClient::Union(int p, int q)
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

int UnionClient::find(int p)
{
    return UnionClient::getIDArray()[p]; // NEW KNOWLEDGE ACQUIRED. I didn't know you could do this :D
}

// Function determines if two nodes are connected or not.
bool UnionClient::connected(int p, int q)
{
    if (UnionClient::getIDArray()[p] == UnionClient::getIDArray()[q])
    {
        return true;
    } else {return false;}
}
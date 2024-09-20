#include <iostream>
#include <fstream>
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
        void buildClient(int);
        void useMandN();
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

// This "constructor" builds a client based off of user input.
void UnionClient::buildClient(int numElements)
{
    /*
    Because the default constructor builds a client, we need to delete the old one and 
        replace it with a user built one.
    */
    UnionClient::~UnionClient();

    auto timeStart = Time::now();
    int* tempIDArray = new int[numElements];
    int* tempSizeArray = new int[numElements];

    for (int i = 0; i < numElements; i++)
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

    ms durationMS = std::chrono::duration_cast<ms>(duration);

    std::cout << "Client with " << numElements << " nodes initialized in " << durationMS.count()
        << " ms." << std::endl;
}

void UnionClient::useMandN()
{
    std::string yesOrNo = " ";
    std::cout << "Do you have a document named \"input.txt\" in this repo?" << std::endl;
    std::cout << "(Answer \"Y\" to continue): ";
    std::cin >> yesOrNo;

    // while ((yesOrNo != "y") || (yesOrNo != "Y"))
    // {
    //     std::cout << "\nInvalid input. Input \"Y\" when ready: ";
    //     std::cin >> yesOrNo;
    // }
    std::ifstream inputStream;

    inputStream.open("input.txt");
    if (!inputStream.is_open())
    {
        std::cout << "File failed to open." << std::endl;
        std::cout << "Please \"CTRL + C\" program to avoid memory leaks." << std::endl;
        std::cin >> yesOrNo; // Using variable input to pause program.
    }

    int numElements = 0;
    int numOperations = 0;

    inputStream >> numElements >> numOperations;

    buildClient(numElements);

    for (int i = 0; i < numOperations; i++)
    {
        int a, b;
        inputStream >> a;
        if (inputStream.peek() == std::istream::traits_type::eof())
        {
            std::cout << find(a) << std::endl;
            continue;
        }

        inputStream.ignore(1); // Ignoring the space between letters.
        inputStream >> b;

        Union(a,b);
    }
}

// Default deconstructor.
UnionClient::~UnionClient()
{
    delete _idArray;
    delete _sizeArray;
    // std::cout << "\nMemory cleaned up." << std::endl;
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
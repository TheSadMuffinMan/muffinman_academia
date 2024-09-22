#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>

typedef std::chrono::steady_clock Time;

/*
***IMPORTANT***: Program memory is dynamically allocated.
Each data element inside client will frequently be referred to as "Node".
*/
class UnionClient
{
    public:
        UnionClient(); // Use buildClient() function instead.
        void buildClient(int);
        void readMandNfromFile();
        int64_t randomMandN(int, int);
        ~UnionClient();

        // Getters
        int* getIDArray() {return _idArray;}
        int* getSizeArray() {return _sizeArray;}
        int getNumElements() {return _numElements;}
        // Setters
        void setIDArray(int* desiredGroup) {_idArray = desiredGroup;}
        void setSizeArray(int* desiredArray) {_sizeArray = desiredArray;}
        void setNumElements(int desiredN) {_numElements = desiredN;}

        void Union(int, int);
        int find(int);
        int findSize(int);
        bool connected(int, int);

    private:
        int* _idArray; // Stores what "group" each node belongs to.
        int* _sizeArray; // Stores the path length to root for each node.
        int _numElements; // Meant to represent N.
};

// Default constructor.
UnionClient::UnionClient()
{
    setNumElements(1);
    int* tempIDArray = new int[getNumElements()];
    int* tempSizeArray = new int[getNumElements()];

    for (int i = 0; i < getNumElements(); i++)
    {
        tempIDArray[i] = i;
        // This sets every node to "point" to itself, meaning that all nodes are not connected to anything.

        tempSizeArray[i] = 1;
        // This sets the size of every node to 1 (because there have been no union operations yet).
    }

    UnionClient::setIDArray(tempIDArray);
    UnionClient::setSizeArray(tempSizeArray);
}

// This "constructor" builds a client based off of user input.
void UnionClient::buildClient(int numElements)
{
    /*
    Because the default constructor builds a client, we need to delete the old one and 
        replace it with a user built one.
    */
    UnionClient::~UnionClient();

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
    setNumElements(numElements);
}

// Function is used for part 2 of this project.
void UnionClient::readMandNfromFile()
{
    std::string yesOrNo = " ";
    std::cout << "Do you have a document named \"input.txt\" in this repo?" << std::endl;
    std::cout << "(Answer \"Y\" to continue): ";
    std::cin >> yesOrNo;

    std::ifstream inputStream;

    inputStream.open("input.txt");
    if (!inputStream.is_open())
    {
        std::cout << "\nFile failed to open." << std::endl;
        UnionClient::~UnionClient();

        std::cout << "Please \"CTRL + C\" program to avoid memory leaks." << std::endl;
        std::cin >> yesOrNo; // Using variable input to pause program.
    }

    int numElements = 0; // AKA N.
    int numOperations = 0; // AKA M.

    inputStream >> numElements >> numOperations;
    std::cout << "NumElements: " << numElements << std::endl;
    std::cout << "NumOperations: " << numOperations << std::endl;
    buildClient(numElements);

    inputStream.ignore(1);
    for (int i = 0; i < numOperations; i++)
    {
        std::string fullLine = "abc";
        std::getline(inputStream, fullLine);

        // If we do NOT find a space inside of fullLine...
        if (fullLine.find(" ") == std::string::npos)
        {
            int a = std::stoi(fullLine);
            std::cout << "Current group size of element " << a << " is " << findSize(a) << "." << std::endl;
            continue;
        }

        int spaceIndex = fullLine.find(" ");
        int a = std::stoi(fullLine.substr(0, spaceIndex));
        int b = std::stoi(fullLine.substr(spaceIndex + 1));
        
        Union(a,b);
        std::cout << "Unionized " << a << " and " << b << "." << std::endl;
    }
}

/*
Function takes two ints: numElements (= N) and numOperations (= M) and returns the time it took for
    the entire operation.
*/
int64_t UnionClient::randomMandN(int numElements, int numOperations)
{
    buildClient(numElements); // Building a new clean client.

    std::chrono::time_point timeStart = Time::now();
    for (int i = 0; i < numOperations; i++)
    {
        int a = (rand() % numElements);
        int b = (rand() % numElements);
        Union(a,b);
    }
    std::chrono::time_point timeStop = Time::now();
    std::chrono::nanoseconds duration = Time::duration(timeStop - timeStart);
    return duration.count();
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
    int i = find(p); // i == p's index.
    int j = find(q); // j == q's index.

    for (i = p; i != _idArray[i]; i = _idArray[i])
        _idArray[i] = _idArray[_idArray[i]]; // Halves the length of the path to root.

    for (j = q; j != _idArray[j]; j = _idArray[j])
        _idArray[j] = _idArray[_idArray[j]]; // Ditto to above, but for j.
        
    if (i == j) {return;} // If the indexes are the same...

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

int UnionClient::find(int i)
{
    while (i != _idArray[i])
    {
        _idArray[i] = _idArray[_idArray[i]];
        i = _idArray[i];
    }
    return _idArray[i]; // NEW KNOWLEDGE ACQUIRED. I didn't know you could do this :D
}

// Function returns the size of whatever group p is in.
int UnionClient::findSize(int p)
{
    return UnionClient::getSizeArray()[p];
}

// Function determines if two nodes are connected or not.
bool UnionClient::connected(int p, int q)
{
    if (UnionClient::getIDArray()[p] == UnionClient::getIDArray()[q])
    {
        return true;
    } else {return false;}
}

/* Old Code
// int singleOrDouble = (rand() % 2);
// if (singleOrDouble == 1)
// {
//     int a = (rand() % numElements);
//     find(a);
//     // std::cout << a << " has a group size of: " << findSize(a) << "." << std::endl;
// } else
// {
//     int a = (rand() % numElements);
//     int b = (rand() % numElements);
//     Union(a,b);
//     // std::cout << a << " and " << b << " unionized." << std::endl;
// }
*/
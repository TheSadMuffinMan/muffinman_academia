/*
Comments.
*/
#pragma once
#include "node.h"
#include <iostream>
#include <fstream>
#include <chrono>

// template <class T>
class DiGraph
{
    public:
        DiGraph();

        void buildGraphFromFile(std::string);
    
    private:
        //
};

// Default constructor.
// template <class T>
DiGraph::DiGraph()
{
    //
}

void DiGraph::buildGraphFromFile(std::string fileName)
{
    std::ifstream inputStream;
    std::ofstream logStream;

    logStream.open("log.txt");

    // Checking to see if user included ".txt" in fileName.
    int last4pos = (fileName.size() - 4);
    std::string last4 = (fileName.substr(last4pos));
    if (last4 != ".txt")
    {
        fileName = (fileName + ".txt");
    }

    std::cout << "\nOpening " << fileName << " ..." << std::endl;

    inputStream.open(fileName);
    if (!inputStream.is_open())
    {
        std::cerr << fileName << " failed to open, program terminating." << std::endl;
        logStream << "Digraph failed to build from file." << std::endl;
        
        return;
    }

}
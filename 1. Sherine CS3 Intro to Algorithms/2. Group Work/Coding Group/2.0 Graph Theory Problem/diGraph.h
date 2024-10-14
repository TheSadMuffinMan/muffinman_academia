/*
Comments.
*/
#pragma once
#include "node.h"
#include <iostream>
#include <fstream>
#include <chrono>

template <class T>
class DiGraph
{
    public:
        DiGraph();

        // Getters
        int getNumNodes() {return _numNodes;}
        Node<T>* getNodeArray() {return _nodeArray;}

        // Setters
        void setNumNodes(int passedNumNodes) {_numNodes = passedNumNodes;}
        void setNodeArray(Node<T>* passedArray) {_nodeArray = passedArray;}

        void buildGraphFromFile(std::string fileName) // ***FINISH LATER***
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
                
                logStream.close();
                return;
            }

            //
        }
    
    private:
        int _numNodes;
        Node<T>* _nodeArray;
};
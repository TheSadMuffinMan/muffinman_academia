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
        DiGraph()
        {
            int userNumNodes = 0;
            std::cout << "How many Nodes would you like?: ";
            std::cin >> userNumNodes;

            setNumNodes(userNumNodes);

            Node<T>* tempNodeArray[getNumNodes()];
            for (int i = 0; i < getNumNodes(); i++)
            {
                tempNodeArray[i] = new Node<T>;

                int userVertex[1];
                std::cout << "\nVertex x: ";
                std::cin >> userVertex[0];

                std::cout << "\nVertex y: ";
                std::cin >> userVertex[1];

                tempNodeArray[i]->setVertex(userVertex);
            }

            setNodeArray(tempNodeArray);
            int printNum = getNodeArray().0->getVertex();

            std::cout << "\n\nNumber of Nodes: " << getNumNodes() << std::endl;
            std::cout << "Node 0 vertex: (" << printNum[0] << "," << printNum[1] << ")" << std::endl;

        }

        ~DiGraph() {delete[] _nodeArray;}

        // Getters
        int getNumNodes() {return _numNodes;}
        Node<T>* getNodeArray() {return _nodeArray;}
        Node<T> returnIndivNode(int requestedNode) {return _nodeArray[requestedNode];}

        // Setters
        void setNumNodes(int passedNumNodes) {_numNodes = passedNumNodes;}
        void setNodeArray(Node<T>* passedArray) {_nodeArray = passedArray;}
        void setIndivNode(int index, Node<T> passedNode) {_nodeArray[index] = passedNode;}

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
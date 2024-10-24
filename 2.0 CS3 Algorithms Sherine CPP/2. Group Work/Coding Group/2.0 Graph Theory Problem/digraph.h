#pragma once

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

struct Edge{
	int vertex;
	int weight;
};

// Class is not dynamically allocated :(
class DiGraph{
	private:
		int Gsize;
		vector<vector<Edge>> adj; //adjacency list
	public:
		DiGraph(int Gsize): Gsize(Gsize), adj(Gsize)
        {
		// create empty DiGraph w/ V vertices
			// this code appears to be redundant as vertice(vertice) initializes the number of vertices to be 
			// the value added to the class constructor, and adj(vertice) initializes an empty adjacencty list for each vertex
			/*for(int v=0; v<vertice; v++){
				adj[v] = std::vector<int>();
			}*/
		}

        DiGraph(std::string fileName)
        {
            int tempGraphSize = 0;
            std::string fullString, tempString, garbVariable;
            std::ifstream inputStream;

            inputStream.open(fileName);
            if (!inputStream.is_open())
            {
                std::cerr << "File failed to open, aborting..." << std::endl;
                return;
            }

            std::getline(inputStream, garbVariable); // Skipping first line.
            std::getline(inputStream, fullString);
            tempString = fullString.substr(13);
            tempGraphSize = std::stoi(tempString);

            this->Gsize = tempGraphSize;
            // DECLARE ADJACENCY LIST/VECTOR?

            while (!inputStream.eof())
            {
                std::getline(inputStream, fullString);
                std::cout << "***DEBUG*** fullString = [" << fullString << "]" << std::endl;

                int firstSpaceIndex = 0;
                int secondSpaceIndex = 0;
                int sourceVertex, destinationVertex, weight;

                // If there is only a vertex and no connections...
                // In this implementation, this only happens for Node #29.
                if (fullString.find(" ") == std::string::npos)
                {
                    sourceVertex = std::stoi(fullString);

                    // Adding a connection with itself.
                    adj[sourceVertex].push_back({sourceVertex, 0});
                    std::cout << "Adding Vertex " << sourceVertex << " with no connections." << std::endl;
                    continue;
                }

                firstSpaceIndex = fullString.find(" ");        
                secondSpaceIndex = fullString.find(" ", (firstSpaceIndex + 1));
                tempString = fullString.substr(0, (fullString.size() - (fullString.size() - firstSpaceIndex)));

                sourceVertex = std::stoi(tempString);

                tempString = fullString.substr((firstSpaceIndex + 1),
                    ((secondSpaceIndex - firstSpaceIndex) - 1));
                
                destinationVertex = std::stoi(tempString);

                // Determining weight.
                tempString = fullString.substr((secondSpaceIndex + 1), (secondSpaceIndex - firstSpaceIndex));
                weight = std::stoi(tempString);

                std::cout << "Adding Edge between " << sourceVertex << " and " << destinationVertex << " with a weight of " <<
                    weight << "." << std::endl;

                
                adj[sourceVertex].push_back({sourceVertex, 0});
                adj[destinationVertex].push_back({destinationVertex, 0});
                addEdge(sourceVertex, destinationVertex, weight);
            }

            inputStream.close();

        }

        void addEdge(int vFrom, int vTo, int weight = 1)
        {
            // add edge vFrom-vTo (parallel edges and self-loops allowed)
            if((vFrom < 0) || (vFrom >= Gsize) || (vTo < 0) || (vTo >= Gsize)){
                throw out_of_range("Vertex index out of bounds");
            }	
            adj[vFrom].push_back({vTo, weight});
            //adj[vTo].push_back(vFrom); //commented out to make this a diDiGraph as this line addes the connection to both nodes
        }

        vector<Edge>& getAdj(int v)
        {
            //use a pointer to dereference the address returned
            //iterator for vertices adjacent to v
            return adj[v];
        }

        void printAdj(int v)
        {
            if(v<0 || v>=Gsize){
                cout<<"Vertex index out of range\n";
                return;
            }
            cout<<"vertice "<<v<<" has "<<adj[v].size()<<" adjacent vertices:\n";
            for(const auto& edge : adj[v]){
                cout<< "(vertex: "<< edge.vertex<<", weight: "<<edge.weight<<")\n";
            }
            cout<<"\n";
        }


        ~DiGraph()
        {
            // delete adj;
            cout<<"DiGraph dynamically allocated memory deleted.\n";
            cout<<"Program terminated.";
        }
};
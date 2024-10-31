/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

#include <iostream>
#include <fstream>
#include <chrono>

#include "Digraph.h"
#include "BreadthFirstSearch.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;


    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/* OLD CODE:

    int V = 6; // Number of vertices
    Digraph G(V);

    // Add directed edges (example graph)
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(4, 5);

    // Perform BFS starting from vertex 0
    BreadthFirstSearch bfs(G, 0);
    bfs.printShortestPaths(0);

*/

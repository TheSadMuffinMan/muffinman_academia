//
//  BreadthFirstSearch.cpp
//  ShortestPaths
//
//  Created by Antoun, Sherine on 10/25/24.
//
#include "BreadthFirstSearch.h"
#include "Queue.h" // Include our custom queue implementation
#include <iostream>
#include <stdexcept> // For exception handling

// Constructor
BreadthFirstSearch::BreadthFirstSearch(const Digraph& G, int s) {
    numVertices = G.getVertices(); // Get and store the number of vertices
    marked = new bool[numVertices];
    edgeTo = new int[numVertices];
    distTo = new int[numVertices];

    // Initialize arrays
    for (int i = 0; i < numVertices; i++) {
        marked[i] = false;
        edgeTo[i] = -1;
        distTo[i] = -1;
    }

    // Run BFS from the source vertex
    bfs(G, s);
}

// Destructor
BreadthFirstSearch::~BreadthFirstSearch() {
    delete[] marked;
    delete[] edgeTo;
    delete[] distTo;
}

// Perform BFS from the source vertex s using the SimpleQueue
void BreadthFirstSearch::bfs(const Digraph& G, int s) {
    SimpleQueue<int> queue;
    marked[s] = true;
    distTo[s] = 0;
    queue.enqueue(s);

    while (!queue.isEmpty()) {
        int v = queue.dequeue();

        // Explore all adjacent vertices of v
        const SelfResizingArray<int>& adjList = G.getAdj(v);
        for (auto it = adjList.begin(); it != adjList.end(); ++it) {
            int w = *it;
            if (!marked[w]) {
                marked[w] = true;
                edgeTo[w] = v;
                distTo[w] = distTo[v] + 1;
                queue.enqueue(w);
            }
        }
    }
}

// Print the shortest path from the source vertex to all reachable vertices - backwards
void BreadthFirstSearch::printShortestPaths(int s) const {
    for (int i = 0; i < numVertices; i++) {
        if (marked[i]) {
            std::cout << "Shortest path to vertex " << i << " from vertex " << s << ": ";
            int pathVertex = i;
            while (pathVertex != s) {
                std::cout << pathVertex << " <- ";
                pathVertex = edgeTo[pathVertex];
            }
            std::cout << s << " (Distance: " << distTo[i] << ")" << std::endl;
        }
    }
}
/*

// Print the shortest path from the source vertex to all reachable vertices - forward
void BreadthFirstSearch::printShortestPaths(int s) const {
    for (int i = 0; i < numVertices; i++) {
        if (marked[i]) {
            std::cout << "Shortest path to vertex " << i << " from vertex " << s << ": ";

            // Reconstruct the path using the edgeTo array with SelfResizingArray
            SelfResizingArray<int> path;
            for (int x = i; x != s; x = edgeTo[x]) {
                path.add(x);
            }
            path.add(s); // Add the source vertex to the path

            // Print the path in reverse order (from source to the current vertex)
            for (int j = (int)path.getSize() - 1; j >= 0; j--) {
                std::cout << path[j];
                if (j > 0) {
                    std::cout << " -> ";
                }
            }

            std::cout << " (Distance: " << distTo[i] << ")" << std::endl;
        }
    }
}
*/

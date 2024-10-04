/*
DEPTH FIRST SEARCH:
    "Going down the rabbit hole."
    Is one of the oldest algorithms out there!
    One of the best representations of a graph is a Maze, especially the Pac-Man Maze!
    Goal: Systematically traverse a graph.
    Idea: Mimic maze exploration // Function-call stack acts as a ball of string.
*/

/* STEPS:
- Create a graph object.
- Pass the graph to a graph processing routine/function.
- Query the graph processing routine for information.

To visit a vertex (explore all adjacent nodes):
    - Mark vertex v as visited.
    - Recursively visit all unmarked vertices adjacent to v.
*/

/* DATA STRUCTURE:
- Boolean array marked[] to mark visited vertices.
- Integer array edgeTo[] to keep track of paths.
    "(edgeTo[w] == v) means that edge v-w taken to visit w for first time".
- Function-call stack for recursion.
*/

/* PROPERTIES:
After DFS, can check if vertex v is connected to s in constant time and can find v–s path (if one exists)
    in time proportional to its length.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
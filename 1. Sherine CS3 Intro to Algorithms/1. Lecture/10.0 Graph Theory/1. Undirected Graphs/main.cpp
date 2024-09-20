// WE HAVE ANOTHER 10 MINUTE QUIZ ON FRIDAY. GET HERE EARLY.
/*
UNDIRECTED GRAPH: consists of vertices connected pairwise by edges.
    Vertices <==> nodes.
    There are literally hundreds of different graph algorithms, many of which are very intricate.
    Examples of undirected graph data sets:
        USStatesUndirectedGraph.png
        FaceBook friend networks.
        The internet!

Generally speaking, in order to gain a better understanding of a problem, you must graph it.
    However, with how large graphs can be, observing them can be difficult.
*/

/*
GRAPH TERMINOLOGY:
    Path: Sequences of vertices connected by edges.
    Cycle: Path whose first and last vertices are the same.
Two vertices are connected if there is a path between them.

GRAPH PROCESSING PROBLEMS:
    "s-t" path: Is there a path between s and t?
    shortest "s-t" path: What is the shortest path between s and t?
    cycle: Is there a cycle in the graph?
    Euler cycle: Is there a cycle that uses each edge exactly once?
    Hamilton cycle: Is there a cycle that uses each vertex exactly once?
    bioconnectivity: Is there a vertiex whose removal disconnectes the graph?
    planarity: Can the graph be drawn in the plane with no crossing edges?
    graph isomorphism: Do two adjacency lists represent the same graph?
*/

/*
GRAPH API:
Drawing a graph provides intuition about the structure of the graph, but most graphs can be drawn correctly
    in a multitude of different ways.

Graph Class: Use ints between [0, (V - 1)].
    public:
        Graph(int V); // Creates an empty graph with V vertices.
        Graph(&inputStream); // Creates a graph from input stream.
        void addEdge(int v, int w); // Add the edge v-w.
        Iterable<int> adj(int v); // Returns vertices adjacent to v.
    private:
        int V(); // Number of vertices.
        int E(); // Number of edges.

For the adj() function, it is wise to maintain a vertex-indexed array of lists. See adjacencyList.png.
    The adjacency strikes the perfect balance between efficiency and computation time.
    Real world graphs tend to be sparse - meaning that they have a huge number of vertices and a smaller
        average vertex degree.
*/

/*
DEPTH FIRST SEARCH:
    Is one of the oldest algorithms out there!
    One of the best representations of a graph is a Maze, especially the Pac-Man Maze!
    Goal: Systematically traverse a graph.
    Idea: Mimic maze exploration // Function-call stack acts as a ball of string.
    

TREMAUX MAZE EXPLORATION:
    Algorithm instructions:
        Unroll a ball of string behind you.
        Mark each visited intersection and each visitied passage.
        Retrace steps when no unvisited options remain.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
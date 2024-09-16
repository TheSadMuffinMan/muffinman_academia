/*
If we allow multiple links to a node as well as from a node, the resulting data structure is called a GRAPH.

A graph is consisted of a set of NODES connected by EDGES.

A graph can be DIRECTED or UNDIRECTED.
    DIRECTED: A graph in which each edge may only be traversed in a specific direction.
    UNDIRECTED: Can navigate in any order.

A graph can be be CONNECTED if you can get from any node to any other node by following edges.
A Directed graph is strongly connected if you can get from any node to any other node by following
    directed edges.

A graph in which no paths exists from one node back to itself except by retracing one's steps is called
    an ACYCLIC graph.

A graph which can be drawn on a sheet of paper with no crossing edges is called a PLANAR graph.

A graph in which all nodes are connected are called a COMPLETE graph.
*/

/*
We can use graphs to represent a wide range of different data types, but representing a graph in code
    can be difficult.

REPRESENTING GRAPHS:
    As an EDGE LIST: a list/array of nodes. Each pair represents the presence of an edge.
    As an ADJANCENCY LIST: Each list gives the set of of nodes connected to a given starting node.
        The current node is represented by the index.
    As an ADJACENCY MATRIX: a two-dimensional, square array with as many rows (and columns) as there are nodes
        in the graph. Each entry indicates whether an edge exists between two nodes.
            Most of the time, Adjacency Matrixes are usually empty and use A LOT of memory.

WEIGHTED GRAPHS:
    Often we want to associate a number with each edge. 
        Examples include Length, Time, Cost, or Profit.
            We refer to these values as WEIGHTS.
    We also use an Edge List, an Adjacency List, or an Adjacency Matrix.
*/

/*
GRAPHS AND TREES
Trees are really just graphs with special restrictions. Technically, a BST is a connected, undirected acyclic graph.

Every connnected graph has one or more trees associated with it. We construct these trees by removing edges from the
    graph until the remaining edges form a tree.
    The resulting tree is called a SPANNING TREE.

If we construct a Spanning Tree for a weighted graph, we can obtain a cost for the Spanning Tree by adding together
    the weights of all edges of the tree.

Generally, these trees will have varying costs.
    The tree with the least cost is called the MINIMAL SPANNING TREE.

Example 1:
A number of towns are connected by roads. I need to upgrade the roads, but I cannot afford to pay for all of them.
    What is the least I can pay to allow travel from any town to any other town?
    Identify the parts:
        Nodes (The towns)
        Edges (The roads)
        Weights (Cost of upgrading the road)
        Task (Find the MINIMAL SPANNING TREE)

Example 2: Complete Factorisation
Given an integer, show its factors in such a way that the factors of the factors are also shown.
    Nodes: The factors.
    Edges: "... is a factor of ..." relation.
    No weights.
    Task: Find the graph.

Example 3: Traffic Costs
Given a complex computer network (the internet), find the fastest way to send a message from one computer to another.
    Nodes: The devices; computers and routers.
    Edges: The links between devices.
    Weights: The time taken to send a message over this link.
    Task: Find the shortest path between two specified devices.

Example 4: Travelling Salesman (NP-Hard problem)
A salesman must visit customers in a number of towns before returning home. They must never retrace their route,
    and they want to spend as little on fuel as possible. What route should they take?
    Nodes: The towns they must visit.
    Edges: The roads between the towns.
    Weights: The fuel cost to travel on this road/edge.
    Task: Find the shortest closed loop that visits all nodes.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
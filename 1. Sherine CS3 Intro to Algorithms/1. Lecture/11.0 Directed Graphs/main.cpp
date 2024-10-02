/*
DIRECTED GRAPHS (Digraphs): A set of vertices connected pairwise by DIRECTED edges.
    Directed Edges: A "one way street" type of connection.

Outdegree: The amount of outbound connections each node vertice has.
Indegree: The amound of inbound connections each vertice has.
*/

/*
Digraph Problems:
    Path - Is there a directed path from s to t?
    Shortest Path - What is the shortest directed path from s to t?
    Topological Sort - Can you draw a digraph so that all edges point upwards?
    Strong Connectivity - Is there a directed path between all pairs of vertices?
    Transitive Closure - For which vertices v and w is there a path from v to w?

Digraph Applications:
    Transportation: street intersection (vertex), one-way street (directed edge).
    Web: web page (vertex), hyperlink (directed edge).
    Food Web: species (vertex), predator-prey relationships (directed edge).
    Scheduling: task (vertx), precedence constraint (directed edge).

In practice, real-world digraphs tend to be sparse (meaning they have a huge number of vertices and a small
    average vertex degree).
Digraphs are best used for iterating over vertices pointing from vertex v.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
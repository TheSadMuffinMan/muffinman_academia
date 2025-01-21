/*
BREADTH FIRST SEARCH:
- A graph traversal approach in which you start at a source node and layer by layer through the graph,
    analyzing the nodes directly related to the source node.
- Not a recursive data structure! :D
*/

/* DATA STRUCTURE:
- Utilizes a queue and places source node in the queue first.
- Add to queue all unmarked vetices pointing form (source) and mark them.
*/

/* STEPS:
Remove vertex v from queue.
Add to queue all unmarked vertices adjacent to v and mark them.
*/

#include <iostream>


int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/* Breadth First Search Java implementation:
public class BreadthFirstPaths
{
private boolean[] marked;
private int[] edgeTo;
private int[] distTo;
...
private void bfs(Graph G, int s) {
Queue<Integer> q = new Queue<Integer>();
q.enqueue(s);
marked[s] = true;
distTo[s] = 0;
while (!q.isEmpty()) {
int v = q.dequeue();
for (int w : G.adj(v)) {
if (!marked[w]) {
q.enqueue(w);
marked[w] = true;
edgeTo[w] = v;
distTo[w] = distTo[v] + 1;
}
}
}
*/
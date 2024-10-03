// PROGRAM 17.2
#include <stdio.h>
#include "graphInterface.h"

int main(int argc, char* argv[])
{
    // Reading V and E from standard input.
    int V = std::atoi(argv[1]), E = std::atoi(argv[2]);
    // Graph G = Graph::GRAPHrand(V, E); // ***DEBUG*** FUNCTION NOT IMPLEMENTED YET.

    if (V < 20)
    {
        // Graph::GRAPHshow(G); // ***DEBUG*** FUNCTION NOT IMPLEMENTED YET.
    }
    else
    {
        printf("%d vertices, %d edges,", V, E);
        // printf("%d component (s)\n", Graph::GRAPHcc(G)); // ***DEBUG*** FUNCTION NOT IMPLEMENTED YET.
    }
    return 0;
}
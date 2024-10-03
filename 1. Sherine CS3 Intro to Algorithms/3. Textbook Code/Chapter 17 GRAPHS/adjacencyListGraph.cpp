#pragma once

#include <stdlib.h>
#include "graphInterface.h"

typedef struct node *link;

struct node
{
    int v;
    link next;
};

struct graph
{
    int V;
    int E;
    link *adj;
};

link NEW(int v, link next)
{
    link x = std::malloc(sizeof(*x));
    x->v = v;
    x->next = next;
    return x;
}

Graph GRAPHinit(int V)
{
    int v;
    Graph G = malloc(V * sizeof(link));
    G->V = V;
    G->E = 0;
    G->adj = malloc(V * sizeof(link));
    for (v = 0; v < V; v++)
    {
        G->adj[v] = NULL;
    }

    return G;
}
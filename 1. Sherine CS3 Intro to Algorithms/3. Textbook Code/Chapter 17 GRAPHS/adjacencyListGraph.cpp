#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "graphInterface.h"

typedef struct node *link;

struct node
{
    int v;
    link* next;
};

struct graph
{
    int V;
    int E;
    link *adj;
};

link* NEW(int v, link* next)
{
    // link x = malloc(sizeof(*x)); // Dynamic memory allocation.
    link* x = new link;
    x->v = v;
    x->next = next;
    return x;
}

Graph GRAPHinit(int V)
{
    int v;
    Graph *G = new Graph(V);
    G->V = V;
    G->E = 0;
    G->adj = malloc(V * sizeof(link));
    for (v = 0; v < V; v++)
    {
        G->adj[v] = NULL;
    }

    return G;
}

void GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    G->adj[v] = NEW(w, G->adj[v]);
    G->adj[w] = NEW(v, G->adj[w]);
    G->E++;
}

int GRAPHedges(Edge a[], Graph G)
{
    int v, E = 0;
    link t;
    for (v = 0; v < G->V; v++)
    {
        for (t = G->adj[v]; t != NULL; t = t->next)
        {
            if (v < t->v)
            {
                a[E++] = EDGE(v, t->v);
            }
        }
    }

    return E;
}
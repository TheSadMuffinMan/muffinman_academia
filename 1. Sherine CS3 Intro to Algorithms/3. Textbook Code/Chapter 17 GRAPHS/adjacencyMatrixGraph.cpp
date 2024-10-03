#pragma once

#include <stdlib.h>
#include "graphInterface.h"

struct graph{int V; int E; int **adj;};
Graph GRAPHinit(int V)
{
    Graph G = std::malloc(sizeof(*G));
    G->V = V;
    G->E = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

void GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
    {
        G->E++;
    }

    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void GRAPHremoveE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
    {
        G->E--;
    }

    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int GRAPHedges(Edge a[], Graph G)
{
    int v, w;
    int E = 0;

    for (v = 0; v < (G->V); v++)
    {
        for (w = (v+1), w < (G->V); w++)
        {
            if ((G->adj[v][w]) == 1)
            {
                a[E++] = EDGE(v,w);
            } 
        }
    }
    return E;
}

/*
This function is PROGRAM 17.4 in the textbook.
Function is used to allocate memory and intialize a graph with no edges.
*/
int **MATRIXint(int r, int c, int val)
{
    int i, j;
    int **t = std::malloc(r * sizeof(int*));

    for (i = 0; i < r; i++)
    {
        t[i] = std::malloc(c * sizeof(int));
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            t[i][j] = val;
        }
    }

    return t;
}

/*
This function is PROGRAM 17.5 IN TEXTBOOK.
Function prints out the full adjacency matrix.
*/
void GRAPHshow(Graph G)
{
    int i, j;
    printf("%d vertices, %d edges\n", G->V, G->E);
    for (j = 0; j < G->V, j++)
    {
        if (G->adj[i][j] == 1)
        {
            printf("%2d", j);
        }
        printf("\n");
    }
}
// TEXTBOOK PROGRAM 17.1
#pragma once
#include <iostream>

typedef struct {int v; int w;} Edge;
Edge EDGE (int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void GRAPHinsertE(Graph, Edge);
void GRAPHremoveE(Graph, Edge);
int GRAPHedges(Edge[], Graph G);
Graph GRAPHcopy(Graph);
void GRAPHdestroy(Graph);
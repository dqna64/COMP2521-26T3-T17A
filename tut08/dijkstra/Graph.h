#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>


typedef struct graph {
  int nV;
  int **adjMatrix;
} *Graph;

Graph GraphNew(int nV);
void GraphFree(Graph g);
int GraphNumVertices(Graph g);
bool GraphHasEdge(Graph g, int v, int w);
int GraphWeight(Graph g, int v, int w);
void GraphInsert(Graph g, int v, int w, int weight);

#endif

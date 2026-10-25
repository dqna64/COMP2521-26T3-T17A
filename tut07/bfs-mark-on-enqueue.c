/*

Correct BFS implementation for cyclic graph

*/

#include "queue.h"

typedef struct graph {
    int nV;
    bool *edges[];
} *Graph;

void breadthFirst(Graph g, int src) {
        bool *toVisit = calloc(g->nV, sizeof(bool));
        int *pred = calloc(g->nV, sizeof(int));
        Queue q = QueueNew();

        QueueEnqueue(q, src);
        toVisit[src] = true;

        while (!QueueIsEmpty(q)) {
                int v = QueueDequeue(q);

                printf("Visiting: %d\n", v);
                for (int w = 0; w < g->nV; w++) {
                        if (g->edges[v][w] && !toVisit[w]) {
                                pred[w] = v;
                                toVisit[w] = true;
                                QueueEnqueue(q, w);
                        }
                }
        }

        free(toVisit);
        free(pred);
        QueueFree(q);
}


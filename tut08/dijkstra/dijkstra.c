#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "dijkstra.h"

int getClosestUnvisited(int* dist, bool* visited, int size);
bool all(bool* arr, int size);

// Run Dijkstra's algorithm on the directed weighted graph g with source vertex
// v. Expects weights of g to be non-negative.
// When complete:
// - dist[i] array will show the shortest distance from vertex src to vertex i
// - pred[i] array will show predecessor vertex of vertex i along shortest path
//      from src to i.
void dijkstra(Graph g, int src, bool* visited, int* dist, int* pred) {
    while (!all(visited, GraphNumVertices(g))) {
        int v = getClosestUnvisited(dist, visited, GraphNumVertices(g));
        printf("Visiting: %d\n", v);
        visited[v] = true;

        for (int w = 0; w < GraphNumVertices(g); w++) {
            if (!GraphHasEdge(g, v, w)) continue;
            // Attempt relax along edge v->w
            if (dist[v] + GraphWeight(g, v, w) < dist[w]) {
                dist[w] = dist[v] + GraphWeight(g, v, w);
                pred[w] = v;
            }
        }
    }

}

// =============================================================================
// ============================= Helper functions ==============================
// =============================================================================
bool all(bool* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (!arr[i]) return false;
    }
    return true;
}

int getClosestUnvisited(int* dist, bool* visited, int size) {
    int* unvisited = calloc(size, sizeof(int));
    int unvisitedCount = 0;
    for (int v = 0; v < size; v++) {
        if (!visited[v]) {
            unvisited[unvisitedCount++] = v;
        }
    }

    // Find the vertex among the unvisited vertices that has the shortest
    // current known dist from src
    int unvisitedVertexClosest = -1;
    int shortestDist = INT_MAX;
    for (int i = 0; i < unvisitedCount; i++) {
        int v = unvisited[i];
        if (dist[v] < shortestDist) {
            shortestDist = dist[v];
            unvisitedVertexClosest = v;
        }
    }

    free(unvisited);

    return unvisitedVertexClosest;
}

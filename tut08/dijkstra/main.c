/**
 * Run:
 * ```
 * $ gcc main.c dijkstra.c Graph.c && ./a.out
 */

#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Graph.h"
#include "dijkstra.h"

int main() {
    // === Setup graph === 
    Graph g = GraphNew(5);
    GraphInsert(g, 0, 1, 7);
    GraphInsert(g, 0, 2, 6);
    GraphInsert(g, 0, 3, 4);
    GraphInsert(g, 2, 3, 1);
    GraphInsert(g, 1, 3, 8);
    GraphInsert(g, 2, 4, 2);
    GraphInsert(g, 3, 4, 4);
    
    int src = 0;


    // === Initialisation for Dijkstra ===
    
    // Create array visited[i] to track whether vertex i has been visited yet
    // i.e. the true shortest path from src to i has been found.
    bool* visited = calloc(GraphNumVertices(g), sizeof(bool));
    for (int i = 0; i < GraphNumVertices(g); i++) {
        visited[i] = false;
    }

    // Create array dist[i] -- an array of current shortest
    // distance from src vertex to vertex i.
    // Initialise all to -1 to represent infinity distance from src.
    // Note: pred[src] should always remain -1
    int* dist = calloc(GraphNumVertices(g), sizeof(int));
    for (int i = 0; i < GraphNumVertices(g); i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Create array pred[i] -- an array keeping the current predecessor vertex
    // along the current known shortest path from src to vertex i
    // Initialise all to -1 to represent no predecessory vertex.
    // Note: pred[src] should always remain -1
    int* pred = calloc(GraphNumVertices(g), sizeof(int));
    for (int i = 0; i < GraphNumVertices(g); i++) {
        pred[i] = -1;
    }


    // === Run Dijkstra ===

    dijkstra(g, src, visited, dist, pred);


    // === See result ===

    printf("visited array: ");
    for (int i = 0; i < GraphNumVertices(g); i++) {
        printf("%s, ", visited[i] ? "true" : "false");
    }
    printf("\n");

    printf("dist array: ");
    for (int i = 0; i < GraphNumVertices(g); i++) {
        printf("%d, ", dist[i]);
    }
    printf("\n");

    printf("pred array: ");
    for (int i = 0; i < GraphNumVertices(g); i++) {
        printf("%d, ", pred[i]);
    }
    printf("\n");
    

    // === Cleanup ===
    free(visited);
    free(dist);
    free(pred);
    GraphFree(g);
}

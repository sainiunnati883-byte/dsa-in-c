#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** adj, int* adjSize, int* visited, int* stack, int* top) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next, adj, adjSize, visited, stack, top);
        }
    }

    stack[(*top)++] = node;   // push after visiting children
}

void topologicalSort(int V, int** adj, int* adjSize) {
    int* visited = (int*)calloc(V, sizeof(int));
    int* stack = (int*)malloc(V * sizeof(int));
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, adjSize, visited, stack, &top);
        }
    }

    // print in reverse stack order
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(visited);
    free(stack);
}
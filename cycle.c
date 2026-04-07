#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int** adj, int* adjSize, int* vis, int* pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!vis[neighbor]) {
            if (dfs(neighbor, adj, adjSize, vis, pathVis))
                return true;
        }
        else if (pathVis[neighbor]) {
            return true; // cycle detected
        }
    }

    pathVis[node] = 0; // backtrack
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int)); // max possible edges
    }

    // input edges (u -> v)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    int* vis = (int*)calloc(n, sizeof(int));
    int* pathVis = (int*)calloc(n, sizeof(int));

    // check all components
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, adjSize, vis, pathVis)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
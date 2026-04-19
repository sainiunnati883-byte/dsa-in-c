#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with large values
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    int visited[MAX] = {0};
    int minEdge[MAX];
    int parent[MAX];

    // Initialize
    for(int i = 1; i <= n; i++) {
        minEdge[i] = INT_MAX;
        parent[i] = -1;
    }

    minEdge[1] = 0; // Start from node 1

    int totalWeight = 0;

    for(int i = 1; i <= n; i++) {
        int u = -1;

        // Find unvisited node with minimum edge
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += minEdge[u];

        // Update adjacent nodes
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
#include <stdio.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];

// DFS function
void dfs(int v, int n) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, s;

    // Input number of vertices
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input starting vertex
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    dfs(s, n);

    return 0;
}
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = 0, rear = 0;

// Enqueue
void enqueue(int v) {
    queue[rear++] = v;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// BFS function
void bfs(int s, int n) {
    enqueue(s);
    visited[s] = 1;

    while (front < rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
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

    // Input source vertex
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform BFS
    bfs(s, n);

    return 0;
}
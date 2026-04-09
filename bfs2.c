#include <stdio.h>
#include <stdlib.h>

void topologicalSort(int V, int** adj, int* adjSize) {
    int* indegree = (int*)calloc(V, sizeof(int));

    // calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adjSize[i]; j++) {
            indegree[adj[i][j]]++;
        }
    }

    // queue
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    // push all nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // process queue
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i];
            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    printf("\n");

    free(indegree);
    free(queue);
}
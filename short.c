#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1001

// Graph Node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap Node
typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// Pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

// Dijkstra with PQ
void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode curr = pop();
        int u = curr.node;
        int d = curr.dist;

        // Skip outdated entries
        if (d > dist[u]) continue;

        Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}
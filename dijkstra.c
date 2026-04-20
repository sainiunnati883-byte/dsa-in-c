#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    Node* n1 = createNode(v, w);
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = createNode(u, w);
    n2->next = adj[v];
    adj[v] = n2;
}

// Min heap structure
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

// Swap heap nodes
void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i, right = 2*i + 1;

    if (left <= size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right <= size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int node, int dist) {
    heap[++size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
}

// Pop from heap
HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[size--];
    heapifyDown(1);
    return top;
}

// Dijkstra
void dijkstra(int n, int source) {
    int dist[MAX];
    
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode cur = pop();
        int u = cur.node;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
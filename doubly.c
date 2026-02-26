#include <stdio.h>
#include <stdlib.h>

// Define Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Insert node at tail
Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Attach new node
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Traverse forward
void printForward(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtTail(head, value);
    }

    printForward(head);

    return 0;
}
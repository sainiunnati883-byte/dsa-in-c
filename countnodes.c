#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    return head;
}

// Function to print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createList(n);

    // Print elements (as per example)
    printList(head);

    // Uncomment below if you need count instead
    // printf("\nTotal Nodes = %d", countNodes(head));

    return 0;
}
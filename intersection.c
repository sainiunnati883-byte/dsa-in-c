#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    int diff = abs(len1 - len2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    
    // Move longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }
    
    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data)
            return ptr1->data;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1; // No intersection
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head1, value);
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insert(&head2, value);
    }
    
    int result = findIntersection(head1, head2);
    
    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);
    
    return 0;
}
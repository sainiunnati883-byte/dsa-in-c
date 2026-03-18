#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue for TreeNode
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Create tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = root->right = NULL;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct TreeNode* curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            struct TreeNode* leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            leftNode->val = arr[i];
            leftNode->left = leftNode->right = NULL;
            curr->left = leftNode;
            enqueue(&q, leftNode);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            struct TreeNode* rightNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            rightNode->val = arr[i];
            rightNode->left = rightNode->right = NULL;
            curr->right = rightNode;
            enqueue(&q, rightNode);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);
            printf("%d ", node->val);

            if (node->left)
                enqueue(&q, node->left);

            if (node->right)
                enqueue(&q, node->right);
        }
        printf("\n");  // next level
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
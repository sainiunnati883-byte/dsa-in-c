#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Queue structure for tree construction */

Node* queue[100];
int front = 0, rear = 0;

void enqueue(Node* node){
    queue[rear++] = node;
}

Node* dequeue(){
    return queue[front++];
}

int isEmpty(){
    return front == rear;
}

/* Build tree from level order */

Node* buildTree(int arr[], int n){

    if(arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while(i < n && !isEmpty()){
        Node* current = dequeue();

        /* Left child */
        if(i < n && arr[i] != -1){
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        /* Right child */
        if(i < n && arr[i] != -1){
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

/* Inorder traversal */

void inorder(Node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* root = buildTree(arr,n);

    inorder(root);

    return 0;
}
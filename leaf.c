#include <stdio.h>
#include <stdlib.h>

// Structure of tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Count leaf nodes
int countLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

// Example usage
int main() {
    // Manually creating tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Leaf nodes count: %d\n", countLeaves(root));

    return 0;
}
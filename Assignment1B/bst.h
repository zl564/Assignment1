#ifndef BST_H
#define BST_H

// Binary Search Tree Node Structure
typedef struct BSTNode {
    int borrowerID;
    char borrowerName[100];
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Function declarations for Binary Search Tree management
BSTNode* insertBST(BSTNode* root, int key, char* borrowerName);
BSTNode* deleteBST(BSTNode* root, int key);
BSTNode* searchBST(BSTNode* root, int key);
void inOrderTraversal(BSTNode* root);
void freeBST(BSTNode* root);

#endif
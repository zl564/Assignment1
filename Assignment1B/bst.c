#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100  // Define a maximum length for borrower names

BSTNode* createNode(int key, char* borrowerName) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (newNode != NULL) {
        newNode->borrowerID = key;
        strcpy_s(newNode->borrowerName, MAX_NAME_LENGTH, borrowerName);
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

BSTNode* insertBST(BSTNode* root, int key, char* borrowerName) {
    if (root == NULL) {
        return createNode(key, borrowerName);
    }
    if (key < root->borrowerID) {
        root->left = insertBST(root->left, key, borrowerName);
    }
    else if (key > root->borrowerID) {
        root->right = insertBST(root->right, key, borrowerName);
    }
    return root;
}

BSTNode* findMin(BSTNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

BSTNode* deleteBST(BSTNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->borrowerID) {
        root->left = deleteBST(root->left, key);
    }
    else if (key > root->borrowerID) {
        root->right = deleteBST(root->right, key);
    }
    else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = findMin(root->right);
        root->borrowerID = temp->borrowerID;
        strcpy_s(root->borrowerName, MAX_NAME_LENGTH, temp->borrowerName);
        root->right = deleteBST(root->right, temp->borrowerID);
    }
    return root;
}

BSTNode* searchBST(BSTNode* root, int key) {
    if (root == NULL || root->borrowerID == key) {
        return root;
    }
    if (key < root->borrowerID) {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

void inOrderTraversal(BSTNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Borrower ID: %d, Name: %s\n", root->borrowerID, root->borrowerName);
        inOrderTraversal(root->right);
    }
}

void freeBST(BSTNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}
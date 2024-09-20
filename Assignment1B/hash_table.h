#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "bst.h"

#define TABLE_SIZE 100  // Define the hash table size

typedef struct {
    BSTNode* root;  // Each bucket contains a binary search tree of borrowers
    char book_title[100];  // Title of the book
} HashTable;

// Function declarations for hash table management
void initializeHashTable(HashTable* table);
int hashFunction(int key);  // Hash function to determine index
void insertBorrowerToBook(HashTable* table, int bookID, int borrowerID, char* borrowerName);
void printAllBooks(HashTable* table);
void printBorrowersForBook(HashTable* table, int bookID);
void freeHashTable(HashTable* table);

#endif
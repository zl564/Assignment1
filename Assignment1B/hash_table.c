#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100  // Define a maximum length for book titles

void initializeHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].root = NULL;
        strcpy_s(table[i].book_title, MAX_TITLE_LENGTH, "");
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert borrower into a book's BST
void insertBorrowerToBook(HashTable* table, int bookID, int borrowerID, char* borrowerName) {
    int index = hashFunction(bookID);
    if (strcmp(table[index].book_title, "") == 0) {
        printf("Enter the book title for Book ID %d: ", bookID);
        scanf_s(" %[^\n]", table[index].book_title, (unsigned)_countof(table[index].book_title));  // Accept the book title
    }
    table[index].root = insertBST(table[index].root, borrowerID, borrowerName);
}

// Print all books stored in the hash table
void printAllBooks(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].root != NULL) {
            printf("Book ID %d, Title: %s\n", i, table[i].book_title);
        }
    }
}

// Print all borrowers for a specific book
void printBorrowersForBook(HashTable* table, int bookID) {
    int index = hashFunction(bookID);
    if (table[index].root != NULL) {
        printf("Borrowers for Book ID %d, Title: %s\n", bookID, table[index].book_title);
        inOrderTraversal(table[index].root);  // Print all borrowers in sorted order
    }
    else {
        printf("No borrowers found for Book ID %d.\n", bookID);
    }
}

// Free the memory used by the hash table and all BSTs
void freeHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].root != NULL) {
            freeBST(table[i].root);
        }
    }
}
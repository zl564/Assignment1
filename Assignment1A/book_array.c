#include "book_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 100  // Define a maximum length for book titles

Book bookArray[MAX_BOOKS];
int numBooks = 0;

// Initialize the book array
void initializeBookArray() {
    numBooks = 0;
}

// Insert a new book into the book array
void insertBook(int book_id, char* title) {
    if (numBooks < MAX_BOOKS) {
        bookArray[numBooks].book_id = book_id;
        strcpy_s(bookArray[numBooks].title, MAX_TITLE_LENGTH, title);
        bookArray[numBooks].borrowers_head = NULL;  // No borrowers initially
        numBooks++;
    }
    else {
        printf("Array is full\n");
    }
}

// Add a borrower to a specific book's borrower list
void addBorrowerToBook(int book_id, int borrower_id, char* borrower_name) {
    for (int i = 0; i < numBooks; i++) {
        if (bookArray[i].book_id == book_id) {
            bookArray[i].borrowers_head = insertAtFront(bookArray[i].borrowers_head, borrower_id, borrower_name);
            return;
        }
    }
    printf("Book ID %d not found\n", book_id);
}

// Print all books in the array
void printAllBooks() {
    for (int i = 0; i < numBooks; i++) {
        printf("Book ID: %d, Title: %s\n", bookArray[i].book_id, bookArray[i].title);
    }
}

// Print all borrowers associated with a given book
void printBorrowersForBook(int book_id) {
    for (int i = 0; i < numBooks; i++) {
        if (bookArray[i].book_id == book_id) {
            printf("Borrowers for Book ID: %d, Title: %s\n", bookArray[i].book_id, bookArray[i].title);
            printList(bookArray[i].borrowers_head);
            return;
        }
    }
    printf("Book ID %d not found\n", book_id);
}

// Free all memory associated with the book array
void freeBookArray() {
    for (int i = 0; i < numBooks; i++) {
        freeList(bookArray[i].borrowers_head);
    }
}
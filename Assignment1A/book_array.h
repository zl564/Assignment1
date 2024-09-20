#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "linked_list.h"

typedef struct {
    int book_id;
    char title[256];
    ListNode* borrowers_head;  // Linked list of borrowers associated with this book
} Book;

// Function declarations for managing the book array
void initializeBookArray();
void insertBook(int book_id, char* title);
void addBorrowerToBook(int book_id, int borrower_id, char* borrower_name);
void printAllBooks();
void printBorrowersForBook(int book_id);
void freeBookArray();

#endif

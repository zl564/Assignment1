#include "hash_table.h"
#include <stdio.h>

int main() {
    HashTable bookTable[TABLE_SIZE];
    initializeHashTable(bookTable);

    // Inserting borrowers into books
    insertBorrowerToBook(bookTable, 1, 101, "John Doe");
    insertBorrowerToBook(bookTable, 1, 102, "Jane Doe");
    insertBorrowerToBook(bookTable, 2, 103, "Alice Johnson");
    insertBorrowerToBook(bookTable, 2, 104, "Bob Smith");

    // Print all books
    printf("\nAll Books:\n");
    printAllBooks(bookTable);

    // Print borrowers for specific book
    printf("\nBorrowers for Book ID 1:\n");
    printBorrowersForBook(bookTable, 1);

    printf("\nBorrowers for Book ID 2:\n");
    printBorrowersForBook(bookTable, 2);

    // Free memory
    freeHashTable(bookTable);

    return 0;
}
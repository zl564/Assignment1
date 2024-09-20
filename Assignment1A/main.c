#include "book_array.h"
#include <stdio.h>

int main() {
    initializeBookArray();

    // Insert some books
    insertBook(1, "C Programming");
    insertBook(2, "Data Structures");

    // Add borrowers to the books
    addBorrowerToBook(1, 101, "John Doe");
    addBorrowerToBook(1, 102, "Jane Doe");
    addBorrowerToBook(2, 103, "Alice Smith");

    // Print all books
    printAllBooks();

    // Print borrowers for a specific book
    printf("\nBorrowers for Book ID 1:\n");
    printBorrowersForBook(1);

    // Print borrowers for another book
    printf("\nBorrowers for Book ID 2:\n");
    printBorrowersForBook(2);

    // Free memory
    freeBookArray();

    return 0;
}
#include "book_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BOOKS 1000
#define NUM_BORROWERS_PER_BOOK 10

// Function to generate random strings for book titles and borrower names
void generateRandomString(char* str, int length) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length - 1; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length - 1] = '\0';
}

// Function to populate books and borrowers
void populateBooksAndBorrowers() {
    char title[100];
    char name[100];
    for (int i = 0; i < NUM_BOOKS; i++) {
        generateRandomString(title, sizeof(title));
        insertBook(i, title);
        for (int j = 0; j < NUM_BORROWERS_PER_BOOK; j++) {
            generateRandomString(name, sizeof(name));
            addBorrowerToBook(i, i * 100 + j, name);
        }
    }
}

#ifdef PERFORMANCE_TEST

int main() {
    srand(time(NULL)); // Seed random number generator
    initializeBookArray();

    // Start timing
    clock_t start = clock();

    // Populate the book array and linked lists
    populateBooksAndBorrowers();

    // Measure time after insertion
    clock_t end_insert = clock();
    double time_spent_insert = (double)(end_insert - start) / CLOCKS_PER_SEC;
    printf("Time to insert %d books and %d borrowers per book: %.2f seconds\n",
        NUM_BOOKS, NUM_BORROWERS_PER_BOOK, time_spent_insert);

    // Print all books (optional)
    // printAllBooks();

    // Measure retrieval time for a specific book's borrowers
    start = clock();
    printBorrowersForBook(NUM_BOOKS / 2); // Example: Print borrowers for the middle book
    end_insert = clock();
    double time_spent_retrieve = (double)(end_insert - start) / CLOCKS_PER_SEC;
    printf("Time to retrieve borrowers for one book: %.5f seconds\n", time_spent_retrieve);

    // Free all allocated memory
    freeBookArray();

    return 0;
}
#endif
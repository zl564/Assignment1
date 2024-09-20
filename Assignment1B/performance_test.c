#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BOOKS 100
#define NUM_BORROWERS_PER_BOOK 1000

// Function to generate random names
void generateRandomName(char* name, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length - 1; i++) {
        int key = rand() % (sizeof(charset) - 2);
        name[i] = charset[key];
    }
    name[length - 1] = '\0';
}

// Function to populate the hash table with test data
void populateHashTable(HashTable* table) {
    for (int bookID = 1; bookID <= NUM_BOOKS; bookID++) {
        char name[100];
        for (int borrowerID = 1; borrowerID <= NUM_BORROWERS_PER_BOOK; borrowerID++) {
            generateRandomName(name, sizeof(name) - 1);
            insertBorrowerToBook(table, bookID, borrowerID, name);
        }
    }
}

// Main function to run performance tests
#ifdef PERFORMANCE_TEST
int main() {
    srand(time(NULL));
    HashTable bookTable[TABLE_SIZE];
    initializeHashTable(bookTable);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    populateHashTable(bookTable);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to insert %d books with %d borrowers each: %f seconds\n", NUM_BOOKS, NUM_BORROWERS_PER_BOOK, cpu_time_used);

    // Example search test for performance
    start = clock();
    for (int bookID = 1; bookID <= NUM_BOOKS; bookID++) {
        for (int borrowerID = 1; borrowerID <= 100; borrowerID++) {  // Testing only first 100 for brevity
            searchBST(bookTable[hashFunction(bookID)].root, borrowerID);
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to search 100 borrowers in each of %d books: %f seconds\n", NUM_BOOKS, cpu_time_used);

    // Free memory
    freeHashTable(bookTable);
    return 0;
}
#endif
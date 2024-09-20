#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100  // Define a maximum length for borrower names

// Insert a new borrower at the front of the linked list
ListNode* insertAtFront(ListNode* head, int id, char* name) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode) {
        newNode->borrower_id = id;
        strcpy_s(newNode->borrower_name, MAX_NAME_LENGTH, name);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Print all borrowers in the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        printf("Borrower ID: %d, Name: %s\n", current->borrower_id, current->borrower_name);
        current = current->next;
    }
}

// Free all nodes in the linked list
void freeList(ListNode* head) {
    ListNode* current = head;
    while (head) {
        current = head;
        head = head->next;
        free(current);
    }
}
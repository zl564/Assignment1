#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ListNode {
    int borrower_id;
    char borrower_name[100];
    struct ListNode* next;
} ListNode;

// Linked list function declarations
ListNode* insertAtFront(ListNode* head, int id, char* name);
void printList(ListNode* head);
void freeList(ListNode* head);

#endif

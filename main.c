// File: main.c
// This is the main program that will the linked list library.
#include "linkedlist.h"
#include <stdio.h>

int main() {
    // create head as a single pointer initialized to NULL
    Node* head = NULL;

    // create each node by passing the address of the head.
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // View the current linked list.
    printf("Printing the linked list:\n");
    printList(head);

    // Delete a node by value
    deleteNode(&head, 2);

    // Add a new node to the END of the linked list.
    insertAtEnd(&head, 4);

    // View the list after modifications.
    printf("Printing the linked list:\n");
    printList(head);

    // free the entire list
    freeList(head);

    return 0;
}

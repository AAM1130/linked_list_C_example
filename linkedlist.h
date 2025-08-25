//
// Created by SituationUnknown on 8/22/2025.
//

#ifndef LINKED_LISTS_LINKEDLIST_H
#define LINKED_LISTS_LINKEDLIST_H

#include <stdio.h>

// Declare the Node structure.
// Use a typedef to create the alias 'Node' for the struct
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes for library functions
Node* createNode(int value);
void insertAtBeginning(Node** head, int value);
void insertAtEnd(Node** head, int value);
void printList(Node* head);
void deleteNode(Node** head, int valueToDelete);
void freeList(Node* head);

// remove all references to head node and change to head pointer....
// add insertAtPosition(Node* head, int position, int value.

#endif //LINKED_LISTS_LINKEDLIST_H
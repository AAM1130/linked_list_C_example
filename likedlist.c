//
// Created by SituationUnknown on 8/22/2025.
//

#include "linkedlist.h"
#include <stdlib.h> // For malloc() and free()

// Function to create a new node.
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a new node at the beginning of the linked list.
// Note: In this case the argument for the list head is passed as a pointer to a pointer.
// This allows the pointer contents to be modified.
void insertAtBeginning(Node** head, int value) {
    // Create the new node to be inserted.
    Node* newNode = createNode(value);

    // Copy head next to the new node.
    newNode->next = *head;      // dereference pointer.

    // Copy new node location to head next.
    *head = newNode;        // dereference pointer.
}

// Function to insert a new node at the end of the list.
void insertAtEnd(Node** head, int value) {
    // Create the new node to be inserted.
    Node* newNode = createNode(value);

    // If current list is empty, new node becomes head.
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Find the last node in the list.
    Node* current = *head;      // dereference pointer
    while (current->next != NULL) {
        current = current->next;
    }

    // Link the last node to the new node.
    current->next = newNode;
}

// Function to free all nodes in the linked list.
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to delete a specified node from the linked list.
void deleteNode(Node** head, int valueToDelete) {
    // Check for proper input, do nothing if not given.
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }

    // If the valueToDelete is the current head.
    if ((*head)->data == valueToDelete) {
        Node* nodeToFree = *head;
        *head = (*head)->next;  // change head pointer to value stored in the next node
        free(nodeToFree);       // free the node
        printf("Deleted node with value: %d\n", valueToDelete);
        return;
    }

    // Find the last node before the one to delete, and set it to current
    Node* current = *head;
    while (current->next != NULL && current->next->data != valueToDelete) {
        current = current->next;
    }

    // Check that the current node is not the last node!
    if (current->next != NULL) {
        // Make a temp pointer to the nodeToFree
        Node* nodeToFree = current->next;
        // Change the pointer of the current node to the pointer of the node to delete.
        current->next = nodeToFree->next;
        // Free the node to delete
        free(nodeToFree);
        printf("Deleted node with value: %d\n", valueToDelete);
    } else {
        printf("Error: Node not found.\n");
    }
}

// Function to print the entire linked list, starting from the head.
void printList(Node* head) {
    // Start at the head pointer
    Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
    } else {
        // Traverse the entire list up to the last node.
        while (current != NULL) {
            printf("Node: Data: %d\n", current->data);
            current = current->next;
        }
    }
}

#include <iostream>
#include "reverse_list.h" // Includes function declarations from the header file

using namespace std;

Node *head = NULL; // Global pointer initially points to NULL because the list is empty

void append(int value) {
    Node *newNode = new Node(); // Create a new node in dynamic memory
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) { // If the list is empty, the new node becomes the first node
        head = newNode; // Global pointer now points to the new node
        return;
    }

    Node *current = head; // Start from the first node pointed to by 'head'
    while (current->next != NULL) // Continue until the next pointer becomes NULL
        current = current->next; // Move to the next node

    current->next = newNode; // The last node now points to the new node
}

void reverseList() {

    if (head == NULL || head->next == NULL)
        throw "Cannot reverse a list containing one or fewer elements";

    Node *previous = NULL; // Pointer to the previous node
    Node *current = head; // Pointer to the current node

    while (current != NULL) { // Continue until the end of the list is reached
        Node *nextNode = current->next; // Save the next node to avoid losing it
        current->next = previous; // Reverse the pointer direction
        previous = current; // Move previous one step forward
        current = nextNode; // Move to the next node
    }

    head = previous; // Global pointer now points to the new first node
}

void printList() {
    Node *current = head; // Start from the first node pointed to by 'head'

    while (current != NULL) {
        cout << current->value << " ";
        current = current->next; // Move to the next node
    }

    cout << endl;
}

void clearList() {
    while (head != NULL) {
        Node *current = head; // Store the current node
        head = head->next;
        delete current; // Delete the stored node from memory
    }
}

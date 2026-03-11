/*
Timurs Maksjuks

Create two programs in C++ that work with a sequence of values in two different ways:
1. implementing it as a singly linked list using dynamic data structures,
2. using the STL::list container.
G8. Write a function that reverses the list. During execution, no additional elements that would duplicate all the information of the existing list may be used.
The operation must be performed by relinking the pointers, not by copying element values.

Program created: 10.03.2026
*/



#include <iostream>
using namespace std;


struct Node { // Structure that describes a list node
    int value;
    Node *next; // Pointer to the next node
};


Node *head = NULL; // Global pointer that initially points to NULL because the list is empty


void add(int value) {

    Node *new_node = new Node(); // Create a new node in dynamic memory
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL) { // If the list is empty, the new node becomes the first one
        head = new_node; // The global pointer points to the new node
        return;
    }

    Node *temp = head; // Start from the first node pointed to by 'head'

    while (temp->next != NULL) // While the next node does not point to NULL
        temp = temp->next; // Move to the next node
    temp->next = new_node; // The last node now points to the new one
}



void reverse_list() {
    Node *prev = NULL; // Pointer to the previous node
    Node *curr = head; // Pointer to the first node pointed to by 'head'

    while (curr != NULL) { // While the end of the list has not been reached
        Node *next = curr->next; // Save the next node so we don't lose it
        curr->next = prev; // Reverse the pointer backwards
        prev = curr; // Move the previous pointer forward
        curr = next; // Move to the next node
    }

    head = prev; // The global pointer now points to the new first node
}


void print_list() {

    Node *temp = head; // Start from the first node pointed to by 'head'
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}


void clear_list() {
    while (head != NULL) {
        Node *temp = head; // Save the current node
        head = head->next;
        delete temp; // The saved node is deleted from memory
    }
}


int main() {

    int answer = 0;
    do {

        clear_list(); // The list is cleared of elements and memory is freed
        int element;
        cout << "Enter list elements on one line: ";

        do {
            cin >> element;
            add(element);
        } while (cin.peek() != '\n');

        cout << "Original list: ";
        print_list();
        reverse_list();

        cout << "Reversed list: ";
        print_list();
        clear_list();

        cout << "Program finished. Do you want to continue? 1 - yes, 0 - no: ";
        cin >> answer;
        cin.ignore();

    } while (answer == 1);

    return 0;
}

struct Node {

    int value;
    Node *next;
};

extern Node *head; // Global pointer to the beginning of the list

void append(int value);
void printList();
void clearList();
void reverseList();

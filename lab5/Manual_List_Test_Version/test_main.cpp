#include <iostream>
#include "reverse_list.h"

using namespace std;

bool test1() {

    clearList();

    append(1);
    append(2);
    append(3);
    append(4);
    append(5);

    try {

        reverseList();

        int expected[5] = {5, 4, 3, 2, 1};

        Node *current = head; // Pointer used for checking list elements

        for (int i = 0; i < 5; i++) {

            if (current == NULL) // Check whether the pointer points to NULL
                return false;

            if (current->value != expected[i])
                return false;

            current = current->next;
        }

        return true;
    }

    catch (...) {

        return false;
    }
}

bool test2() {

    clearList();

    append(1);

    try {

        reverseList();

        return false;
    }

    catch (const char *message) {

        return true;
    }
}

bool test3() {

    clearList();

    try {

        reverseList();

        return false;
    }

    catch (const char *message) {

        return true;
    }
}

bool test4() {

    clearList();

    append(-7);
    append(8);
    append(-9);
    append(10);

    try {

        reverseList();

        int expected[4] = {10, -9, 8, -7};

        Node *current = head; // Pointer used for checking list elements

        for (int i = 0; i < 4; i++) {

            if (current == NULL) // Check whether the pointer points to NULL
                return false;

            if (current->value != expected[i])
                return false;

            current = current->next;
        }

        return true;
    }

    catch (...) {

        return false;
    }
}

int main() {

    cout << "Test 1: " << (test1() ? "OK" : "FAILED") << endl;
    cout << "Test 2: " << (test2() ? "OK" : "FAILED") << endl;
    cout << "Test 3: " << (test3() ? "OK" : "FAILED") << endl;
    cout << "Test 4: " << (test4() ? "OK" : "FAILED") << endl;

    return 0;
}

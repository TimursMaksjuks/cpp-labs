/*
Timurs Maksjuks

G8. Write a function that reverses the list.
During the operation, additional elements that duplicate the entire information of the existing list must not be used.
The operation must be performed by reconnecting links, not by copying element values.

Program created: 09.05.2026
*/

#include <iostream>
#include <sstream> // Provides support for working with 'stringstream'
#include "reverse_list.h" // Includes function declarations from the header file

using namespace std;

int main() {
    int answer = 0;

    do {

        clearList();

        string line;

        cout << "Enter list elements in one line: ";

        // Read the entire input line
        getline(cin, line);

        // Create a stream for processing the entered text
        stringstream ss(line);

        int element;

        // Read numbers from the entered line
        while (ss >> element) {

            append(element);
        }

        cout << "Original list: ";
        printList();

        try {

            reverseList();

            cout << "Reversed list: ";
            printList();

        }

        catch (const char *message) {

            cout << message << endl;

        }

        clearList();

        cout << "Program finished. Continue? 1 - yes, 0 - no: ";
        cin >> answer;

        cin.ignore(); // Clear the input buffer

    } while (answer == 1);

    return 0;
}

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
#include <list>
using namespace std;


template <typename T> // Template declaration to work with different data types
void reversed_list(list<T> &list_ref) { // Using '&' to work with the original list, not a copy

    auto left = list_ref.begin(); // Iterator pointing to the first element of the list
    auto right = list_ref.end(); // Iterator positioned after the last element of the list
    --right; // Subtract 1 so the iterator points to the last element of the list

    for (int i = 0; i < list_ref.size() / 2; i++) { // List length is divided by 2, otherwise the values would be swapped back to their original positions
        swap(*left, *right); // Swaps the values of the left and right iterators
        ++left; // Moves the left iterator one position to the right
        --right; // Moves the right iterator one position to the left
    }
}



int main() {



    int answer = 0;
    do {
    int choice = 0;
    cout << "Choose the list data type:" << endl;
    cout << "1 - int" << endl;
    cout << "2 - char" << endl;
    cout << "3 - double" << endl;
    cin >> choice;
    cin.ignore(); // Clears the '\n' character from the input buffer so the next cin.peek() works correctly
    if (choice == 1) {



            list<int> my_list;
            int element;
            cout << "Enter list elements on one line: ";
            do {
            cin >> element;
            my_list.push_back(element);
    }      while (cin.peek() != '\n'); // Checks the next character in the buffer - if it's not 'ENTER', continues reading elements


    cout << "Original list: ";
        for (auto it = my_list.begin(); it != my_list.end(); ++it)
            cout << *it << " ";
        cout << endl;


        reversed_list(my_list);


        cout << "Reversed list: ";
        for (auto it = my_list.begin(); it != my_list.end(); ++it)
            cout << *it << " ";
        cout << endl;
        my_list.clear();  // Frees the list memory by deleting all elements
    }



    else if (choice == 2) {
            list<char> my_list;
            char element;
            cout << "Enter list elements on one line: ";
            do {
            cin >> element;
            my_list.push_back(element);
    }      while (cin.peek() != '\n');


    cout << "Original list: ";
        for (auto it = my_list.begin(); it != my_list.end(); ++it)
            cout << *it << " ";
        cout << endl;


        reversed_list(my_list);


        cout << "Reversed list: ";
        for (auto it = my_list.begin(); it != my_list.end(); ++it)
            cout << *it << " ";
        cout << endl;
        my_list.clear();
    }


    else if (choice == 3) {
            list<double> my_list;
            double element;
            cout << "Enter list elements on one line: ";
            do {
            cin >> element;
            my_list.push_back(element);
    }      while (cin.peek() != '\n');


    cout << "Original list: ";
        for (auto it = my_list.begin(); it != my_list.end(); ++it)
            cout << *it << " ";
        cout << endl;


        reversed_list(my_list);


        cout << "Reversed list: ";
        for (auto it = my_list.begin(); it != my_list.end(); ++it)
            cout << *it << " ";
        cout << endl;
        my_list.clear();
    }

    else {
        cout << "Enter the correct number!" << endl;
        return 1;
    }


        cout << "Program finished. Do you want to continue? 1 - yes, 0 - no: ";
        cin >> answer;
        cin.ignore();

    } while (answer == 1);


    return 0;
}

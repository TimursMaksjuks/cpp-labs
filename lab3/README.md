`G8 - Linked List Reversal`
Two C++ programs that reverse a sequence of values using two different approaches.

`Implementations`
1. `Singly Linked List` — using dynamic data structures and pointer relinking.
2. `STL::list` — using the standard C++ STL list container.

`How it works`
Both programs allow the user to input list elements, apply the reversal function, and print the result. Memory is properly freed at the end using delete / clear.

`Key Requirement`
The reversal is performed by relinking pointers only — no additional data structures that duplicate the full list content are used, and element values are never copied.

`Usage`
Compile and run either program, enter elements on one line separated by spaces, and press Enter to see the reversed list.
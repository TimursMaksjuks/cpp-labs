# Lab 1 - Hexadecimal Multiplication Table

## Description

This laboratory work implements a hexadecimal multiplication table in C++ without using built-in hexadecimal formatting functions.

The program generates and prints a multiplication table from:

```
1 × 1  to  F × F

```

All decimal values are manually converted into hexadecimal representation using a custom conversion function.

## Task

Without using built-in hexadecimal output functions:
- generate multiplication results,
- convert decimal values into hexadecimal format manually,
- display the complete hexadecimal multiplication table.

## Features

- Manual decimal-to-hexadecimal conversion
- Hexadecimal multiplication table generation
- Nested loop table traversal
- Static two-dimensional array usage
- String manipulation
- User-controlled program loop

## Technologies Used

- C++
- Functions
- Arrays
- Loops
- String operations
- Number system conversion

## File Structure

### `main.cpp`

Contains:
- hexadecimal conversion function,
- multiplication table generation function,
- main program loop.

## Main Functions

### `trans(int num)`

Converts a decimal number into hexadecimal format manually.

Examples:

```text
10  -> A
15  -> F
31  -> 1F
```

### `table(string arr[16][16])`

Generates and prints the hexadecimal multiplication table.

## Example Output

```text
1   2   3   4   5
2   4   6   8   A
3   6   9   C   F
```

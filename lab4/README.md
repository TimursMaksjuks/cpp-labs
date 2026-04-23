# H7 - Binary File Sorting with STL `map`

Two C++ helper programs and one main C++ program for creating, printing, and sorting binary file records using the STL `map` container.

## Programs

1. **create_file.cpp** — creates the binary file `main.bin` with records of fixed length.
2. **print_content.cpp** — reads and prints all records stored in `main.bin`.
3. **main.cpp** — reads records from `main.bin` and creates two new binary files:
   - `key.bin` — records sorted in ascending order by key
   - `name.bin` — records sorted in ascending order by name

## Record Structure

Each binary file record has the following fixed-length structure:

- **key** (`int`)
- **name** (`char[31]`) — maximum 30 characters + null terminator

## How it works

The main program reads all records from `main.bin` and stores them in two separate STL `map` containers:

- `map<int, string>` — for sorting by key
- `map<string, int>` — for sorting by name

Because `map` automatically keeps elements sorted in ascending order by key, the records are then written into two separate binary output files in the required order.

## Key Requirement

The task requires using the STL `map` structure both for reading the data and for ensuring sorting.

It is assumed that all records are unique:

- unique by **key**
- unique by **name**

## Usage

1. Run **create_file.cpp** to generate `main.bin`
2. Run **print_content.cpp** to display the contents of `main.bin`
3. Run **main.cpp** to create:
   - `key.bin`
   - `name.bin`

You can also use **print_content.cpp** to inspect the contents of the generated binary files if needed.
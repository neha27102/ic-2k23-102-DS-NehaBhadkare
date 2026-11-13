
# Linked List Operations in C++

This repository contains C++ implementations of three types of linked lists:

1. Singly Linked List
2. Doubly Linked List
3. Circular Singly Linked List

Each implementation demonstrates common linked list operations using classes, pointers, and dynamic memory allocation.

## Features

The following operations are implemented in each linked list:

- **Insert at Position:** Inserts a new node at a specified position.
- **Delete at Position:** Deletes a node from a specified position.
- **Reverse:** Reverses the linked list.
- **Concatenate:** Joins two linked lists into one.
- **Display:** Displays all the nodes of the linked list.
- **Memory Management:** Uses `new` and `delete` for dynamic memory allocation and deallocation.
- **Error Handling:** Handles invalid positions and empty linked lists.

## Types of Linked Lists

### 1. Singly Linked List

Each node contains:
- `data` – Stores the value.
- `next` – Stores the address of the next node.

The last node points to `NULL`.

### 2. Doubly Linked List

Each node contains:
- `data` – Stores the value.
- `next` – Stores the address of the next node.
- `prev` – Stores the address of the previous node.

It supports both forward and backward traversal.

### 3. Circular Singly Linked List

Each node contains:
- `data` – Stores the value.
- `next` – Stores the address of the next node.

The last node points back to the first node instead of pointing to `NULL`.

## Time Complexity

Let `n` represent the number of nodes.

| Operation | Singly Linked List | Doubly Linked List | Circular Linked List |
|---|---|---|---|
| Insert at Position | O(n) | O(n) | O(n) |
| Delete at Position | O(n) | O(n) | O(n) |
| Reverse | O(n) | O(n) | O(n) |
| Concatenate | O(n) | O(n) | O(n) |
| Display | O(n) | O(n) | O(n) |

## Concepts Practised

- Classes and Objects
- Pointers
- Dynamic Memory Allocation
- Dynamic Memory Deallocation
- Pass by Reference
- Node Creation and Linking
- Linked List Traversal
- Pointer Manipulation
- Insertion and Deletion Operations
- Reversing and Concatenating Linked Lists

## How to Compile and Run

Make sure a C++ compiler such as GCC or MinGW is installed.

### Compile

```bash
g++ filename.cpp -o output
```

### Run on Windows

```bash
output.exe
```

### Run on Linux

```bash
./output
```

Replace `filename.cpp` with the name of the source file you want to compile.

## Important Notes

- Positions are 1-based. Position 1 represents the first node.
- Each program uses dynamically allocated nodes.
- Memory is released using `delete` before program termination.
- In concatenation, the second list is attached to the first list.
- The implementations use `#include<iostream>` without STL containers.

## Author

Neha Bhadkare



# Unit 02 - Sorting and Searching Algorithms

## Overview
This repository contains C++ implementations of fundamental sorting and searching algorithms as part of the Data Structures laboratory coursework.

The objective is to understand how different algorithms work, how they manipulate data, and how their time and space complexities differ.

## 1. Problem Statement

Implement various searching and sorting algorithms using C++ to arrange elements in ascending order and efficiently locate a particular element in an array.

The programs aim to:
- Understand different sorting techniques.
- Implement searching algorithms.
- Analyze time and space complexities.
- Compare the performance of different algorithms.
- Develop problem-solving and logical thinking skills.

## 2. Algorithms Implemented

| S.No. | Algorithm | File Name |
|---|---|---|
| 1 | Binary Search | `program01-BinarySearch.cpp` |
| 2 | Bubble Sort | `Program02-BubbleSort.cpp` |
| 3 | Insertion Sort | `Program03-insertionSort.cpp` |
| 4 | Selection Sort | `SelectionSort.cpp` |
| 5 | Merge Sort | `MergeSort.cpp` |
| 6 | Radix Sort | `RadixSort.cpp` |

## 3. Approach

### 3.1 Binary Search
- Binary Search is used to find an element in a sorted array.
- It compares the target element with the middle element.
- If the target is smaller, the search continues in the left half.
- If the target is larger, the search continues in the right half.
- This process continues until the element is found or the search space becomes empty.

### 3.2 Bubble Sort
- Compares adjacent elements of an array.
- Swaps elements if they are in the wrong order.
- Repeatedly traverses the array until it becomes sorted.
- The largest unsorted element moves to its correct position in every pass.

### 3.3 Insertion Sort
- Divides the array into sorted and unsorted portions.
- Picks an element from the unsorted portion.
- Compares it with elements in the sorted portion.
- Shifts larger elements to the right and inserts the selected element at its correct position.

### 3.4 Selection Sort
- Finds the smallest element from the unsorted portion.
- Swaps it with the first element of the unsorted portion.
- Repeats this process until the entire array is sorted.

### 3.5 Merge Sort
- Uses the Divide and Conquer approach.
- Divides the array into smaller subarrays.
- Recursively sorts the subarrays.
- Merges the sorted subarrays to produce the final sorted array.

### 3.6 Radix Sort
- Sorts elements digit by digit.
- Starts from the least significant digit (LSD).
- Uses Counting Sort as a stable sorting technique for each digit position.
- Continues until all digit positions have been processed.

## 4. Time and Space Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case | Auxiliary Space |
|---|---|---|---|---|
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Bubble Sort | O(n)* | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Radix Sort | O(d(n + b)) | O(d(n + b)) | O(d(n + b)) | O(n + b) |

**Where:**
- n = Number of elements in the array.
- d = Number of digits in the largest element.
- b = Base of the number system (10 for decimal numbers).

*Note: Bubble Sort best-case O(n) assumes an optimized implementation with a swap flag. Radix Sort complexity assumes Counting Sort is used for each digit.*

## 5. Sample Input and Output

### Sample 1: Sorting Algorithms

**Input:**
```text
Enter the number of elements: 5
Enter array elements: 64 25 12 22 11
```

**Output:**
```text
Sorted array:
11 12 22 25 64
```

### Sample 2: Binary Search

**Input:**
```text
Enter the number of elements: 5
Enter sorted array elements: 10 20 30 40 50
Enter element to search: 30
```

**Output:**
```text
Element found at position: 3
```

*Note: Sample I/O is illustrative. Exact prompts and position numbering may vary depending on the individual program implementation.*

## 6. Screenshots

Screenshots of program execution can be added below to demonstrate the output of each algorithm.

Create a folder named `screenshots` inside the `Unit02-Sorting` directory.

Suggested screenshot organization:

| Algorithm | Screenshot |
|---|---|
| Binary Search | `screenshots/binary-search.png` |
| Bubble Sort | `screenshots/bubble-sort.png` |
| Insertion Sort | `screenshots/insertion-sort.png` |
| Selection Sort | `screenshots/selection-sort.png` |
| Merge Sort | `screenshots/merge-sort.png` |
| Radix Sort | `screenshots/radix-sort.png` |

### Binary Search
<img width="1366" height="768" alt="Screenshot (10)" src="https://github.com/user-attachments/assets/6023497d-e091-4858-8ab7-c1fa2ea7ef6e" />


### Bubble Sort
<img width="1366" height="768" alt="Screenshot (11)" src="https://github.com/user-attachments/assets/2426aaab-4abc-44e7-a20e-bb1ac535d131" />


### Insertion Sort
<img width="1366" height="768" alt="Screenshot (12)" src="https://github.com/user-attachments/assets/3407d8c8-7f9f-4285-b14d-38f7381d87b9" />


### Selection Sort
<img width="1366" height="768" alt="Screenshot (13)" src="https://github.com/user-attachments/assets/8291dcb7-42d4-4426-9fb6-e7834ab737d6" />


### Merge Sort
<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/efdb36e7-366a-4236-a281-4df08bcb290e" />


### Radix Sort
<img width="1366" height="768" alt="Screenshot (15)" src="https://github.com/user-attachments/assets/fc487fdf-6b82-4d86-9981-6329a4427c29" />


## 7. Learning Outcomes

Through the implementation of these algorithms, I learned:

1. Understanding the working principles of searching and sorting algorithms.
2. Implementing different algorithms using C++.
3. Understanding the Divide and Conquer technique through Merge Sort.
4. Learning how Binary Search reduces the search space.
5. Understanding element comparison, swapping, and shifting operations.
6. Analyzing best, average, and worst-case time complexities.
7. Understanding auxiliary space requirements of different algorithms.
8. Developing logical thinking and problem-solving skills.

## 8. Technologies Used

- **Programming Language:** C++
- **IDE:** Visual Studio Code
- **Compiler:** GCC (G++)
- **Version Control:** Git and GitHub

## 9. Repository

GitHub Repository:  
[Data Structures - Neha Bhadkare](https://github.com/neha27102/ic-2k23-102-DS-NehaBhadkare)

---

**Author:** Neha Bhadkare  
**Subject:** Data Structures  
**Unit:** Unit 02 - Sorting and Searching Algorithms


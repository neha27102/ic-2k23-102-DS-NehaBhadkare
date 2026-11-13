#include <iostream>
using namespace std;

class Stack {
    int arr[100];   // Array to hold stack elements
    int tos;        // Index of the top element in the stack
    const int maxSize = 100; // Maximum size of the stack

public:
    Stack(){ tos = -1; }  // Constructor initializes top to -1

    void push(int element);
    void pop();
    void peek();
    bool isEmpty();
    bool isFull();
    void display();
};

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return tos == -1; // If top is -1, the stack is empty
}

// Function to check if the stack is full
bool Stack::isFull() {
    return tos == maxSize - 1; // If top is at maxSize - 1, the stack is full
}

// Function to add an element to the stack
void Stack::push(int element) {
    if (isFull()) {
        cout << "Stack overflow! Cannot push " << element << endl;
        return;
    }
    arr[++tos] = element; // Increment top and add element
    cout << element << " pushed onto the stack." << endl;
}

// Function to remove the top element from the stack
void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Cannot pop from an empty stack." << endl;
        return;
    }
    cout << arr[tos--] << " popped from the stack." << endl; // Return the top element and decrement top
}

// Function to view the top element of the stack
void Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty! No top element." << endl;
        return;
    }
    cout << "Top element is: " << arr[tos] << endl; // Display the top element
}

// Function to display all elements in the stack
void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements are: ";
    for (int i = tos; i >= 0; i--) {
        cout << arr[i] << " "; // Display stack elements from top to bottom
    }
    cout << endl;
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Push Element" << endl;
    cout << "2. Pop Element" << endl;
    cout << "3. Peek Element" << endl;
    cout << "4. Display Stack" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    Stack stack;
    int choice, element;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to push: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

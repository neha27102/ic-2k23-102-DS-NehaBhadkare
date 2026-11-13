
#include<iostream>
using namespace std;

#define SIZE 5

class Stack {
    int arr[SIZE];
    int tos;

public:
    Stack() {
        tos = -1;
    }

    // Inserts an element at the top of the stack
    void push(int d) {

        if(tos == SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        tos++;
        arr[tos] = d;

        cout << d << " pushed into stack." << endl;
    }

    // Removes the top element from the stack
    void pop() {

        if(tos == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << "Deleted element: " << arr[tos] << endl;

        tos--;
    }

    // Displays the top element of the stack
    void peek() {

        if(tos == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Top element: " << arr[tos] << endl;
    }

    // Displays all elements of the stack
    void display() {

        if(tos == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements: ";

        for(int i = tos; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Checks whether the stack is empty
    bool isEmpty() {
        return tos == -1;
    }

    // Checks whether the stack is full
    bool isFull() {
        return tos == SIZE - 1;
    }
};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    s.peek();

    s.push(60);

    s.pop();

    s.display();

    cout << "Is stack empty? " << s.isEmpty() << endl;
    cout << "Is stack full? " << s.isFull() << endl;

    return 0;
}


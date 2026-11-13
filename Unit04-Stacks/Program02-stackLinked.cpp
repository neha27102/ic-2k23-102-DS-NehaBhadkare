
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* tos;

public:
    Stack() {
        tos = NULL;
    }

    // Inserts a new node at the top of the stack
    void push(int d) {

        Node* temp = new Node(d);

        temp->next = tos;
        tos = temp;

        cout << d << " pushed into stack." << endl;
    }

    // Removes the top element from the stack
    void pop() {

        if(tos == NULL) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        Node* temp = tos;

        cout << "Deleted element: " << tos->data << endl;

        tos = tos->next;

        delete temp;
    }

    // Displays the top element of the stack
    void peek() {

        if(tos == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Top element: " << tos->data << endl;
    }

    // Displays all elements of the stack
    void display() {

        if(tos == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* curr = tos;

        cout << "Stack elements: ";

        while(curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    // Deletes all remaining nodes
    void clear() {

        while(tos != NULL) {
            Node* temp = tos;
            tos = tos->next;
            delete temp;
        }
    }

    ~Stack() {
        clear();
    }
};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.peek();

    s.pop();

    s.display();

    s.pop();

    s.display();

    return 0;
}

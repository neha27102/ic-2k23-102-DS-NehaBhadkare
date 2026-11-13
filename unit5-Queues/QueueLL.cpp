
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:

    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Inserts a new node at the rear of the queue
    void enqueue(int d) {

        Node* temp = new Node(d);

        if(front == NULL) {
            front = temp;
            rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }

        cout << d << " inserted successfully" << endl;
    }

    // Removes the front node from the queue
    void dequeue() {

        if(front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;

        cout << "Deleted Element: " << front->data << endl;

        front = front->next;

        if(front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Displays the front element of the queue
    void peek() {

        if(front == NULL) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Front Element: " << front->data << endl;
    }

    // Traverses the linked list and displays all queue elements
    void display() {

        if(front == NULL) {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Queue Elements: ";

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Releases all dynamically allocated nodes
    ~Queue() {

        while(front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }
};

int main() {

    Queue q;
    int choice, d;

    do {
        cout << "\n----- DYNAMIC QUEUE MENU -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter element: ";
                cin >> d;
                q.enqueue(d);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }

    } while(choice != 5);

    return 0;
}

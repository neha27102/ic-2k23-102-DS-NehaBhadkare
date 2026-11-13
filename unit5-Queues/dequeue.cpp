
#include<iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
    int size;

public:

    Queue() {
        front = -1;
        rear = -1;
        size = 100;
    }

    // Inserts an element at the rear of the queue
    void enqueue(int d) {

        if(rear == size - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if(front == -1) {
            front = 0;
        }

        arr[++rear] = d;

        cout << d << " inserted successfully" << endl;
    }

    // Removes an element from the front of the queue
    void dequeue() {

        if(front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted Element: " << arr[front] << endl;

        front++;

        if(front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Displays the front element of the queue
    void peek() {

        if(front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Front Element: " << arr[front] << endl;
    }

    // Displays all elements present in the queue
    void display() {

        if(front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue Elements: ";

        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    Queue q;
    int choice, d;

    do {
        cout << "\n----- QUEUE MENU -----" << endl;
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

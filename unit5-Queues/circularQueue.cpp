
#include<iostream>
using namespace std;

class CircularQueue {
    int arr[100];
    int front, rear;
    int size;

public:

    CircularQueue() {
        front = -1;
        rear = -1;
        size = 100;
    }

    // Inserts an element at the rear using circular movement
    void enqueue(int d) {

        if((rear + 1) % size == front) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if(front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = d;

        cout << d << " inserted successfully" << endl;
    }

    // Removes an element from the front of the queue
    void dequeue() {

        if(front == -1) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted Element: " << arr[front] << endl;

        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
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

    // Displays all elements by following circular indexing
    void display() {

        if(front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue Elements: ";

        int i = front;

        while(true) {
            cout << arr[i] << " ";

            if(i == rear) {
                break;
            }

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {

    CircularQueue q;
    int choice, d;

    do {
        cout << "\n----- CIRCULAR QUEUE MENU -----" << endl;
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

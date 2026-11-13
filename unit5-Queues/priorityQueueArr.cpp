
#include<iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int priority[100];
    int rear;
    int size;

public:

    PriorityQueue() {
        rear = -1;
        size = 100;
    }

    // Inserts an element along with its priority
    void enqueue(int d, int p) {

        if(rear == size - 1) {
            cout << "Priority Queue Overflow" << endl;
            return;
        }

        int i = rear;

        // Shifts lower-priority elements to maintain priority order
        while(i >= 0 && priority[i] > p) {
            arr[i + 1] = arr[i];
            priority[i + 1] = priority[i];
            i--;
        }

        arr[i + 1] = d;
        priority[i + 1] = p;

        rear++;

        cout << d << " inserted with priority " << p << endl;
    }

    // Deletes the element having the highest priority
    void dequeue() {

        if(rear == -1) {
            cout << "Priority Queue Underflow" << endl;
            return;
        }

        cout << "Deleted Element: " << arr[0] << endl;

        for(int i = 0; i < rear; i++) {
            arr[i] = arr[i + 1];
            priority[i] = priority[i + 1];
        }

        rear--;
    }

    // Displays the highest-priority element
    void peek() {

        if(rear == -1) {
            cout << "Priority Queue is Empty" << endl;
            return;
        }

        cout << "Highest Priority Element: " << arr[0] << endl;
        cout << "Priority: " << priority[0] << endl;
    }

    // Displays all elements with their priorities
    void display() {

        if(rear == -1) {
            cout << "Priority Queue is Empty" << endl;
            return;
        }

        cout << "\nElement\tPriority" << endl;

        for(int i = 0; i <= rear; i++) {
            cout << arr[i] << "\t" << priority[i] << endl;
        }
    }
};

int main() {

    PriorityQueue pq;
    int choice, d, p;

    do {
        cout << "\n----- PRIORITY QUEUE MENU -----" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter element: ";
                cin >> d;

                cout << "Enter priority (1 = Highest): ";
                cin >> p;

                pq.enqueue(d, p);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.peek();
                break;

            case 4:
                pq.display();
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

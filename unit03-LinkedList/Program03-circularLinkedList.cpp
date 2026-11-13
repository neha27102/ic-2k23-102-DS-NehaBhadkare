
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

// Inserts a new node at the specified position
void insertAtPos(Node* &head, int d, int pos) {

    if(pos < 1) {
        cout << "Error: Invalid position!" << endl;
        return;
    }

    Node* temp = new Node(d);

    // Insert into an empty list
    if(head == NULL) {

        if(pos != 1) {
            cout << "Error: Position does not exist!" << endl;
            delete temp;
            return;
        }

        temp->next = temp;
        head = temp;

        cout << "Node inserted successfully." << endl;
        return;
    }

    // Insert at the beginning
    if(pos == 1) {

        Node* curr = head;

        // Reach the last node
        while(curr->next != head) {
            curr = curr->next;
        }

        temp->next = head;
        curr->next = temp;
        head = temp;

        cout << "Node inserted successfully." << endl;
        return;
    }

    Node* curr = head;

    // Reach the node just before the required position
    for(int i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next;
    }

    if(curr->next == head && pos > 1) {
        if(pos != 2 && curr == head) {
            cout << "Error: Position does not exist!" << endl;
            delete temp;
            return;
        }
    }

    // Check whether the required position exists
    if(pos > 1) {
        int count = 1;
        Node* check = head;

        while(check->next != head) {
            count++;
            check = check->next;
        }

        if(pos > count + 1) {
            cout << "Error: Position does not exist!" << endl;
            delete temp;
            return;
        }
    }

    temp->next = curr->next;
    curr->next = temp;

    cout << "Node inserted successfully." << endl;
}

// Deletes a node from the specified position
void deleteAtPos(Node* &head, int pos) {

    if(head == NULL) {
        cout << "Error: Linked list is empty!" << endl;
        return;
    }

    if(pos < 1) {
        cout << "Error: Invalid position!" << endl;
        return;
    }

    Node* curr = head;

    // Delete the first node
    if(pos == 1) {

        // Only one node exists
        if(head->next == head) {
            delete head;
            head = NULL;
            cout << "Node deleted successfully." << endl;
            return;
        }

        Node* last = head;

        // Reach the last node
        while(last->next != head) {
            last = last->next;
        }

        Node* temp = head;
        head = head->next;
        last->next = head;

        delete temp;

        cout << "Node deleted successfully." << endl;
        return;
    }

    // Reach the node just before the target node
    for(int i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next;
    }

    if(curr->next == head) {
        cout << "Error: Position does not exist!" << endl;
        return;
    }

    Node* temp = curr->next;
    curr->next = temp->next;

    delete temp;

    cout << "Node deleted successfully." << endl;
}

// Reverses the circular linked list
void reverseList(Node* &head) {

    if(head == NULL) {
        cout << "Error: Linked list is empty!" << endl;
        return;
    }

    if(head->next == head) {
        cout << "Only one node exists. No reversal needed." << endl;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    Node* last = head;

    // Find the last node
    while(last->next != head) {
        last = last->next;
    }

    // Reverse the links
    do {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    } while(curr != head);

    // Connect the old first node to the new first node
    head->next = prev;
    head = prev;

    cout << "Linked list reversed successfully." << endl;
}

// Joins the second circular list to the first circular list
void concatenate(Node* &head1, Node* &head2) {

    if(head2 == NULL) {
        cout << "Error: Second linked list is empty!" << endl;
        return;
    }

    if(head1 == NULL) {
        head1 = head2;
        head2 = NULL;

        cout << "Lists concatenated successfully." << endl;
        return;
    }

    Node* last1 = head1;
    Node* last2 = head2;

    // Find the last node of the first list
    while(last1->next != head1) {
        last1 = last1->next;
    }

    // Find the last node of the second list
    while(last2->next != head2) {
        last2 = last2->next;
    }

    // Join both circular lists
    last1->next = head2;
    last2->next = head1;

    head2 = NULL;

    cout << "Lists concatenated successfully." << endl;
}

// Displays all nodes of the circular linked list
void display(Node* head) {

    if(head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    Node* curr = head;

    do {
        cout << curr->data << " -> ";
        curr = curr->next;
    } while(curr != head);

    cout << "(Back to Head)" << endl;
}

// Releases all dynamically allocated nodes
void freeList(Node* &head) {

    if(head == NULL) {
        return;
    }

    Node* curr = head->next;

    while(curr != head) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    delete head;
    head = NULL;
}

int main() {

    Node* head = NULL;
    Node* head2 = NULL;

    // Creating the first circular linked list
    insertAtPos(head, 10, 1);
    insertAtPos(head, 20, 2);
    insertAtPos(head, 30, 3);

    cout << "\nFirst Linked List: ";
    display(head);

    // Inserting a node at position 2
    insertAtPos(head, 15, 2);

    cout << "After Insertion: ";
    display(head);

    // Deleting the node at position 2
    deleteAtPos(head, 2);

    cout << "After Deletion: ";
    display(head);

    // Reversing the first circular linked list
    reverseList(head);

    cout << "After Reversal: ";
    display(head);

    // Creating the second circular linked list
    insertAtPos(head2, 40, 1);
    insertAtPos(head2, 50, 2);

    cout << "\nSecond Linked List: ";
    display(head2);

    // Concatenating both circular linked lists
    concatenate(head, head2);

    cout << "After Concatenation: ";
    display(head);

    // Releasing allocated memory
    freeList(head);
    freeList(head2);

    return 0;
}

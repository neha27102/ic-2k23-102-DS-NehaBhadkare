
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

    // Insert at the beginning
    if(pos == 1) {
        temp->next = head;
        head = temp;
        cout << "Node inserted successfully." << endl;
        return;
    }

    Node* curr = head;

    // Reach the node just before the required position
    for(int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    // Check whether the position exists
    if(curr == NULL) {
        cout << "Error: Position does not exist!" << endl;
        delete temp;
        return;
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

    Node* temp = head;

    // Delete the first node
    if(pos == 1) {
        head = head->next;
        delete temp;
        cout << "Node deleted successfully." << endl;
        return;
    }

    Node* curr = head;

    // Reach the node just before the node to be deleted
    for(int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    // Check whether the target node exists
    if(curr == NULL || curr->next == NULL) {
        cout << "Error: Position does not exist!" << endl;
        return;
    }

    temp = curr->next;
    curr->next = temp->next;

    delete temp;

    cout << "Node deleted successfully." << endl;
}

// Reverses the linked list using three pointers
void reverseList(Node* &head) {

    if(head == NULL) {
        cout << "Error: Linked list is empty!" << endl;
        return;
    }

    if(head->next == NULL) {
        cout << "Only one node exists. No reversal needed." << endl;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {

        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    head = prev;

    cout << "Linked list reversed successfully." << endl;
}

// Joins the second linked list to the end of the first linked list
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

    Node* curr = head1;

    // Reach the last node of the first linked list
    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = head2;

    // Clear the second head to avoid two heads owning the same list
    head2 = NULL;

    cout << "Lists concatenated successfully." << endl;
}

// Displays all nodes of the linked list
void display(Node* head) {

    if(head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    Node* curr = head;

    while(curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }

    cout << "NULL" << endl;
}

// Releases all dynamically allocated nodes
void freeList(Node* &head) {

    Node* curr = head;

    while(curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    head = NULL;
}

int main() {

    Node* head = NULL;
    Node* head2 = NULL;

    // Creating the first linked list
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

    // Reversing the first linked list
    reverseList(head);

    cout << "After Reversal: ";
    display(head);

    // Creating the second linked list
    insertAtPos(head2, 40, 1);
    insertAtPos(head2, 50, 2);

    cout << "\nSecond Linked List: ";
    display(head2);

    // Concatenating both linked lists
    concatenate(head, head2);

    cout << "After Concatenation: ";
    display(head);

    // Releasing allocated memory
    freeList(head);
    freeList(head2);

    return 0;
}

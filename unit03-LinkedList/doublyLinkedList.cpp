
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
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

        if(head != NULL) {
            head->prev = temp;
        }

        head = temp;

        cout << "Node inserted successfully." << endl;
        return;
    }

    Node* curr = head;

    // Reach the node just before the required position
    for(int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if(curr == NULL) {
        cout << "Error: Position does not exist!" << endl;
        delete temp;
        return;
    }

    temp->next = curr->next;
    temp->prev = curr;

    if(curr->next != NULL) {
        curr->next->prev = temp;
    }

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

    // Reach the node to be deleted
    for(int i = 1; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }

    if(curr == NULL) {
        cout << "Error: Position does not exist!" << endl;
        return;
    }

    // Update previous node's next pointer
    if(curr->prev != NULL) {
        curr->prev->next = curr->next;
    }
    else {
        head = curr->next;
    }

    // Update next node's previous pointer
    if(curr->next != NULL) {
        curr->next->prev = curr->prev;
    }

    delete curr;

    cout << "Node deleted successfully." << endl;
}

// Reverses the doubly linked list
void reverseList(Node* &head) {

    if(head == NULL) {
        cout << "Error: Linked list is empty!" << endl;
        return;
    }

    if(head->next == NULL) {
        cout << "Only one node exists. No reversal needed." << endl;
        return;
    }

    Node* curr = head;
    Node* temp = NULL;

    while(curr != NULL) {

        // Swap next and prev pointers
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to the next node in the original list
        curr = curr->prev;
    }

    // Update head to the new first node
    head = temp->prev;

    cout << "Linked list reversed successfully." << endl;
}

// Joins the second list at the end of the first list
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

    // Reach the last node of the first list
    while(curr->next != NULL) {
        curr = curr->next;
    }

    // Connect both lists in forward and backward directions
    curr->next = head2;
    head2->prev = curr;

    // Clear the second head pointer
    head2 = NULL;

    cout << "Lists concatenated successfully." << endl;
}

// Displays the list in forward direction
void displayForward(Node* head) {

    if(head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    Node* curr = head;

    while(curr != NULL) {
        cout << curr->data << " <-> ";
        curr = curr->next;
    }

    cout << "NULL" << endl;
}

// Displays the list in backward direction
void displayBackward(Node* head) {

    if(head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    Node* curr = head;

    // Reach the last node
    while(curr->next != NULL) {
        curr = curr->next;
    }

    // Traverse backwards using prev
    while(curr != NULL) {
        cout << curr->data << " <-> ";
        curr = curr->prev;
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

    // Creating the first doubly linked list
    insertAtPos(head, 10, 1);
    insertAtPos(head, 20, 2);
    insertAtPos(head, 30, 3);

    cout << "\nFirst Linked List: ";
    displayForward(head);

    // Inserting a node at position 2
    insertAtPos(head, 15, 2);

    cout << "After Insertion: ";
    displayForward(head);

    // Deleting the node at position 2
    deleteAtPos(head, 2);

    cout << "After Deletion: ";
    displayForward(head);

    // Reversing the first linked list
    reverseList(head);

    cout << "After Reversal: ";
    displayForward(head);

    // Displaying the list backwards
    cout << "Backward Display: ";
    displayBackward(head);

    // Creating the second doubly linked list
    insertAtPos(head2, 40, 1);
    insertAtPos(head2, 50, 2);

    cout << "\nSecond Linked List: ";
    displayForward(head2);

    // Concatenating both lists
    concatenate(head, head2);

    cout << "After Concatenation: ";
    displayForward(head);

    // Releasing allocated memory
    freeList(head);
    freeList(head2);

    return 0;
}

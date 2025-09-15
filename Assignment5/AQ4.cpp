#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newnode = new Node();
        newnode->data = value;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;   // Save next
            curr->next = prev;   // Reverse link
            prev = curr;         // Move prev
            curr = next;         // Move curr
        }
        head = prev;  // New head
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;  
    }
};

int main() {
    SinglyLinkedList sll;

    // Build the list: 1->2->3->4->NULL
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.insertAtEnd(4);

    cout << "Original Linked List: ";
    sll.display();

    sll.reverse();

    cout << "Reversed Linked List: ";
    sll.display();

    return 0;
}


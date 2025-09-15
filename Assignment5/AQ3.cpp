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

    // Find middle element
    void findMiddle() {
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element: " << slow->data << endl;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList sll;

    // Build the list: 1->2->3->4->5
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.insertAtEnd(4);
    sll.insertAtEnd(5);

    cout << "Linked List: ";
    sll.display();

    sll.findMiddle();

    return 0;
}

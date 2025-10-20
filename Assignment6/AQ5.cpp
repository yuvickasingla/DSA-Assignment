#include <iostream>
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

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    Node* getHead() { return head; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Make list circular manually for testing
    void makeCircular() {
        if (head == NULL)
            return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head; // circular link
    }

    bool isCircular() {
        if (head == NULL)
            return false;

        Node* temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        int count = 0;
        while (temp != NULL && count < 10) { // limit to prevent infinite loop
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(7);
    list.insert(5);

    list.makeCircular(); // make circular for test
    list.display();

    if (list.isCircular())
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}

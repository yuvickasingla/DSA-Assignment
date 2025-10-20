#include <iostream>
using namespace std;

// DOUBLY LINKED LIST
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insert(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int size() {
        int count = 0;
        DNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// CIRCULAR LINKED LIST
class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    CNode* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insert(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) {
            head = newNode;
            head->next = head; // circular link
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int size() {
        if (head == NULL)
            return 0;
        int count = 0;
        CNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void display() {
        if (head == NULL) {
            cout << "Circular Linked List is empty!" << endl;
            return;
        }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// MAIN FUNCTION
int main() {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);
    dll.display();
    cout << "Size of Doubly Linked List: " << dll.size() << endl << endl;

    CircularLinkedList cll;
    cll.insert(5);
    cll.insert(15);
    cll.insert(25);
    cll.insert(35);
    cll.display();
    cout << "Size of Circular Linked List: " << cll.size() << endl;

    return 0;
}



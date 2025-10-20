#include <iostream>
using namespace std;

// Node Definition
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List
class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << data << " inserted at beginning.\n";
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            cout << data << " inserted as first node.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << data << " inserted at end.\n";
    }

    void insertAfter(int key, int data) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << key << " not found!\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << data << " inserted after " << key << ".\n";
    }

    void insertBefore(int key, int data) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << key << " not found!\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
        cout << data << " inserted before " << key << ".\n";
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << key << " deleted.\n";
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << key << " not found in list.\n";
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Circular Linked List
class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() { head = NULL; }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << data << " inserted at beginning.\n";
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << data << " inserted at end.\n";
    }

    void insertAfter(int key, int data) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(data);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << data << " inserted after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << key << " not found!\n";
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node *curr = head, *prev = NULL;
        do {
            if (curr->data == key) {
                if (prev == NULL) {
                    Node* temp = head;
                    while (temp->next != head)
                        temp = temp->next;
                    if (head->next == head) {
                        head = NULL;
                    } else {
                        temp->next = head->next;
                        head = head->next;
                    }
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Node " << key << " deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node " << key << " not found!\n";
    }

    void search(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << key << " not found in list.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "Circular Linked List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

// Menu
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int mainChoice, subChoice, data, key;

    while (true) {
        cout << "\n==== LINKED LIST MENU ====\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            while (true) {
                cout << "\n--- Doubly Linked List Operations ---\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert Before a Node\n";
                cout << "4. Insert After a Node\n";
                cout << "5. Delete a Node\n";
                cout << "6. Search a Node\n";
                cout << "7. Display\n";
                cout << "8. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Enter data: "; cin >> data;
                    dll.insertAtBeginning(data);
                } else if (subChoice == 2) {
                    cout << "Enter data: "; cin >> data;
                    dll.insertAtEnd(data);
                } else if (subChoice == 3) {
                    cout << "Enter key and data: "; cin >> key >> data;
                    dll.insertBefore(key, data);
                } else if (subChoice == 4) {
                    cout << "Enter key and data: "; cin >> key >> data;
                    dll.insertAfter(key, data);
                } else if (subChoice == 5) {
                    cout << "Enter key to delete: "; cin >> key;
                    dll.deleteNode(key);
                } else if (subChoice == 6) {
                    cout << "Enter key to search: "; cin >> key;
                    dll.search(key);
                } else if (subChoice == 7) {
                    dll.display();
                } else if (subChoice == 8) break;
                else cout << "Invalid choice!\n";
            }
        }

        else if (mainChoice == 2) {
            while (true) {
                cout << "\n--- Circular Linked List Operations ---\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert After a Node\n";
                cout << "4. Delete a Node\n";
                cout << "5. Search a Node\n";
                cout << "6. Display\n";
                cout << "7. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Enter data: "; cin >> data;
                    cll.insertAtBeginning(data);
                } else if (subChoice == 2) {
                    cout << "Enter data: "; cin >> data;
                    cll.insertAtEnd(data);
                } else if (subChoice == 3) {
                    cout << "Enter key and data: "; cin >> key >> data;
                    cll.insertAfter(key, data);
                } else if (subChoice == 4) {
                    cout << "Enter key to delete: "; cin >> key;
                    cll.deleteNode(key);
                } else if (subChoice == 5) {
                    cout << "Enter key to search: "; cin >> key;
                    cll.search(key);
                } else if (subChoice == 6) {
                    cll.display();
                } else if (subChoice == 7) break;
                else cout << "Invalid choice!\n";
            }
        }

        else if (mainChoice == 3) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}


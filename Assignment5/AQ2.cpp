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

    int countAndDeleteKey(int key) {
        int count = 0;

        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }

        return count;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is Empty";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(3);
    sll.insertAtEnd(1);

    int key = 1;
    int count = sll.countAndDeleteKey(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    sll.display();
    cout << endl;

    return 0;
}

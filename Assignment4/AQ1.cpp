//Name: Yuvicka
//Roll No: 1024240016

#include <iostream>
using namespace std;
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == MAX - 1);
}
void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is Full! Cannot enqueue.\n";
        return;
    }
    if (isEmpty()) { 
        front = 0;
    }
    rear++;
    queue[rear] = item;
    cout << "Enqueued: " << item << endl;
}
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty! Cannot dequeue.\n";
        return;
    }
    cout << "Dequeued: " << queue[front] << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Queue is Empty! Nothing to peek.\n";
    } else {
        cout << "Front element is: " << queue[front] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Queue contents: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}
int main() {
    int choice, item;
    while (true) {
        cout << "\n--- Linear Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> item;
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << (isEmpty() ? "Queue is Empty\n" : "Queue is NOT Empty\n");
                break;
            case 6:
                cout << (isFull() ? "Queue is Full\n" : "Queue is NOT Full\n");
                break;
            case 7:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

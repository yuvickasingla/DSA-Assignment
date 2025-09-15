//Name:Yuvicka
//Roll No:1024240016
#include <iostream>
using namespace std;

#define MAX 5   
int q[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1);
}
bool isFull() {
    return ((rear + 1) % MAX == front);
}
void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is Full! Cannot enqueue.\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
 q[rear] = item;
    cout << "Enqueued: " << item << endl;
}
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty! Cannot dequeue.\n";
        return;
    }
    cout << "Dequeued: " << q[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Queue is Empty! Nothing to peek.\n";
    } else {
        cout << "Front element is: " << q[front] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Queue contents: ";
    int i = front;
    while (true) {
        cout << q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}
int main() {
    int choice, item;
    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
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

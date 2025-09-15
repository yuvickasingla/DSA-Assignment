//Name:Yuvicka
//Roll No:1024240016
#include <iostream>
using namespace std;
#define MAX 100  
int arr[MAX];     
int front = 0, rear = -1;  
int n;           
void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow!\n";
        return;
    }
    arr[++rear] = x;
}
void display() {
    if (rear < front) {
        cout << "Queue is Empty!\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void interleave() {
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements!\n";
        return;
    }
    int half = n / 2;
    int result[MAX];
    int idx = 0;
    for (int i = 0; i < half; i++) {
        result[idx++] = arr[i];        
        result[idx++] = arr[i + half]; 
    }
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
    rear = n - 1; 
}
int main() {
    cout << "Enter number of elements (even): ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        enqueue(x);
    }
    cout << "Original Queue: ";
    display();
    interleave();
    cout << "Interleaved Queue: ";
    display();
    return 0;
}



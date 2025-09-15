//Name:Yuvicka
//Roll No:1024240016
#include <iostream>
using namespace std;
#define MAX 1000
char q[MAX];
int front = 0, rear = -1;
void enqueue(char ch) {
    if (rear == MAX - 1) return; 
    q[++rear] = ch;
}
void dequeue() {
    if (front <= rear) front++;
}
char getFront() {
    if (front > rear) return '\0';
    return q[front];
}
bool isEmpty() {
    return (front > rear);
}
void resetQueue() {
    front = 0;
    rear = -1;
}
void firstNonRepeating(string str) {
    int freq[256] = {0};  
    resetQueue();

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        freq[ch]++;
        enqueue(ch);

        while (!isEmpty() && freq[getFront()] > 1) {
            dequeue();
        }

        if (isEmpty())
            cout << "-1 ";
        else
            cout << getFront() << " ";
    }
    cout << endl;
}
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "First non-repeating characters: ";
    firstNonRepeating(s);
    return 0;
}

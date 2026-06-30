#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow" << endl;
    } else {
        if (front == -1) front = 0; // first insertion
        rear = rear + 1;            // increment rear explicitly
        queue[rear] = item;
        cout << "Inserted: " << item << endl;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
    } else {
        cout << "Deleted: " << queue[front] << endl;
        front = front + 1; // move front forward
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}

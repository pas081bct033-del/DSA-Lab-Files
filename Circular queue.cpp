#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    // Overflow condition
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        cout << "Queue Overflow" << endl;
    } else {
        if (front == -1) {
            front = rear = 0; // first insertion
        } else {
            rear = rear + 1;
            if (rear == SIZE) rear = 0; // manual reset
        }
        queue[rear] = item;
        cout << "Inserted: " << item << endl;
    }
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
    } else {
        cout << "Deleted: " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = front + 1;
            if (front == SIZE) front = 0; // wrap around
        }
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = i + 1;
            if (i == SIZE) i = 0; // manual reset
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
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    return 0;
}

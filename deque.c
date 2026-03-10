#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (front == 0 && rear == MAX - 1);
}

void push_front(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        printf("No space at front\n");
    }
    else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int getFront() {
    if (isEmpty())
        return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty())
        return -1;
    return deque[rear];
}

int size() {
    if (isEmpty())
        return 0;
    return rear - front + 1;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);

    display();

    pop_front();
    pop_back();

    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    return 0;
}
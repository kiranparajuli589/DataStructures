#include <iostream>

#define SIZE 10

using namespace std;

/**
 * A linear Queue implementation using an array
*/
class Queue {
    private:
        int front;
        int rear;
        int items[SIZE];
    public:
        // constructor
        Queue() {
            front = -1;
            rear = -1;
        }

        // operation declarations
        void enqueue(int);
        int dequeue();
        int size();
        int head();
        int tail();
        bool isEmpty();
        bool isFull();
        void display();
};

/**
 * Determines if the queue is empty
 * 
 * @returns true if queue is empty
 * @returns false if queue is not empty
*/
bool Queue::isEmpty() {
    return (front == -1 && rear == -1);
}

/**
 * Determines if the queue is full
 * 
 * @returns true if queue is full
 * @returns false if queue is not full
*/
bool Queue::isFull() {
    return (rear == (SIZE - 1));
}

/**
 * Returns the size of the queue
*/
int Queue::size() {
    if (Queue::isEmpty()) {
        return 0;
    } else {
        return rear - front + 1;
    }
}

/**
 * Adds an element to the head of the queue
 * 
 * @param itemToAdd the item to add to the queue
 * 
 * @returns void
*/
void Queue::enqueue(int itemToAdd) {
    if (Queue::isFull()) {
        cout << "Queue is already full" << endl;
    } else {
        if (Queue::isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        items[rear] = itemToAdd;
    }
}

/**
 * Removes an element from the front of the queue
*/
int Queue::dequeue() {
    if (Queue::isEmpty()) {
        cout << "Queue is already empty" << endl;
        return -1;
    } else {
        int itemToPop = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return itemToPop;
    }
}

/**
 * Returns the head of the queue
*/
int Queue::head() {
    if (Queue::isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        return items[front];
    }
}

/**
 * Returns the tail of the queue
*/
int Queue::tail() {
    if (Queue::isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        return items[rear];
    }
}

/**
 * Displays the queue
*/
void Queue::display() {
    if(Queue::isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Size of the queue is " << Queue::size() << endl;
        cout << "Head of the queue is " << Queue::head() << endl;
        cout << "Tail of the queue is " << Queue::tail() << endl;

        cout << "Queue: " << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << "--";
        }
        cout << endl;


        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << "--";
        }
        cout << endl;
        cout << "++++" << endl;
    }
}

int main() {
    Queue queue;

    for (int i = 0; i < 10; i++) {
        queue.enqueue(i);
    }

    queue.display();

    for (int i = 0; i < 5; i++) {
        queue.dequeue();
    }

    queue.display();

    return 0;
}
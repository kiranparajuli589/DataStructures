#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int value) {
            data = value;
            next = NULL;
        }
};

/**
 * A circular Queue implementation using a linked list
*/
class Queue {
    private:
        Node *front, *rear;
        int count, size;
    public:
        Queue(int inputSize) {
            front = rear = NULL;
            count = 0;
            size = inputSize;
        }
        // operation prototypes
        void enqueue(int);
        void dequeue();
        int head();
        int tail();
        int getCount();
        bool isEmpty();
        bool isFull();
        void display();
};

/**
 * Determines if the queue is empty
 * 
 * @returns true if the queue is empty, false otherwise
*/
bool Queue::isEmpty() {
    return (front == NULL && rear == NULL);
}

/**
 * Determines if the queue is full
 * 
 * @returns true if the queue is full, false otherwise
*/
bool Queue::isFull() {
    return (count == size);
}

/**
 * Returns the current items count of the queue
 * 
 * @returns the size of the queue
*/
int Queue::getCount() {
    return count;
}

/**
 * Adds an element to the end of the queue
 * 
 * @param itemToAdd the item to add to the queue
 * 
 * @returns void
*/
void Queue::enqueue(int itemToAdd) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        Node *newNode = new Node(itemToAdd);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
            front->next = rear;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        count++;
    }
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node *temp = front;
        if (front == rear) { // only one item in the queue
            front = rear = NULL;
        } else {
            // move the front pointer to the next item
            // point the rear pointer to the new front
            front = front->next;
            rear->next = front;
        }
        cout << "Dequeued item: " << temp->data << endl;
        delete temp;
        count--;
    }
}

/**
 * Returns the first item in the queue
 * 
 * @returns the first item in the queue
*/
int Queue::head() {
    if (isEmpty()) {
        return -1;
    } else {
        return front->data;
    }
}

/**
 * Returns the last item in the queue
 * 
 * @returns the last item in the queue
*/
int Queue::tail() {
    if (isEmpty()) {
        return -1;
    } else {
        return rear->data;
    }
}

/**
 * Displays the contents of the queue
 * 
 * @returns void
*/
void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue size: " << getCount() << endl;
        cout << "Queue head: " << head() << endl;
        cout << "Queue tail: " << tail() << endl;

        Node *temp = front;
        cout << "Queue contents: " << endl;
        
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
}

int main() {
    Queue queue(5);

    for (int i = 0; i < 5; i++) {
        queue.enqueue(i);
    }

    queue.display();

    queue.dequeue();

    queue.display();

    for (int i = 0; i < 4; i++) {
        queue.dequeue();
    }

    queue.display();

    return 0;
}
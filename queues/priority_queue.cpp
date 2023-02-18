#include <iostream>

using namespace std;

class Node {
    public:
        int data, priority;
        Node *next;

        Node(int value, int inputPriority) {
            data = value;
            priority = inputPriority;
            next = nullptr;
        }
};

/**
 * A priority queue implementation using a linked list
*/
class PriorityQueue {
    private:
        Node *front;
        int count;
    public:
        PriorityQueue() {
            front = nullptr;
            count = 0;
        }
        // operation prototypes
        void enqueue(int, int);
        void dequeue();
        int head();
        int tail();
        int getCount();
        bool isEmpty();
        void display();
};

/**
 * Determines if the queue is empty
 * 
 * @returns true if the queue is empty, false otherwise
*/
bool PriorityQueue::isEmpty() {
    return (front == nullptr);
}

/**
 * Returns the current items count of the queue
 * 
 * @returns the size of the queue
*/
int PriorityQueue::getCount() {
    return count;
}

/**
 * Adds an item to the queue
 * 
 * @param value the value to add to the queue
 * @param priority the priority of the value
*/
void PriorityQueue::enqueue(int value, int priority) {
    Node *newNode = new Node(value, priority);

    // If the priority queue is empty or the new node has the higher priority
    // than the front node, set the new node as the front of the queue
    if (isEmpty() || priority > front->priority) {
        newNode->next = front;
        front = newNode;
    }
    // Otherwise, find the correct position for the new node in the queue based on its priority
    else {
        Node *temp = front;
        while(temp->next != nullptr && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/**
 * Removes an item from the queue
*/
void PriorityQueue::dequeue() {
    if (isEmpty()) {
        cout << "The queue is empty" << endl;
    }
    else {
        // Since the front node has the highest priority, remove it
        Node *temp = front;
        front = front->next;
        delete temp;
    }
}

/**
 * Returns the value of the front node
 * 
 * @returns the value of the front node
*/
int PriorityQueue::head() {
    if (isEmpty()) {
        return -1;
    }
    else {
        return front->data;
    }
}

/**
 * Returns the value of the rear node
 * 
 * @returns the value of the rear node
*/
int PriorityQueue::tail() {
    if (isEmpty()) {
        return -1;
    }
    else {
        Node *temp = front;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
}

/**
 * Displays the queue
*/
void PriorityQueue::display() {
    if (isEmpty()) {
        cout << "The queue is empty" << endl;
    }
    else {
        Node *temp = front;
        while (temp != nullptr) {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    PriorityQueue queue;

    // Priority 2 is higher than priority 1

    queue.enqueue(1, 1);
    queue.enqueue(2, 4);
    queue.enqueue(3, 2);
    queue.enqueue(4, 3);

    queue.display();

    queue.dequeue();

    queue.display();

    queue.dequeue();

    queue.display();
}


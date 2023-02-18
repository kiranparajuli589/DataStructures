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
 * A linear Queue implementation using a linked list
*/
class Queue {
    private:
        Node *front, *rear;
        int count;
    public:
        Queue() {
            front = rear = NULL;
            count = 0;
        }
        void enqueue(int);
        void dequeue();
        int head();
        int tail();
        int getSize();
        bool isEmpty();
        void display();
};

/**
 * Determines if the queue is empty
*/
bool Queue::isEmpty() {
    return (front == NULL && rear == NULL);
}

/**
 * Returns the size of the queue
*/
int Queue::getSize() {
    if (Queue::isEmpty()) {
        return 0;
    } else {
        return count;
    }
}

/**
 * Adds an element to the end of the queue
 * 
 * @param itemToAdd the item to add to the queue
 * 
 * @returns void
*/
void Queue::enqueue(int itemToAdd) {
    Node *newNode = new Node(itemToAdd);

    if(Queue::isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

/**
 * Removes an element from the front of the queue
 * 
 * @returns void
*/
void Queue::dequeue() {
    if(Queue::isEmpty()) {
        return;
    } else {
        // store the item to be removed
        Node *temp = front;
        // update the front pointer
        front = front->next;
        // if front is NULL, then the queue is empty
        if(front == NULL) {
            rear = NULL;
        }
        // free the memory
        delete temp;
        // decrement of the count
        count--;
    }
}

int Queue::head() {
    if(Queue::isEmpty()) {
        return -1;
    } else {
        return front->data;
    }
}

int Queue::tail() {
    if(Queue::isEmpty()) {
        return -1;
    } else {
        return rear->data;
    }
}

/**
 * Displays the elements of the queue
*/
void Queue::display() {
    if(Queue::isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Size of the queue: " << Queue::getSize() << endl;
        cout << "Head element: " << Queue::head() << endl;
        cout << "Tail element: " << Queue::tail() << endl;
        cout << "Elements of the queue: " << endl;
        Node *temp = front;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << "++++" << endl;
}

int main() {
    Queue q;

    q.display();
    
    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }

    q.display();

    for (int i = 0; i < 5; i++) {
        q.dequeue();
    }

    q.display();

    return 0;
}


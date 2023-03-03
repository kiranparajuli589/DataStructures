#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int value) {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
};

/**
 * A Deque implementation using a linked list
*/
class Deque {
    private:
        Node *front, *rear;
        int count;
    public:
        Deque() {
            front = rear = nullptr;
            count = 0;
        }
        // operation prototypes
        void enqueueFront(int);
        void enqueueRear(int);
        void dequeueFront();
        void dequeueRear();
        int head();
        int tail();
        int getCount();
        bool isEmpty();
        void display();
};

/**
 * Determines if the deque is empty
 * 
 * @returns true if the deque is empty, false otherwise
*/
bool Deque::isEmpty() {
    return (front == nullptr && rear == nullptr);
}

/**
 * Returns the current items count of the deque
 * 
 * @returns the size of the deque
*/
int Deque::getCount() {
    return count;
}

/**
 * Adds an item to the front of the deque
 * 
 * @param value the value to add to the deque
*/
void Deque::enqueueFront(int value) {
    Node *newNode = new Node(value);

    // If the deque is empty, set the front and rear to the new node
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        newNode->next = front;
        front = newNode;
    }
    count++;
}

/**
 * Adds an item to the rear of the deque
 * 
 * @param value the value to add to the deque
*/
void Deque::enqueueRear(int value) {
    Node *newNode = new Node(value);

    // If the deque is empty, set the front and rear to the new node
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    count++;
}

/**
 * Removes an item from the front of the deque
*/
void Deque::dequeueFront() {
    // If the deque is empty, do nothing
    if (isEmpty()) {
        return;
    }

    Node *temp = front;

    // If there is only one item in the deque, set the front and rear to null
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }
    delete temp;
    count--;
}

/**
 * Removes an item from the rear of the deque
*/
void Deque::dequeueRear() {
    // If the deque is empty, do nothing
    if (isEmpty()) {
        return;
    }

    Node *temp = rear;

    // If there is only one item in the deque, set the front and rear to null
    if (front == rear) {
        front = rear = nullptr;
    } else {
        rear = rear->prev;
        rear->next = nullptr;
    }
    delete temp;
    count--;
}

/**
 * Returns the value of the item at the front of the deque
 * 
 * @returns the value of the item at the front of the deque
*/
int Deque::head() {
    // If the deque is empty, return -1
    if (isEmpty()) {
        return -1;
    }
    return front->data;
}

/**
 * Returns the value of the item at the rear of the deque
 * 
 * @returns the value of the item at the rear of the deque
*/

int Deque::tail() {
    // If the deque is empty, return -1
    if (isEmpty()) {
        return -1;
    }
    return rear->data;
}

/**
 * Displays the contents of the deque
*/

void Deque::display() {
    if (isEmpty()) {
        cout << "The deque is empty" << endl;
        return;
    }

    cout << "The size of the deque is: " << count << endl;
    cout << "The head of the deque is: " << head() << endl;
    cout << "The tail of the deque is: " << tail() << endl;

    cout << "The contents of the deque are: " << endl;

    Node *temp = front;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl << "+++++" << endl;
}

int main() {
    Deque deque;

    for (int i = 100; i < 105; i++) {
        deque.enqueueFront(i);
    }

    deque.display();

    for (int i = 200; i < 205; i++) {
        deque.enqueueRear(i);
    }

    deque.display();

    for (int i = 0; i < 5; i++) {
        deque.dequeueFront();
    }

    deque.display();

    for (int i = 0; i < 5; i++) {
        deque.dequeueRear();
    }

    deque.display();

    return 0;
}

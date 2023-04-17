#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node *next;

        Node(int value) {
            this->value = value;
            this->next = NULL;
        }
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int size;
    public:
        LinkedList() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }

        void append(int);
        void remove(int);
        void get(int);
        void print();
        int getSize();
        Node* getHead();
        Node* getTail();
        Node* getNode(int);
};

void LinkedList::append(int value) {
    Node *newNode = new Node(value);

    if (this->head == NULL) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

void LinkedList::remove(int index) {
    if (index < 0 || index >= this->size) {
        cout << "Index out of range" << endl;
        return;
    }
    while 
}
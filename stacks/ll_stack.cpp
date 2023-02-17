#include <iostream>

using namespace std;

/**
 * A node in a linked list
*/
class Node {
    public:
        int data;
        Node *next; // Pointer to the next node
};

/**
 * A stack implemented using a linked list
*/
class Stack {
    private:
        Node* top; // Pointer to the top node of the stack
    public:
        Stack() { top = NULL; } // constructor

        // operation declarations
        void push(int newElement);
        int pop();
        int peek();
        bool isEmpty();
        void display();
};

/**
 * Checks if the stack is empty
 * 
 * @returns true if stack is empty
 * @returns false if stack is not empty
*/
bool Stack::isEmpty() {
    return top == NULL;
}

/**
 * Adds an element to the top of the stack
*/
void Stack::push(int newElement) {
    Node *newNode = new Node(); // Create a new node
    newNode->data = newElement; // Set the data of the new node
    newNode->next = top; // Set the next pointer of the new node to the current top
    top = newNode; // Update the top pointer of the Stack to the new node just created
    return;
}

/**
 * Removes the top element of the stack
 * 
 * @returns 0 if stack is empty
 * @returns the popped element if stack is not empty
*/
int Stack::pop() {
    if (Stack::isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        Node *temp = top; // Create a temporary pointer to the top node
        top = top->next; // Update the top pointer of the Stack to the next node
        int poppedElement = temp->data; // Store the data of the popped node
        delete temp; // Delete the popped node
        return poppedElement;
    }
}

/**
 * Returns the top element of the stack
 * 
 * @returns 0 if stack is empty
 * @returns the top element if stack is not empty
*/
int Stack::peek() {
    if (Stack::isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        return top->data;
    }
}

/**
 * Displays the stack
*/
void Stack::display() {
    if (Stack::isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        Node *temp = top;
        while (temp != NULL) {
            cout << "| " << temp->data << endl;
            temp = temp->next;
        }
        cout << "+---+" << endl;
    }
}

int main() {
    Stack stack;
    
    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }

    cout << "Top element is " << stack.peek() << endl;

    stack.display();
    
    cout << stack.pop() << " popped from stack" << endl;
    
    cout << "Top element is " << stack.peek() << endl;
    
    stack.display();

    return 0;
}


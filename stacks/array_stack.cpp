#include <iostream>

using namespace std;

#define MAX 10

class Stack {
    int top;
    public:
        int stackArray[MAX];
        Stack() { top = -1; } // constructor

        // operation declarations
        bool push(int newElement);
        int pop();
        int peek();
        int size();
        bool isEmpty();
        bool isFull();
        void display();
};

/**
 * Determines if the stack is empty
 * 
 * @returns true if stack is empty
 * @returns false if stack is not empty
*/
bool Stack::isEmpty() {
    return (top < 0);
}

/**
 * Determines if the stack is full
 * 
 * @returns true if stack is full
 * @returns false if stack is not full
*/
bool Stack::isFull() {
    return (top >= (MAX - 1));
}

/**
 * Returns the size of the stack
*/
int Stack::size() {
    return (top + 1);
}

/**
 * Adds an element to the top of the stack
 * 
 * @returns false if stack is full
 * @returns true if element is successfully added
*/
bool Stack::push(int newElement) {
    if (Stack::isFull()) {
        cout << "Stack reached max capacity" << endl;
        return false;
    } else {
        stackArray[++top] = newElement;
        cout << newElement << " pushed into stack" << endl;
        return true;
    }
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
        int poppedElement = stackArray[top--];
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
        int topElement = stackArray[top];
        return topElement;
    }
}

/**
 * Displays the elements of the stack
*/
void Stack::display() {
    if (Stack::isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    } else {
        cout << "Stack size is " << Stack::size() << endl;
        cout << "Top element is " << Stack::peek() << endl;
        cout << "Stack elements are: " << endl;
        
        for (int i = top; i >= 0; i--) {
            cout << "| " << stackArray[i] << endl;
        }

        cout << "+----+" << endl;
    }
}


int main () {
    class Stack stack;
    stack.push(10);
    stack.push(200);
    stack.push(30);

    stack.display();
    
    cout << stack.pop() << " popped from stack" << endl;
    
    stack.display();

    // pop until the stack is empty
    while (!stack.isEmpty()) {
        cout << stack.pop() << " popped from stack" << endl;
    }

    stack.display();

    return 0;
}

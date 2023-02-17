#include <iostream>

using namespace std;

#define MAX 10

class Stack {
    int top;
    public:
        int stackArray[MAX];
        Stack() { top = -1; } // constructor

        // operation declarations
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

/**
 * Adds an element to the top of the stack
 * 
 * @returns false if stack is full
 * @returns true if element is successfully added
*/
bool Stack::push(int newElement) {
    if (top >= (MAX - 1)) {
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
    if (top < 0) {
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
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        int topElement = stackArray[top];
        return topElement;
    }
}

/**
 * Determines if the stack is empty
 * 
 * @returns true if stack is empty
 * @returns false if stack is not empty
*/
bool Stack::isEmpty() {
    return (top < 0);
}


int main () {
    class Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << stack.pop() << " popped from stack" << endl;
    cout << "Top element is " << stack.peek() << endl;
    cout << "Stack is empty: " << stack.isEmpty() << endl;

    // pop until the stack is empty
    while (!stack.isEmpty()) {
        cout << stack.pop() << " popped from stack" << endl;
    }

    cout << "Top element is " << stack.peek() << endl;
    cout << "Stack is empty: " << stack.isEmpty() << endl;

    return 0;
}

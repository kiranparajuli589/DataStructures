#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int precedence(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

/**
 * The infixToPostfix function takes an infix expression as a string and returns the postfix expression as a string.
 * The function uses a stack to keep track of operators and a precedence function to determine the order in which operators are added to the postfix expression.
 * The "isalnum" function is used to check if a character is a letter or a digit.
 * The unordered_map is used to map each operator to its precedence level.
 * The main function calls infixToPostfix on an example infix expression and prints both the infix and postfix expressions to the console.
*/
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix;
    unordered_map<char, int> precedenceMap{{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+b*c-(d/e+f^g*h)";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;

    string infix2 = "(A+B/C*(D+E)-F)";
    string postfix2 = infixToPostfix(infix2);
    cout << "Infix expression: " << infix2 << endl;
    cout << "Postfix expression: " << postfix2 << endl;
    return 0;
}

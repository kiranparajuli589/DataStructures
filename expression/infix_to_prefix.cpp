#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

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
 * The infixToPrefix function takes an infix expression as a string and returns the prefix expression as a string.
 * The function uses a stack to keep track of operators and a precedence function to determine the order in which operators are added to the prefix expression.
 * The isalnum function is used to check if a character is a letter or a digit.
 * The unordered_map is used to map each operator to its precedence level.
 * The main function calls infixToPrefix on an example infix expression and prints both the infix and prefix expressions to the console.
 * Note that the reverse function is used to reverse the infix expression before processing it and to reverse the prefix expression after processing it.
*/
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    stack<char> operators;
    string prefix;
    unordered_map<char, int> precedenceMap{{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    for (char c : infix) {
        if (isalnum(c)) {
            prefix += c;
        } else if (c == ')') {
            operators.push(c);
        } else if (c == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == ')') {
                operators.pop();
            }
        } else {
            while (!operators.empty() && precedence(operators.top()) > precedence(c)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix = "a+b*c-(d/e+f^g*h)";
    string prefix = infixToPrefix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}

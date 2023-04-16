#include<iostream>

using namespace std;

int fibonacci(int num) {
    if (num == 0 || num == 1) {
        return num;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main() {
    int num;
    cout << "Enter a number of terms of Fibonacci series: ";
    cin >> num;
    cout << "Fibonacci series: ";
    for (int i = 0; i < num; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}
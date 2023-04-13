#include<vector>
#include<iostream>
#include<ctime>


using namespace std;

void displayArray(vector<int> arr) {
    for (int i = 0; i < int(arr.size()); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

time_t now() {
    return time(0);
}

int getMax(vector<int>& arr) {
    int max = arr[0];

    for (int i = 1; i < int(arr.size()); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}
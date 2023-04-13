#include <iostream>
#include <vector>
#include "base.h"

using namespace std;

int getParentPos(int pos) {
    return (pos-1) / 2;
}

int getLeftChildPos(int pos) {
    return 2 * pos + 1;
}

int getRightChildPos(int pos) {
    return 2 * pos + 2;
}

void shiftDown(vector<int>& arr, int start, int end) {
    int root = start;
    while (getLeftChildPos(root) <= end) {
        int child = getLeftChildPos(root);
        int temp = root;
        if (arr[temp] < arr[child]) {
            temp = child;
        }
        if (child + 1 <= end && arr[temp] < arr[child+1]) {
            temp = child + 1;
        }
        if (temp == root) {
            return;
        } else {
            swap(arr[root], arr[temp]);
            root = temp;
        }
    }
}

void heapify(vector<int>& arr) {
    int size = arr.size();
    int start = getParentPos(size - 1);
    
    while (start >= 0) {
        shiftDown(arr, start, size - 1);
        start -= 1;
    }
}

void heapSort(vector<int>& arr) {
    heapify(arr);
    int end = arr.size() - 1;
    while (end > 0) {
        swap(arr[end], arr[0]);
        end -= 1;
        shiftDown(arr, 0, end);
    }
}

int main() {
    vector<int> unsorted{8, 5, 2, 6, 9, 3, 1, 4, 0, 7};

    heapSort(unsorted);

    displayArray(unsorted);

    return 0;
}

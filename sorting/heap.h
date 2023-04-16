#include <iostream>
#include <vector>

using namespace std;


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
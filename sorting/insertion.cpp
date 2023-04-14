#include<iostream>
#include<vector>
#include "base.h"

using namespace std;

vector<int> insertionSort(vector <int> arr) {
    int i = 1;

    // moves A[i] to its position in one go
    // only performs one assignment in the inner loop
    while(i < arr.size()) {
        int curr = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > curr) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = curr;
        i++;
    }

    return arr;
}

void insertionSortRecursively(vector<int>& arr, int size) {
   if (size <= 1) {
        return;
    }

    insertionSortRecursively(arr, size-1);

    int curr = arr[size-1];
    int j = size - 2;

    while(j>= 0 && arr[j] > curr) {
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = curr;
}

int main() {
    vector<int> unsorted{ 8, 2, 4, 9, 3, 6 };
    cout << "Insertion Sort:" << endl;
    displayVector(insertionSort(unsorted));
    cout << "Insertion Sort Recursively:" << endl;
    insertionSortRecursively(unsorted, unsorted.size());
    displayVector(unsorted);
    return 0;
}
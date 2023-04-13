#include<vector>
#include<iostream>
#include "base.h"

using namespace std;

void performMerge(vector<int>& arr, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[middle+1+j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i<leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void performMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        performMergeSort(arr, left, middle);
        performMergeSort(arr, middle + 1, right);

        performMerge(arr, left, middle, right);
    }
}

int main() {
    vector<int> unsorted{ 5, 4, 3, 2, 1 };

    performMergeSort(unsorted, 0, unsorted.size());

    displayArray(unsorted);

    return 0;
}
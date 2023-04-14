#include<vector>
#include<iostream>
#include "base.h"
#include "heap.h"
#include "merge.h"

using namespace std;

void bubbleSort(vector<int>& arr) {
    int size = (int)arr.size();
    do {
        int cursor = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i-1] > arr[i]) {
                swap(arr[i-1], arr[i]);
                cursor = i;
            }
        }
        size = cursor;
    } while (size > 1);
}

void performHeadSort(vector<int>& arr) {
    heapify(arr);
    int end = arr.size() - 1;
    while (end > 0) {
        swap(arr[end], arr[0]);
        end -= 1;
        shiftDown(arr, 0, end);
    }
}

void performInsertionSort(vector<int>& arr) {
    int i = 1;
    while(i < (int)arr.size()) {
        int curr = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > curr) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
        i++;
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

void performRadixSort(vector<int>& arr, int radix = 10) {
    int exp = 1;
    int max = getMax(arr);
    vector<vector<int>> buckets(radix);

    while(max > 0) {
        for (int i = 0; i < int(arr.size()); i++) {
            int digit = (arr[i]/exp) % radix;
            buckets[digit].push_back(arr[i]);
        }
        arr.clear();
        for (int i = 0; i < radix; i++) {
            arr.insert(
                arr.end(),
                buckets[i].begin(),
                buckets[i].end()
            );
            buckets[i].clear();
        }
        exp *= radix;
        max /= radix;
    }
}

void performSelectionSort(vector<int>& arr) {
    int size = int(arr.size());
    for (int i = 0; i < size-1; i++) {
        int currentMinimum = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[currentMinimum]) {
                currentMinimum = j;
            }
        }
        if (currentMinimum != i) {
            int temp = arr[i];
            arr[i] = arr[currentMinimum];
            arr[currentMinimum] = temp;
        }
    }
}

void performShellSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j-gap] > temp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}




#include <iostream>
#include <vector>
#include "base.h"
#include "ctime"

using namespace std;

void performBubbleSort(vector<int>& arr) {
    time_t start, end;
    start = now();
    int size = int(arr.size());
    for (int i = 0; i < size-1; i++) {
        bool swapped = false;
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    end = now();
    cout << "Time taken: " << end - start << " seconds" << endl;
}

void performOptimizedBS(vector<int>& arr) {
    time_t start, end;
    start = now();
    int size = int(arr.size());

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

    end = now();
    cout << "Time taken: " << end - start << " seconds" << endl;
}

int main() {
    vector <int> unsorted{ 8, 2, 4, 9, 3, 6 };
    cout << "Bubble sort: " << endl;

    performBubbleSort(unsorted);
    displayArray(unsorted);


    vector<int> unsorted1{ 8, 2, 4, 9, 3, 6 };
    cout << "Optimized Bubble sort: " << endl;
    performOptimizedBS(unsorted1);
    displayArray(unsorted1);

    return 0;
}
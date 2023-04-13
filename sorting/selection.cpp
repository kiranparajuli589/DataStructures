#include<iostream>
#include<array>
#include "base.h"
#include <vector>

using namespace std;


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

int main() {
    vector<int> unsorted{ 8, 2, 4, 9, 3, 6 };
    performSelectionSort(unsorted);
    displayArray(unsorted);
}
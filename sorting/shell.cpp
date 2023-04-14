#include<iostream>
#include<vector>
#include "base.h"

using namespace std;

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

int main() {
    vector <int> unsorted{8, 9, 1, 7, 2, 3, 5, 4, 6, 0};

    performShellSort(unsorted);

    displayVector(unsorted);

    return 0;
}
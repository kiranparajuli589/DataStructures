#include<vector>
#include<iostream>
#include "base.h"

using namespace std;

void performRadixSort(vector<int>& arr, int radix = 10) {
    int exp = 1;
    int max = getMax(arr);
    // create buckets for each digit
    vector<vector<int>> buckets(radix);

    // loop upto the maximum number of digits
    while(max > 0) {
        // put each number in the respective bucket
        for (int i = 0; i < int(arr.size()); i++) {
            int digit = (arr[i]/exp) % radix;
            buckets[digit].push_back(arr[i]);
        }
        // concatenate the bucket items back to the array
        arr.clear();
        for (int i = 0; i < radix; i++) {
            arr.insert(
                arr.end(),
                buckets[i].begin(),
                buckets[i].end()
            );

            buckets[i].clear();
        }

        // move on to the next digit
        exp *= radix;
        max /= radix;
    }

}

int main() {

    vector<int> unsorted{ 170, 45, 75, 90, 802, 24, 2, 66 };

    performRadixSort(unsorted);

    displayVector(unsorted);

    return 0;
}

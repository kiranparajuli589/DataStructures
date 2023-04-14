#include <iostream>
#include <vector>
#include <cmath>
#include "../sorting/sort.h"

using namespace std;

int linearSearch(vector<int>& arr, int target)
{
    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] == target)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int binarySearch(vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    performShellSort(arr);

    while (left != right)
    {
        int middle = ceil((float)(left + right) / (float)2);
        if (arr[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            left = middle;
        }
    }
    if (arr[left] == target)
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> arr{1, 2, 4, 6, 3, 7, 4, 6};

    int index = linearSearch(arr, 6);

    cout << "Linear Search::Found " << 6 << " at index: " << index << endl;

    index = binarySearch(arr, 2);

    cout << "Binary Search::Found " << 2 << " at index: " << index << endl;

    return 0;
}
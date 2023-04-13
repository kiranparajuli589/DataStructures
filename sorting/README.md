# Sorting

Sorting is an arrangement of data in a particular order or sequence. It is a common algorithmic problem in computer science and used in various applications such as searching, data analysis and information retrieval.

The main advantage of sorting is time complexity and that's the most important thing when you solve a problem because it's not enough you're able to solve a problem, but you should be able to solve it in the minimum time possible.

## Types

### 1. Internal Sort
An internal sort is any data sorting process that takes place entirely within the main memory of a computer. This is possible whenever the data to be sorted is small enough to all be held in the main memory like hard-disk. Some common internal sorting algorithms include:

- Bubble Sort
- Insertion Sort
- Selection Sort
- Heap Sort
- Radix Sort

### 2. External Sort
An external sort is a class of sorting algorithms that can handle massive amounts of data. External sorting is required when the data being sorted do not fit into the main memory of a computing device (usually RAM) and instead they must reside in the slower external memory, usually disk drive. Thus, external sorting algorithms are external memory algorithms and thus applicable in the external memory model of computation. Some common external sorting algorithms include:

- External Merge Sort
- External Distribution Sort


## Insertion sort

Algorithm:

Sorting is typically done in-place, by iterating up the array, growing the sorted list behind it. At each array-position, it checks the value there against the largest value in the sorted list (which happens to be next to it, in the previous array-position checked). If larger, it leaves the element in place and moves to the next. If smaller, it finds the correct position within the sorted list, shifts all the larger values up to make a space, and inserts into that correct position.

The resulting array after k iterations has the property where the first k + 1 entries are sorted (`+1` because the first entry is skipped). In each iteration the first remaining entry is inserted into the result at the correct position, thus extending the result.


Pseudocode:
```
i <- 1
while i < length(A)
    j <- i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j <- j - 1
    end while
    i <- i + 1
end while
```

Time complexity:

- Best case: O(n)
- Average case: O(n^2)
- The Worst case: O(n^2)

## Selection sort

Algorithm:
- Set the first element as the minimum value.
- Compare this item to the next item in the array until you find a smaller number.
- If a smaller number is found, designate that smaller number to be the new "minimum" and continue until the end of the array. Now the new minimum value is swapped with the previous minimum value.
- Repeat this with the next element until the array is sorted.

Pseudocode:
```
i <- 0
for i to length(A) - 1
    min <- i
    for j <- i + 1 to length(A)
        if A[j] < A[min]
            min <- j
        end if
    end for
    if min != i
        swap A[i] and A[min]
    end if
end for
```

Time complexity:

The time complexity of selection sort is the same for all cases - worst, average, and best - as it always performs the same number of comparisons and swaps for a given input size.

The time complexity of selection sort is O(n^2).


## Exchange sort

An exchange sort algorithm is one which compares adjacent elements and swaps them to their correct positions based on a less-than or greater than comparisons. For example, while sorting to ascending order, we might swap if the element on the left is greater than the element on the right.

It is also known as "Bubble Sort" because the largest element "bubbles" to the top of the array.

Algorithm:
1. Start with the first element of the array and compare with the adjacent element.
2. If the adjacent element is smaller, swap with the first one.
3. Repeat step 1 and 2 until the end of the array.
4. After the first pass, the largest element in the array will have "bubbled" to the last position.
5. Repeat steps 1-4 for the remaining elements in the array (i.e. exclude the last element, as it is already in its correct sorted position).
6. Repeat steps 1-5 until the array is sorted.

Pseudocode:
```
procedure bubbleSort(A: list of sortable items)
    n <- length(A)
    repeat
        swapped <- false
        for i <- 1 to n-1 inclusive do
            /* if this pair is out of order */
            if A[i-1] > A[i] then
                /* swap them and remember something changed */
                swap(A[i-1], A[i])
                swapped <- true
            end if
        end for
        n <- n - 1
    until not swapped
end procedure
```

More generally, it can happen that more than one element is placed in their final position on a single pass. In particular, after every pass, all elements after the last swap are sorted, and do not need to be checked again. This allows to skip over many elements, resulting in about the worst case 50% improvement in comparison count (though no improvement in swap counts), and adds very little complexity because the new code subsumes the "swapped" variable:

```
procedure bubbleSort(A: list of sortable items)
    n <- length(A)
    repeat
        newn := 0
        for i <- 1 to n-1 inclusive do
            /* if this pair is out of order */
            if A[i-1] > A[i] then
                /* swap them and remember something changed */
                swap(A[i-1], A[i])
                newn := i
            end if
        end for
        n <- newn
    until n <= 1
end procedure
```

Time Complexity:

- Best case: O(n)
- Average case: O(n^2)
- The Worst case: O(n^2)    

## Merge sort

It is an efficient, general-purpose, and comparison-based sorting algorithm. Merge sort is a divide and conquer algorithm that was invented by John von Neumann in 1945.

Algorithm:

- Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
- Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

Pseudocode:
```
procedure mergeSort(arr, left, right)
    if left < right
        middle = (left + right) / 2
        mergeSort(arr, left, middle)
        mergeSort(arr, middle + 1, right)
        merge(arr, left, middle, right)
    endif
end procedure

procedure merge(arr, left, middle, right)
    n1 = middle - left + 1
    n2 = right - middle

    // create temporary arrays for left and right halves
    L = new array of size n1
    R = new array of size n2

    // copy data to temporary arrays
    for i = 0 to n1 - 1
        L[i] = arr[left + i]
    end for

    for j = 0 to n2 - 1
        R[j] = arr[middle + 1 + j]
    end for

    // merge the temporary arrays back into arr
    i = 0
    j = 0
    k = left
    while i < n1 and j < n2
        if L[i] <= R[j]
            arr[k] = L[i]
            i++
        else
            arr[k] = R[j]
            j++
        end if
        k++
    end while

    // copy the remaining elements of L, if there are any
    while i < n1
        arr[k] = L[i]
        i++
        k++
    end while

    // copy the remaining elements of R, if there are any
    while j < n2
        arr[k] = R[j]
        j++
        k++
    end while
end procedure
```
Time complexity:

- Best case: O(n log n)
- Average case: O(n log n)
- The Worst case: O(n log n)

## Radix Sort

It is a non-comparative sorting algorithm in computer science. It avoids comparison by creating and categorizing elements based on their radix. It is a linear sorting algorithm. For elements with more than one significant digit, this bucketing process is repeated for each digit, while preserving the ordering of the prior step, until all digits have been considered. For this reason, radix sort has also been called bucket sort and digital sort.

Algorithm:

- Define the input array to be sorted and find the maximum value in the array
- Create `d` number of buckets, where `d` is the radix (10 for decimal numbers)
- Initialize a variable `exp` to 1, which represents the current digit being considered for sorting. This variable will be multiplied by 10 for each pass of the outer loop.
- Loop from the least significant digit to the most significant digit
    - Initialize an array of buckets to hold the values for each digit
    - Iterate through each element in the input array
        - Extract the current digit from the element by dividing it by `exp` and taking the remainder.
        - Add the element to the bucket at the index corresponding to the current digit.
    - Concatenate the elements from the buckets into the original array
    - Multiply `exp` by 10 to move to the next digit


Pseudocode:

```
procedure radixSort(array)
    max <- find largest element in array
    exp <- 1
    while max / exp > 0
        countingSort(array, exp)
        exp <- exp * 10
        max <- max // 10
    end while
end procedure

procedure countingSort(array, i)
    buckets <- new array of d array elements
    for num in arr:
        digit <- (num // i) % 10
        buckets[digit].append(num)
    end for
    arr <- concatenate buckets
end procedure
```

Time Complexity:

- Best case: O(nk)
- Average case: O(nk)
- The Worst case: O(nk)

## Shell Sort

Shell sort is an optimization of insertion sort that allows the exchange of items that are far apart. The idea is to arrange the list of elements so that, starting anywhere, taking every `h`th element produces sorted list. Such a list is said to be `h`-sorted.

Beginning with large values of `h` allows elements to move long distances in the original list, reducing large amounts of disorder quickly, and leaving less work for smaller `h`-sort steps to take. Following this idea for a decreasing sequence of `h` values ending in 1 is guaranteed to leave a sorted list in the end.

Algorithm:
1. Initialize the value of `h` as the length of the list divided by 2.
2. Divide the list into smaller list of equal interval `h`.
3. Sort these sublists using insertion sort.
4. Decrease the value of `h` by a factor of 2 until it becomes 1.
5. Repeat steps 2, 3 and 4 until the list is sorted.


Pseudocode:
```
procedure shellSort(arr)
    n <- length(arr)
    gap <- n / 2
    while gap > 0
        for i <- gap to n-1
            temp = arr[i]
            j <- i
            while j >= gap and arr[j-gap] > temp
                arr[j] = arr[j-gap]
                j <- j - gap
            end while
            arr[j] = temp
        end for
        gap <- gap / 2
    end while
end procedure
```

Time Complexity:

- Best case: O(n log n)
- Average case: depends on gap sequence
- The Worst case: O(n^2)

## Heap Sort

### Complete Binary Tree
If the index of any element is the array is `i`, the element in the index `2i+1` will become the left child and element in `2i+2` index will become the right child. Also, the parent of any element at index `i` is given by the lower bound of `(i-1)/2`

### Max Heap
A max heap is a complete binary tree data structure in which the value of each parent node is greater than or equal to the value of its children. The root node is the largest element in the tree.

### Algorithm
1. Call the `buildMaxHeap()` function on the list. Also referred as `heapify()`, this builds a heap from a list in `O(n)` operations.
2. Swap the first element of the list with the final element. Decrease the considered range of the list by one.
3. Call the `shiftDown()` function on the list to shift the new first element to its appropriate index in the heap.
4. Go to step (2) unless the considered range of the list is one element

### Time Complexity
The `buildMaxHeap()` operation is run once, and is `O(n)` in performance. The `shiftDown()` function is `O(log n)` and is called `n` times. Therefore, the performance of this algorithm is `O(n + nlog n) = O(nlog n)`

### Pseudocode
```
procedure heapSort(arr, size)
    heapify(arr, size) // build the heap in array so that largest value is at the root
    end <- size - 1 // considerable size of the list
    // The following loop maintains the invariants that "a[0:end]" is a heap and every element
    // Beyond "end" is greater than everything before it, so a[end:size] is in sorted order
    while (end > 0) do
        // a[0] is the root and the largest value. The swap moves it in from of the sorted elements.
        swap(a[end], a[0])
        // The heap size is reduced by one
        end <- end - 1
        // The swap ruined the heap property, so restore it
        shiftDown(arr, 0, end)
    end while
end procedure

procedure heapify(arr, size)
    // "start" is assigned the index in "arr" of the last parent node
    // the last element in a 0-based array is at index "count - 1"
    start <- iParent(size - 1)
    
    while start >= 0 do
        // Shift down the node at index "start" to the proper place such that all nodes below the "start" index are in heap order
        shiftDown(arr, start, size - 1)
        // Go to the next parent node
        start <- start - 1
    end while
end procedure

procedure shiftDown(arr, start, end)
    root <- start
    
    // While the root has at least one child
    while iLeftChild(root) <= end do
        child <- iLeftChild(root)
        swap = root // Keeps tract of child to swap with
        
        if arr[swap] < arr[child] then
            swap = child
        end if
        // If there is a right child and that child is greater
        if child + 1 <= end and arr[swap] < arr[child+1] then
            swap <- child + 1
        end if
        // If root holds the largest element, childs are valid
        if swap = root then
            return
        else
            swap(a[root], a[swap])
            root <- swap
        end if
    end while
end procedure
```

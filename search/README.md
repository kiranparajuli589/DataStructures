# Searching

Searching in data structure refers to the process of finding the required information from a collection of items stored as elements in the computer memory. These sets of items can be in different forms, such as an array, linked list, graph, or tree. Another way to define searching is to say that it is the process of locating the desired element of specific characteristics in a collection of elements.

## Searching Techniques

There are several common searching techniques used in data structures. The following are the most common searching techniques:

1. Sequential search:

    Sequential search is a method of searching for a particular element in a list by checking each element sequentially until the desired element is found. It is also known as linear search. The time complexity of this method is O(n).

    Examples: Linear Search

2. Binary search:

    Also known as half-interval search, logarithmic search, or binary chop.

    Binary search is a search algorithm that finds the position of a target value within a sorted array. The algorithm compares the target value to the middle element f the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array. The time complexity of this method is O(log n), where n is the number of elements in the array.

### Linear Search

#### Algorithm

Given a list L of n elements with values or records L0, L1, ..., Ln-1, and target value T, the following subroutine uses a linear search to find the index of T in L.

1. Set `i` to `0`.
2 if `Li` is equal to `T`, go to step 4.
3. Add `1` to `i`.
4. If `i < n`, the search terminates successfully; Else, the search terminates unsuccessfully.

#### Pseudocode

```
procedure linearSearch(arr, target)
    i <- 0
    while i < length(arr)
        if arr[i] = target
            return i
        i <- i + 1
    return -1
end procedure
```

### Binary Search

#### Algorithm

Given an array A of n elements with values or records A0, A1, ..., An-1, sorted such that `A0 <= A1 <= ... <= An-1`, and target value T, the following subroutine uses a binary search to find the index of T in A.

1. Set `L` to `0` and `R` to `n-1`.
2. If `L > R`, the search terminates as unsuccessful.
3. Set `m` (the position of the middle element) to the floor of `(L + R) / 2`, which is the greatest integer less than or equal to `(L + R) / 2`.
4. If Am < T, set `L` to `m+1` and go to step 2.
5. If `Am > T`, set `R` to `m-1` and go to step 2.
6. If `Am = T`, the search is done; return `m`.

#### Pseudocode

```
procedure binarySearch(arr, target)
    L <- 0
    R <- Length(arr) - 1
    while L <= R
        m = floor((L+R)/2)
        if arr[m] < T then
            L = m + 1
        else if arr[m] > T then
            R = m -1
        else
            return m
        end if
    end while
    return -1
end procedure
```

#### Optimized Pseudocode
The above procedure checks whether the middle element is equal to the target in every iteration. Some implementations leave out this check during each iteration. The algorithm would perform this check only when one element is left (when L=R). This results in a faster comparison loop, as one comparison is eliminated per iteration, while it requires only one more iteration on average.

```
procedure binarySearch(arr, target)
    L <- 0
    R <- Length(arr) - 1
    while L != R do
        m = ceil((L+R)/2)
        if A[m] > T then
            R <- m - 1
        else
            L <- m
        end if
    end while
    if arr[L] = T then
        return L
    else
        return -1
    endif
end procedure
```

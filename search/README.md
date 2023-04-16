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

## Linear Search

### Algorithm

Given a list L of n elements with values or records L0, L1, ..., Ln-1, and target value T, the following subroutine uses a linear search to find the index of T in L.

#### Basic Algorithm
1. Set `i` to `0`.
2. If `Li` is equal to `T`, the search terminates successfully.
3. Increase `i` by `1`.
4. If `i < n`, go to step 2; Else, the search terminates unsuccessfully.

##### Pseudocode

```
procedure linearSearch(arr, target)
    i <- 0;
    while i < Length(arr)
        if arr[i] = target then
            return i
        end if
        i <- i + 1
    end while
    return -1
```

#### With Sentinel

The basic algorithm above makes two comparisons per iteration: one to check if L[i] equals T, and the other to check if `i` still points to a valid index of the list. By adding an extra record L[n] to the list (a sentinel value) that equals the target, the second comparison can be eliminated until the end of the search, making the algorithm faster. The search will reach the sentinel if the target is not contained within the list.

1. Set `i` to `0`.
2 if `Li` is equal to `T`, go to step 4.
3. Add `1` to `i`.
4. If `i < n`, the search terminates successfully; Else, the search terminates unsuccessfully.

##### Pseudocode


```
procedure linearSearch(arr, target)
    i <- 0
    while arr[i] != target
        i <- i + 1
    end while
    if i < Length(arr) then
        return i
    else
        return -1
    end if
end procedure
```

#### In an ordered list

If the list is ordered, the algorithm can be modified to terminate as soon as `Li` is greater than `T`, since the list is sorted and all remaining elements will be greater than `T`.

1. Set `i` to `0`.
2. If `Li >= T`, go to step 4.
3. Add `1` to `i`.
4. If `Li = T`, the search terminates successfully; Else, the search terminates unsuccessfully.

##### Pseudocode

```
procedure linearSearch(arr, target)
    i <- 0
    while arr[i] <= target
        i <- i + 1
    end while
    if arr[i] = target then
        return i
    else
        return -1
    end if
end procedure
```

#### Time Complexity

The worst-case cost and the average-case cost of linear search are both `O(n)`, where n is the number of elements in the array.

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

#### Time Complexity

The time complexity of binary search is `O(log n)`, where n is the number of elements in the array.

## General Search Tree

## Hashing

The searching time of each searching technique, that were discussed in the above section, depends on the comparison i.e., `n` comparisons required for an array `A` with `n` elements. To increase the efficiency i.e. to reduce the searching time, we need to avoid the unnecessary comparisons.

Hashing is a technique where we can compute the location of the desired record in order to retrieve it in a single access (or comparison).

Let there is a table of `n` employee records and each employee record is defined by a unique employee code, which is a key to the record in the table. If the key (employee code) is used as the index of the table, then the record can be retrieved in a single access. If we can locate the memory address of a record from the key then the desired record can be retrieved in a single access. This is the basic idea of hashing.

For notational and coding convenience, we assume that the keys in `k` and the address in `L` are integers. The hash function is a function that maps a key to the address `L` in the table.

### Hash Function

A Hash function `h` can be defined as a function that takes key as input `k` and transforms it into a hash table index `L`.

Hash functions are of two types:

1. Distribution - Independent function
2. Distribution - Dependent function

Popular Distribution - Independent Hash Functions:

1. Division Method
2. Mid-Square Method
3. Folding Method

### Division Method

Choose a number `m`, which is larger than the number of keys `k` in the table. The hash function is defined as:

`h(k) = k mod m`

where, `mod` is the modulo operator.

Suppose an employee code is `1234` in a list of `90` employees. Now, `m` should be greater than `90`. Let `m = 100`. Then, for the employee code `1234`, the hash function will be:

```
h(1234) = 1234 mod 100 = 34
```
### Mid-Square Method

The mid-square method is a hash function that uses the certain number (r) of middle digits of the square of the key as the hash value.

```
H(k) = k^2
```

For the above example with `r = 2`, the hash function will be:

```
k^2 = 1234^2 = 152275
h(22) = 1234
```

### Folding Method

The method breaks up a key value into precise segments that are added to form a hash value.

Algorithm:

- The key is divided into equal-sized segments (the last segment may not be of equal size because the key may not be divisible by the number of segments).

- The segments are then added together to give the hash value.

- The sum is then divided by the table size to give the remainder.


## Hash Collision

Hash collision is a situation where two or more keys are mapped to the same hash value. This is a problem because the hash function is supposed to be a one-to-one mapping. If two keys are mapped to the same hash value, then the hash table will store only one of the keys and the other key will be lost.

Collision occur because different hashing techniques in data structure convert every input into a fixed-length code, regardless of its length. Since there are an endless number of inputs and a limited number of outputs, the hashing algorithms will eventually produce repeating hashes.

## Collision Resolution

Collision resolution is a technique to resolve the collision problem. There are two types of collision resolution techniques:

1. Separate Chaining
2. Open Addressing

### Separate Chaining

The process involves building a linked list with key-value pair for each search array index. The collided items are chained together through a single linked list, which can be traversed to access the item with a unique search key.

### Open Addressing

It is a collision technique in which every entry record is stored in the bucket array itself, and the hash resolution is performed through probing. When a new entry has to be inserted, the buckets are examined, started with the hasted-to slot and proceeding in some probe sequence, until an unoccupied slot is found. When searching for an entry, the buckets are scanned in the same sequence, until either the target record is found or an unused array slot is found, which indicates an unsuccessful search.

Well known probe sequence includes:

- **Linear probing**, in which the interval between probes is fixed.

- **Quadratic probing**, in which the interval between probes is increased by adding the successive outputs of a quadratic polynomial to the value given by the original hash computation.

- **Double hashing**, in which the interval between probes is computed by a secondary hash function.

The performance of open addressing may be slower compared to separate chaining since the probe sequence increases when the load factor `α` approaches 1. However, open addressing is more cache friendly than separate chaining. Since the slots are located in successive locations, linear probing could lead to better utilization of CPU cache due to locality of references resulting in reduced memory latency.


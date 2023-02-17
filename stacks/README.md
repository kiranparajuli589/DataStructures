# Stacks

## Introduction
In computer science, a stack is an abstract data type that serves as a linear collection of elements. The order in which an element added to or removed from a stack is described as **Last in First Out (LIFO)**. As a stack of physical objects, this structure makes it easy to take an item off the top of the stack, but accessing a datum deeper in the stack may require taking off multiple other items first.

## Operations
Two main operation involved with the stack are:

- **Push**, which adds an element to the top of the collection
- **Pop**, which removes the most recently added element that wwwas not yet removed

It is considered as *linear data structure* or more abstractly a sequential collection as the push and pop operations occur only at one end of the structure, referred to as *the top* of the stack.

Other non essential operations can be:

- **Peek**, which return the value of the last element added without modifying the stack
- **isEmpty**, which return true if the stack is empty, false otherwise
- **isFull**, which return true if the stack is full, false otherwise
- **display**, which display the full content of the stack

## Implementation
The stack can be implemented easily either through an array or a linked list, as stacks are just special cases of lists. What identifies the data structure as a stack, in either case, is not the implementation but the way the data is accessed.

### [Array implementation](https://github.com/kiranparajuli589/DataStructures/blob/main/stacks/array_stack.cpp "Array implementation")
The array implementation is the simplest one, as it is just a matter of keeping track of the top of the stack. The top of the stack is the last element added to the stack. The stack is empty when the top is equal to -1. The stack is full when the top is equal to the size of the array minus one.

#### Advantages
- Easy to implement
- Memory efficient as the stack size is fixed and pointers are not involved.

#### Disadvantages
- The stack is not dynamic and can only hold a fixed number of elements.
- The stack size must be specified in advance.

### [Linked list implementation](https://github.com/kiranparajuli589/DataStructures/blob/main/stacks/ll_stack.cpp "Linked list implementation")
Another option for implementing stacks is to use a singly linked list. A stack is then a pointer to the "head" of the list. The top of the stack is the head of the list. The stack is empty when the head is NULL. The stack is full when the memory is full.

#### Advantages
- The stack is dynamic and can grow and shrink according to the needs of the program.
- It can be used in many virtual machine implementations.

#### Disadvantages
- It is not memory efficient as pointers are involved.
- It is not cache friendly as the memory locations are not contiguous.

### Time complexity
The time complexity of the operations is the following:

| Operation | Time complexity |
|-----------|-----------------|
| Push      | O(1)            |
| Pop       | O(1)            |
| Peek      | O(1)            |
| isEmpty   | O(1)            |
| isFull    | O(1)            |
| display   | O(n)            |


## Advantages
- Stacks are used to reverse a word or a sentence.
- Infix to Postfix /Prefix conversion.
- Redo-undo features at many places like editors, photoshop.
- Forward and backward feature in web browsers.
- Backtracking is one of the algorithm designing techniques. It is used in solving problems like mazes, n-queen, rat in a maze, etc.
- In memory management, any modern computer uses a stack as the primary memory management technique.
- Stacks also helps in implementing function calls in programming languages.

## References
- [Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type) "Wikipedia")
- [GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/ "GeeksforGeeks")


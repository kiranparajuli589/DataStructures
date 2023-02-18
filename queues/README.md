# Queue

## Introduction
In computer science, a queue is a collection of entities that are maintained in a sequence and can be modified by the addition of entities at one end of the sequence and the removal of entities from the other end of the sequence. By convention, the end of the sequence at which elements are added is called the back, tail, or rear of the queue, and the end at which elements are removed is called the head or front of the queue, analogously to the words used when people line up to wait for goods or services. This makes the queue a First-In-First-Out (FIFO) data structure.

## Operations
The queue data structure supports the following operations:
- **Enqueue**, which adds an element to the end of the queue.
- **Dequeue**, which removes the element from the front of the queue and returns it.
- **Peek**, which returns the front element without removing it.
- **IsEmpty**, which checks if the queue is empty.
- **Clear**, which removes all elements from the queue.
- **Count**, which returns the number of elements in the queue.


## Implementations
Theoretically, one characteristic of a queue is that it does not have a specific capacity. Regardless of how many elements are already contained, a new element can always be added. It can also be empty, at which point removing an element will be impossible until a new element has been added. Queue *overflow* results from trying to add an element onto a full queue and queue *underflow* happens when trying to remove an element from an empty queue. There are several implementations of FIFO queues. An efficient implementation is one that can perform the operations: en-queuing and de-queuing in O(1) time.

### Array Implementation
Fixed-length arrays are limited in capacity, but it is not true that items need to be copied towards the head of the queue. The simple trick of turning the array into a closed circle and letting the head and tail drift around endlessly in that circle makes it unnecessary to ever move items stored in the array. If *n* is the size of the array, then computing indices modulo *n* will turn the array into a circle. This is still conceptually the simplest way to construct a queue in a high level language, but it does admittedly slow things down a little, because the array indices must be compared to zero and the array size, which is comparable to the time taken to check whether an array index is out of bounds, which some languages do, but this will certainly be the method of choice for a quick and dirty implementation, or for any high-level languages that does not have pointer syntax.

The array size must be declared ahead of time, but some implementations simply double the declared array size when overflow occurs. Most modern languages with objects or pointers can implement or come with libraries for dynamic lists. Such data structures may have not specified a fixed capacity limit besides memory constraints.

### Linked list Implementations
- A regular **singly linked list** only has efficient insertion and deletion at one end. However, a small modification -- keeping a pointer to the last node in addition to the first one -- will enable it to implement an efficient queue.
- A **doubly linked list** has O(1) insertion and deletion at both ends, so it is a natural choice for queues.

### DeQue Implementation
A **DeQue (double-ended queue)** implemented using a modified dynamic array where elements can be added to or removed from either the front or back.

## Types of Queue
Some most common types of queues used in computer sciences are:

1. Linear Queue: A linear queue is a simple queue where the elements are stored in a linear data structure, such as an array or linked list. In a linear queue, elements are added at the back and removed from the front.

2. Circular Queue: A circular queue is a variation of the linear queue where the front and rear pointers wrap around to the beginning of the queue when they reach the end. This allows for efficient use of space and avoids wasting memory.

3. Priority Queue: A priority queue is a type of queue where each element is assigned a priority and the elements with higher priority are dequeued first. Priority queues are used in many applications, such as scheduling algorithms and network routing.

4. Double-ended Queue (DeQue): A double ended queue is a data structure that allows elements to be added or removed from either end. It can be used as both a queue and a stack.

## Applications
- **CPU Scheduling**: In operating systems, a queue is used to hold the processes that are ready to execute. The operating system selects the process to be executed from the queue based on a scheduling algorithm. The process is then removed from the queue and executed. When the process is finished, it is removed from the CPU and a new process is selected from the queue.
- **Network Packet Routing**: In computer networks, queues are used to manage the flow of packets between network devices. Packets are added to the queue when they arrive at the device and are removed from the queue when they are sent to the next device.
- **Event Handling**: In event-driven programming, queues are used to manage the flow of events (such as clicks or keyboard presses) between different components of a program. Events are added to the queue when they occur and are removed from the queue when they are handled by the program.
- **Simulation**: In simulation, queues are used to manage the flow of entities (such as customers or cars) through a system. Entities are added to the queue when they arrive at the system and are removed from the queue when they leave the system.
- **Customer Service**: In call centers or other customer service environments, queues are used to manage the flow of customers through the system. Customers are added to the queue when they arrive at the system and are removed from the queue when they are served by an agent.

These are just a few examples of the many applications of queues. Queues are a versatile data structure that can be used in a variety of contexts where it is necessary to manage the order in which items are processed.

## Time Complexity
### Array, LinkedList, DeQue Implementation
| Operation | Time Complexity |
|-----------|-----------------|
| Enqueue   | O(1)            |
| Dequeue   | O(1)            |
| Peek      | O(1)            |
| IsEmpty   | O(1)            |
| Clear     | O(1)            |
| Count     | O(1)            |
## Priority Queue Implementation
| Operation | Time Complexity |
|-----------|-----------------|
| Enqueue   | O(n)            |
| Dequeue   | O(1)            |
| Peek      | O(1)            |
| IsEmpty   | O(1)            |
| Clear     | O(1)            |
| Count     | O(1)            |

## References
- [Wikipedia](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
- [GeeksforGeeks](https://www.geeksforgeeks.org/queue-data-structure/)

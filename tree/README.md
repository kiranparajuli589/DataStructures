# Tree
A **tree** is a type of abstract data structure that is used to represent hierarchical relationships between objects or data in a way that is easy to navigate and search. It is a collection of *nodes* that are connected by *edges*. Each node contains a value and a set of references to its child nodes. Because of this type of data storing technique, it is considered as a non-linear data structure.

Trees are commonly used in a wide range of applications such as file systems, network routing, compiler parsing, and database indexing. They offer efficient access to data because the search or retrieval time is proportional to the height of the tree rather than the size of the data set. Trees also provide a natural way to represent nested structures, such as XML documents or HTML web pages.

```
        A
       / \
      B   C
     / \   \
    D   E   F
```
Fig: A simple tree data structure

## Basic Terminologies
Here are some basic terms that are commonly used in tree data structures:

* **Node**: A node is a basic unit of a tree data structure. It is a data structure that contains a value and a reference to its child nodes.**{A, B, C, D, E, F}** are all nodes in the above tree.
* **Edge**: An edge is a connection between two nodes. In the above tree, **A** is connected to **B** and **C** by edges. The edges are also called links or branches.
* **Parent Node**: A node which is a predecessor of another node is called its parent node. In the above tree, **A** is the parent of **B** and **C**.
* **Child Node**: A node which is a successor of another node is called its child node. In the above tree, **B** and **C** are the children of **A**.
* **Root Node**: The topmost node in a tree is called the root node. It is the only node in the tree that does not have a parent node. In the above tree, **A** is the root node.
* **Leaf Node**: A node that does not have any child node is called a leaf node. In the above tree, **D**, **E**, and **F** are all leaf nodes.
* **Ancestor Node**: Any predecessor nodes on the path of the root to that node are called ancestor nodes. In the above tree, **A** and **B** are the ancestors of **D**.
* **Descendant Node**: Any node that is reachable from a given node by following its edges or links in a downward direction is called a descendant node. In the above tree, **D** and **E** are the descendants of **B**.
* **Sibling Node**: Nodes that have the same parent are called sibling nodes. In the above tree, **B** and **C** are the siblings of each other.
* **Internal Node**: All nodes except for leaf nodes and the root node. In the above tree, **B**, and **C** are the internal nodes.
* **Subtree**: A subtree is a set of nodes and edges of a tree that includes a parent node and all of its descendants. In the above tree, the subtree rooted at **B** consists of **B**, **D**, and **E**.

## Properties of a Tree
1. **Nodes**: A tree is composed of a set of nodes, each of which stores a value and a reference to its child nodes.
2. **Edges**: The nodes are connected by edges. Each edge connects two nodes, one of which is the parent node and the other is the child node.
3. **Root**: The root is the only node in the tree that does not have a parent node.
4. **Path**: A path is a sequence of nodes and edges connecting a node with a descendant.
5. **Depth**: The depth of a node is the number of edges on the path from the root node to that node.
6. **Height**: The height of a tree is the number of edges on the longest path from the root node to any leaf node.
7. **Degree of a Node**: The total count of child nodes of a node is called the degree of that node.
8. **Binary Tree**: A binary tree is a tree in which each node has at most two children. The left child is called the left subtree and the right child is called the right subtree.
9. **Ordered Tree**: An ordered tree is a tree in which the children of each node are ordered in some way. For example, a binary search tree is an ordered tree in which the left child is less than the parent node and the right child is greater than the parent node.
10. **Balanced Tree**: A balanced tree is a tree in which the difference between the height of the left subtree and the height of the right subtree is not more than one. A balanced tree is also called an AVL tree.
11. **Binary Search Tree**: A binary search tree is a binary tree in which the left child is less than the parent node and the right child is greater than the parent node.
12. **Successor**: The successor of a node is the node with the smallest key greater than the node. It appears immediately after the given node in an in-order traversal of the tree. 
13. **Predecessor**: The predecessor of a node is the node with the greatest key smaller than the node. It appears immediately before the given node in an in-order traversal of the tree.

## Binary Tree
A binary tree is a type of tree data structure in which each node has at most two children, referred to as the left child and the right child. Each node in a binary tree stores a value or key, and may also have additional attributes such as pointers to its parent or child nodes.

### Operations

The operations that can be performed on a binary tree are:

1. **Insertion**: The insertion operation adds a new node with a given value to the tree. To insert a node in a binary tree, we start at the root node and compare the new value with the value of the current node. If the new value is smaller than the current node's value, we move to its left child, and if it is greater, we move to its right child. We repeat this process until we reach an empty node, and then we insert the new node there.
2. **Traversal**: The traversal operation visits all nodes in the tree in a specific order. There are three common methods for traversing a binary tree:
   1. In-order traversal: In this traversal method, we first visit the left child, then the current node, and finally the right child. This method is also called the left-root-right traversal method.
   2. Pre-order traversal: In this traversal method, we first visit the current node, then the left child, and finally the right child. This method is also called the root-left-right traversal method.
   3. Post-order traversal: In this traversal method, we first visit the left child, then the right child, and finally the current node. This method is also called the left-right-root traversal method.
3. **Search**: The search operation finds a node with a given value in the tree. To search for a node in a binary tree, we start at the root node and compare the search value with the value of the current node. If the search value is smaller than the current node's value, we move to it's left child, and if it is greater, we move to its right child. We repeat this process until we either find the node with the given value or reach an empty node.
4. **Deletion**: The deletion operation removes a node with a given value from the tree. There are several cases to consider when deleting a node, depending on whether it has zero, one or two children. In the case of a node with zero children, we simply remove it from the tree. In the case of a node with one child, we replace it with its child. If the node has two children, we replace the node to be deleted with the deepest node in the left (or right) subtree.

### Types:
#### Full Binary Tree
A full binary tree is a special type of Binary tree in which every node has either zero or two children.

```
      A
     / \
    B   C
   / \
  D   E
```
#### Perfect Binary Tree
A perfect binary tree is a special type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.

```
       A
     /   \
    B     C
   / \   / \
  D   E F   G
```
#### Complete Binary Tree
A complete binary tree is a special type of binary tree in which every level, except possibly the last, is completely filled, and the nodes are filled from left to right.

In complete binary tree:
- Every level except the last level is completely filled.
- All the nodes are as far left as possible.

```
       A
     /   \
    B     C
   / \   /
  D   E F
```

#### Balanced Binary Tree
A balanced binary tree is a special type of binary tree in which the difference between the height of the left subtree and the height of the right subtree is not more than one.

In a balanced binary tree:
- The absolute difference of the height of the left subtree and the height of the right subtree is less than or equal to 1.
- For each node, its left subtree and right subtree are also balanced binary trees.

Balanced binary trees are also called AVL trees or Height-balanced Binary trees. 

```
       A
     /   \
    B     C
   / \   / \
  D   E F   G
```

```
       A
     /   \
    B     C
   / \   / \
  D   E F   G
```

```
       A
     /   \
    B     C
   / \   / \
  D   E F   G
```

## Binary Search Tree

A binary search tree is a binary tree in which the left child is less than the parent node and the right child is greater than the parent node. In a binary search tree, the left subtree of a node contains only nodes with keys less than the node's key, and the right subtree of a node contains only nodes with keys greater than the node's key. The left and right subtree each must also be a binary search tree.

### Operations

The operations that can be performed on a binary search tree are:

1. **Insertion**: The insertion operation adds a new node with a given value to the tree. To insert a node in a binary search tree, we start at the root node and compare the new value with the value of the current node. If the new value is smaller than the current node's value, we move to its left child, and if it is greater, we move to its right child. We repeat this process until we reach an empty node, and then we insert the new node there.

2. **Traversal**: The traversal operation visits all nodes in the tree in a specific order. There are three common methods for traversing a binary search tree:
   1. In-order traversal: In this traversal method, we first visit the left child, then the current node, and finally the right child. This method is also called the left-root-right traversal method.
   2. Pre-order traversal: In this traversal method, we first visit the current node, then the left child, and finally the right child. This method is also called the root-left-right traversal method.
   3. Post-order traversal: In this traversal method, we first visit the left child, then the right child, and finally the current node. This method is also called the left-right-root traversal method.

3. **Search**: The search operation finds a node with a given value in the tree. To search for a node in a binary search tree, we start at the root node and compare the search value with the value of the current node. If the search value is smaller than the current node's value, we move to it's left child, and if it is greater, we move to its right child. We repeat this process until we either find the node with the given value or reach an empty node.

4. **Deletion**:
    Deletion of a node, say `D` from a BST should abide the following three cases:

    1. If the node to be deleted is a leaf node, the parent node's pointer to `D` gets replaced with `NULL`.

    2. If the node has a single child node, the child gets elevated as either left or right child of the `D`'s parent depending on the position of `D` in the tree.

    3. If the node has both a left and a right child, then find the minimum value in the right subtree of the node to be deleted. Replace the value of the node to be deleted with the minimum value. Delete the node with the minimum value in the right subtree which must be a leaf node.

## B-Tree

A B-tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. The B-tree is a generalization of a binary search tree in that a node can have more than two children. Unlike self-balancing binary search trees, the B-tree is optimized for systems that read and write large blocks of data. It is commonly used in databases and file systems.

### Properties
1. Every node has at most `m` children.
2. Every internal node has at least of `m/2` children.
3. Every non-leaf node has at least two children.
4. All leaves appear on the same level.
5. A non-leaf node with `k` children contains `k-1` keys.


### Operations

The operations that can be performed on a B-tree are:

1. **Insertion**:

All insertions start at a leaf node.

- Search the tree to find the leaf node where the new element should be added. Insert the new element into that node with the following steps

- If the node contains less than the maximum allowed number of elements, then there is room for the new element. Insert the new element into the node, keeping the node's elements ordered.

- Otherwise, the node is full. Evenly split it into two nodes so:

    - A single median is chosen from among the leaf's elements and the new element that is being inserted

    - Values less than the median are put in the new left node and values greater than the median are put in the new right node, with the median acting as a separation value.

    - The separation value is inserted in node's parent, which may cause it to be split, and so on. If the node has no parent (i.e. the node was the root), create a new root above this node (increasing the height of the tree).

If the splitting goes all the way up to the root, it creates a new root with a single separator value and two children, which is why the lower bound on the size of internal does not apply to the root.

2. **Deletion**:

Strategy:
- locate the item
- delete the item
- restructure the tree to retain its invariants

There are two special cases to consider when deleting an item from a B-tree:

1. The element in an internal node is a separator for its child nodes.
2. Deleting an element may put its node under the minimum number of elements and children.

*Case 1:* Deletion from a leaf node
- Search for the value to delete.
- If the value is in a leaf node, simply delete it from the node.
- If underflow happens, re-balance the tree

**Case 2:* Deletion from an internal node

Each element in an internal node acts as a separation value for two subtrees, therefore we need to find a replacement for separation. Note that the largest element in the left subtree is still less than the separator. Likewise, the smallest element in the right subtree is still greater than the separator. Both of those elements are in leaf nodes, and either one can be the new separator from the two subtrees.

- Choose a new separator (either the largest element in the left subtree of the smallest element in the right subtree), remove it from the leaf node, and replace the element to be deleted with the new separator.

- The previous step deleted an element (the new separator) from a leaf node. If that leaf node is now deficient (has fewer than the required number of nodes), then re-balance the tree.

**Re-balancing the tree**

Re-balancing starts from a leaf and proceeds towards the root until the tree is balanced again. If deleting an element from a node has brought it under the minimum size, then some elements must be redistributed to bring all nodes up to the minimum.

Usually, the redistribution involves moving an element from a sibling node that has more than the minimum number of nodes. The redistribution operation is called a rotation. If no sibling can spare an element, then the deficient node must be merged with a sibling node.

The merge causes the parent to lose a separator element, so the parent may become deficient. If the parent is deficient, then the merge operation is performed on the parent node. This process continues until the root is reached. Since the minimum element count doesn't apply to the root, making the root be the only deficient node is not a problem.

The algorithm for redistributing elements is as follows:

- If the deficient node's right sibling exists and has more than the minimum number of elements, then rotate left.
    - Copy the separator from the parent to the end of the deficient node (the separator moves down; the deficient now has the minimum number of elements).
    - Replace the separator in the parent with the first element of the right sibling (right sibling loses one node but still has at least the minimum number of elements).
    - The tree is now balanced.
- Otherwise, if the deficient node's left sibling exists and has more than the minimum number of elements, then rotate right.
    - Copy the separator from the parent to the beginning of the deficient node (the separator moves down; the deficient now has the minimum number of elements).
    - Replace the separator in the parent with the last element of the left sibling (left sibling loses one node but still has at least the minimum number of elements).
    - The tree is now balanced.
  - Otherwise, if both immediate siblings have only the minimum number of elements then merge with a sibling sandwiching their separator taken off from their parent.
    - Copy the separator to the end of the left node (the left node may be the deficient node or it may be the sibling with the minimum number of elements).
    - Move all elements from the right node to the left node (the left node now has the maximum number of elements, and the right node - empty).
    - Remove the separator from the parent along with its empty right child (the parent loses an element)
      - If the parent is the root and now has no elements, then free it and make the merged node the new root (tree becomes shallower).
      - Otherwise, if the parent has fewer than the required number of elements, then re-balance the parent.




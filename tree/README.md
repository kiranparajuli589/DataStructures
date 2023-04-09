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
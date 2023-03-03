#include <iostream>

using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int value) {
            left = nullptr;
            right = nullptr;
            data = value;
        }
};

class BinaryTree {
    public:
        TreeNode *root;
 
        BinaryTree() {
            root = nullptr;
        } // constructor

        // operation prototypes
        void insertNode(int);
        void inOrderTraversal(TreeNode*);
        void preOrderTraversal(TreeNode*);
        void postOrderTraversal(TreeNode*);
        bool search(int);
        bool deleteNode(int);
        TreeNode *findMin(TreeNode*);
};

void BinaryTree::insertNode(int value) {
    TreeNode *newNode = new TreeNode(value);
    if (root == nullptr) {
        root = newNode;
    } else {
        TreeNode *curr = root;
        while(true) {
            // If the new value is smaller than the current node's value
            if (value < curr->data) {
                // If the left node is empty then, we set it to the new value
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    break;
                }
                // Otherwise, we keep looking to the left side
                else {
                    curr = curr->left;
                }
            }
            // Otherwise, we move to its right child
            else {
                // If the right node is empty, then we set it to the new value
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    break;
                }
                // Otherwise, we keep looking to the right side
                else {
                    curr = curr->right;
                }
            }
        }    
    }
}

void BinaryTree::inOrderTraversal(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    // Recursively call for the left subtree
    inOrderTraversal(node->left);
    // Print the current node's value (root)
    cout << node->data << " ";
    // Recursively call for the right subtree
    inOrderTraversal(node->right);
}

void BinaryTree::preOrderTraversal(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    // Print the current node's value (root)
    cout << node->data << " ";
    // Recursively call for the left subtree
    preOrderTraversal(node->left);
    // Recursively call for the right subtree
    preOrderTraversal(node->right);
}

void BinaryTree::postOrderTraversal(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    // Recursively call for the left subtree
    postOrderTraversal(node->left);
    // Recursively call for the right subtree
    postOrderTraversal(node->right);
    // Print the current node's value (root)
    cout << node->data << " ";
}

bool BinaryTree::search(int value) {
    TreeNode *curr = root;
    while (curr != nullptr) {
        // If the value is found, then we return true
        if(curr->data == value) {
            return true;
        }
        // Otherwise, we move to its left or right child depending on the value
        // If the value is smaller than the current node's value, then we move to its left child
        else if (value < curr->data) {
            curr = curr->left;
        }
        // Otherwise, we move to its right child
        else {
            curr = curr->right;
        }
    }
    // If the value is not found, then we return false
    return false;
}

TreeNode *BinaryTree::findMin(TreeNode *node) {
    // If the tree is empty, then we return nullptr
    if (node == nullptr) {
        return nullptr;
    }
    // If the left child is empty, then the current node is the minimum
    if (node->left == nullptr) {
        return node;
    }
    // Otherwise, we keep looking to the left side
    return findMin(node->left);
}


bool BinaryTree::deleteNode(int value) {
    // Algorithm:
    // 1. Find the node to be deleted
    // 2. If the node is not found, then return false
    // 3. If the node has no children, then delete it and return true
    // 4. If the node has one child, then replace it with its child and return true
    // 5. If the node has two children,
    //    a. Find the minimum value in the right subtree
    //    b. Replace the node's value with the minimum value
    //    c. Recursively delete the node with the minimum value in the right subtree
    //    d. Return true
    //    Note: We can also find the maximum value in the left subtree and replace the node's value with it
    //    Note: We replace the value of the node to be deleted with the value of the minimum (or maximum) node
    //          in the right (or left) subtree, instead of actually moving the node. This is because moving the
    //          node could change the structure of the tree and break the binary tree property.

    // If the tree is empty, then we return false
    if (root == nullptr) {
        return false;
    }

    // Check if the node to be deleted exists in the tree
    if (!search(value)) {
        return false;
    }

    // Find the node to be deleted
    TreeNode *nodeToDelete = root;
    while(nodeToDelete->data != value) {
        // If the value is smaller than the current node's value, then we move to its left child
        if (value < nodeToDelete->data) {
            nodeToDelete = nodeToDelete->left;
        }
        // Otherwise, we move to its right child
        else {
            nodeToDelete = nodeToDelete->right;
        }
    }

    // If the node to be deleted has no children, then we delete it and return true
    if (nodeToDelete->left == nullptr && nodeToDelete->right == nullptr) {
        delete nodeToDelete;
        return true;
    }

    // If the node to be deleted has one child, then we replace it with its child and return true
    if (nodeToDelete->left == nullptr) {
        TreeNode *temp = nodeToDelete;
        nodeToDelete = nodeToDelete->right;
        delete temp;
        return true;
    }
    if (nodeToDelete->right == nullptr) {
        TreeNode *temp = nodeToDelete;
        nodeToDelete = nodeToDelete->left;
        delete temp;
        return true;
    }

    // If the node to be deleted has two children, then we find the minimum value in the right subtree
    // and replace the node's value with the minimum value

    // Find the minimum value in the right subtree
    TreeNode *minNode = findMin(nodeToDelete->right);

    // Replace the node's value with the minimum value
    nodeToDelete->data = minNode->data;

    // Recursively delete the node with the minimum value in the right subtree
    nodeToDelete->right = deleteNode(nodeToDelete->data);
}


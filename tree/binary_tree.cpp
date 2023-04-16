#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

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
        void inOrderTraversal(TreeNode*);
        void preOrderTraversal(TreeNode*);
        void postOrderTraversal(TreeNode*);
        TreeNode* search(int);
        TreeNode* deleteNode(int);
        void deleteDeepest(TreeNode*, TreeNode*);
        void display(TreeNode*, string, bool);
        int getTreeHeight(TreeNode*);
};

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

TreeNode* BinaryTree::search(int value) {
    TreeNode *curr = root;
    while (curr != nullptr) {
        // If the value is found, then we return true
        if(curr->data == value) {
            return curr;
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
    return nullptr;
}


TreeNode* BinaryTree::deleteNode(int value) {
    // if the tree is an empty one, then:
    if (root == nullptr) {
        return nullptr;
    }
    // if three tree has root only, then:
    if(root->left == nullptr && root->right == nullptr) {
        if (root->data == value){
            root = nullptr;
            return root;
        } else {
            return nullptr;
        }
    }
    // if the tree has more than 1 levels:
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode *lastNode = nullptr;
    TreeNode *nodeToDelete = nullptr;
    while (!q.empty()) {
        lastNode = q.front();
        q.pop();
        if(lastNode->data == value) {
            nodeToDelete = lastNode;
        }
        if(lastNode->left) {
            q.push(lastNode->left);
        }
        if(lastNode->right) {
            q.push(lastNode->right);
        }
    }
    // if no key is found, then:
    if(!nodeToDelete) {
        return nullptr;
    }
    nodeToDelete->data = lastNode->data;
    deleteDeepest(root, lastNode);
    return lastNode;
}

void BinaryTree::deleteDeepest(TreeNode *root, TreeNode *node) {
    if (root == nullptr) {
        return;
    }
    if(root == node && root->left == nullptr && root->right == nullptr) {
        delete node;
        root = nullptr;
        return;
    }
    if(root->left == node) {
        delete node;
        root->left = nullptr;
        return;
    }
    if(root->right == node) {
        delete node;
        root->right = nullptr;
        return;
    }
    deleteDeepest(root->left, node);
    deleteDeepest(root->right, node);
}

void BinaryTree::display(TreeNode *node, string prefix = "", bool isLeft = true) {
   if (node != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──(l) [" : "└──(r) [");
        cout << node->data << "]" << endl;
        display(node->left, prefix + (isLeft ? "│   " : "    "), true);
        display(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

int BinaryTree::getTreeHeight(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getTreeHeight(node->left);
    int rightHeight = getTreeHeight(node->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    BinaryTree btree;
    btree.root = new TreeNode(10);
    btree.root->left = new TreeNode(5);
    btree.root->right = new TreeNode(15);
    btree.root->left->left = new TreeNode(2);
    btree.root->left->right = new TreeNode(7);
    btree.root->right->left = new TreeNode(12);
    btree.root->right->right = new TreeNode(17);
    btree.root->left->left->left = new TreeNode(1);
    btree.root->left->left->right = new TreeNode(3);

    btree.preOrderTraversal(btree.root);
    cout << endl;
    btree.inOrderTraversal(btree.root);
    cout << endl;
    btree.postOrderTraversal(btree.root);
    cout << endl;
    btree.display(btree.root);
    btree.deleteNode(2);
    cout << endl;
    btree.display(btree.root);
}


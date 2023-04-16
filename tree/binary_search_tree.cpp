#include<iostream>
#include<map>

using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
    
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
    public:
        TreeNode *root;

        BST() {
            root = nullptr;
        }

        void insert(int);
        void inOrderTraversal(TreeNode*);
        void preOrderTraversal(TreeNode*);
        void postOrderTraversal(TreeNode*);
        map<string, TreeNode*> search(int);
        TreeNode* deleteNode(int);
        void display(TreeNode*, string, bool);
        int getTreeHeight(TreeNode*);
        TreeNode* successor(TreeNode*);
        TreeNode* predecessor(TreeNode*);
        TreeNode* getRightMostNode(TreeNode*);
        TreeNode* getLeftMostNode(TreeNode*);
};

void BST::preOrderTraversal(TreeNode *node = NULL) {
    if (node == nullptr) {
        return;
    }
    if (node == NULL) {
        node = root;
    }
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void BST::inOrderTraversal(TreeNode *node = NULL) {
    if (node == nullptr) {
        return;
    }
    if (node == NULL) {
        node = root;
    }
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

void BST::postOrderTraversal(TreeNode *node = NULL) {
    if (node == nullptr) {
        return;
    }
    if (node == NULL) {
        node = root;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}

void BST::insert(int value) {
    TreeNode *newNode = new TreeNode(value);

    TreeNode *curr = root;
    TreeNode *final = nullptr;

    while(curr != nullptr) {
        final = curr;
        if (value < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (final == nullptr) {
        root = newNode;
    } else if (value < final->data) {
        final->left = newNode;
    } else {
        final->right = newNode;
    }
}

map<string, TreeNode*> BST::search(int target) {
    map<string, TreeNode*> result;
    TreeNode *curr = root;
    TreeNode *parent = nullptr;
    while(curr != nullptr) {
        if (curr->data == target) {
            result["parent"] = parent;
            result["node"] = curr;
            return result;
        } else if (target < curr->data) {
            parent = curr;
            curr = curr->left;
        } else {
            parent = curr;
            curr = curr->right;
        }
    }
    return result;
}

TreeNode* BST::getRightMostNode(TreeNode *node = NULL) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node == NULL) {
        node = root;
    }
    while(node->right != nullptr) {
        node = node->right;
    }
    return node;
}

TreeNode* BST::getLeftMostNode(TreeNode *node = NULL) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node == NULL) {
        node = root;
    }
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/**
 * @brief Returns the node with the minimum value but
 * greater than the value of the given node
*/
TreeNode* BST::successor(TreeNode *node = NULL) {
    if (node == NULL) {
        node = root;
    }
    if (node->right != nullptr) {
        return getLeftMostNode(node->right);
    }
    return nullptr;
}

/**
 * @brief Returns the node with the maximum value but
 * smaller than the value of the given node
*/
TreeNode* BST::predecessor(TreeNode *node = NULL) {
    if (node == NULL) {
        node = root;
    }
    if (node->left != nullptr) {
        return getRightMostNode(node->left);
    }
    return nullptr;
}

TreeNode* BST::deleteNode(int target) {
    // Search for the target node
    map<string, TreeNode*>result = search(target);
    TreeNode *targetNode = result["node"];
    TreeNode *parentNode = result["parent"];

    if (targetNode == nullptr) {
        return nullptr;
    }

    // Check if the target node is a leaf node
    if (targetNode->left == nullptr && targetNode->right == nullptr) {
        if(parentNode == nullptr) {
            root = nullptr;
        } else {
            if (parentNode->left == targetNode) {
                parentNode->left = nullptr;
            } else {
                parentNode->right = nullptr;
            }
        }
    }

    // Check if the target node has both left and right child
    else if (targetNode->left != nullptr && targetNode->right != nullptr) {
        // Replace the target node with its successor node
        TreeNode *successorNode = successor(targetNode);
        int temp = successorNode->data;
        deleteNode(successorNode->data);
        targetNode->data = temp;
    }

    // Check if the target node has only one child
    else {
        TreeNode *childNode = (targetNode->left != nullptr) ? targetNode->left : targetNode->right;
        if (parentNode == nullptr) {
            root = childNode;
        } else {
            if (parentNode->left == targetNode) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
        }
    }

    return targetNode;
}

void BST::display(TreeNode *node, string prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──(l) [" : "└──(r) [");
        cout << node->data << "]" << endl;
        display(node->left, prefix + (isLeft ? "│   " : "    "), true);
        display(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

int BST::getTreeHeight(TreeNode *node = NULL) {
    if (node == nullptr) {
        return 0;
    }
    if (node == NULL) {
        node = root;
    }
    int leftHeight = getTreeHeight(node->left);
    int rightHeight = getTreeHeight(node->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);
    bst.insert(7);
    bst.insert(12);
    bst.insert(17);

    cout << "Pre-order traversal: ";
    bst.preOrderTraversal();
    cout << endl;

    cout << "In-order traversal: ";
    bst.inOrderTraversal();
    cout << endl;

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();
    cout << endl;

    bst.display(bst.root);

    cout << "Deleting 17..." << endl;
    bst.deleteNode(17);
        cout << "Pre-order traversal: ";
    bst.preOrderTraversal();
    cout << endl;

    cout << "In-order traversal: ";
    bst.inOrderTraversal();
    cout << endl;

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();
    cout << endl;
    bst.display(bst.root);

    cout << "Deleting 10..." << endl;
    bst.deleteNode(10);
    cout << "Pre-order traversal: ";
    bst.preOrderTraversal();
    cout << endl;

    cout << "In-order traversal: ";
    bst.inOrderTraversal();
    cout << endl;

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();
    cout << endl;
    bst.display(bst.root);

    return 0;
}

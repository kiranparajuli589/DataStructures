#include<iostream>

using namespace std;

class TreeNode {
    public:
        /**
         * d: minimum degree
         * n: number of keys
         * keys: array of keys
         * child: array of child pointers
        */
        bool leaf;
        int d, n, *keys;
        TreeNode **child;

        TreeNode(int degree, bool isLeaf) {
            n = 0;
            d = degree;
            leaf = isLeaf;
            // Allocate memory for maximum number of possible keys and child pointers
            keys = new int[2*d-1];
            child = new TreeNode*[2*d];
        }

        TreeNode* search(int);
        void traverse();
        void insertNonFull(int);
        void splitChild(int, TreeNode*);

        friend class BTree;
};

class BTree {
    public:
        TreeNode *root;
        int d;
        BTree(int degree) {
            root = nullptr;
            d = degree;
        }

        void traverse();
        TreeNode* search(int);
        void insert(int);
        void remove(int);
};

void BTree::traverse() {
    if (root != nullptr) {
        root->traverse();
    }
}

void TreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        // If this is not a leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if (leaf == false) {
            child[i]->traverse();
        }
        cout << " " << keys[i];
    }
    // Print the subtree rooted with last child
    if (leaf == false) {
        child[i]->traverse();
    }
}

TreeNode* BTree::search(int k) {
    return (root == nullptr) ? nullptr : root->search(k);
}

TreeNode* TreeNode::search(int k) {
    int i = 0;
    // Find the first key greater than or equal to k
    while (i < n && k > keys[i]) {
        i++;
    }
    // If the found key is equal to k, return this node
    if (keys[i] == k) {
        return this;
    }
    // If the key is not found here and this is a leaf node
    if (leaf == true) {
        return nullptr;
    }
    // Otherwise, go to the appropriate child
    return child[i]->search(k);
}

void TreeNode::splitChild(int i, TreeNode *y) {
    // Create a new node which is going to store (d-1) keys
    // of y
    TreeNode *z = new TreeNode(y->d, y->leaf);
    z->n = d - 1;
    // Copy the last (d-1) keys of y to z
    for (int j = 0; j < d-1; j++) {
        z->keys[j] = y->keys[j+d];
    }
    // Copy the last d children of y to z
    if (y->leaf == false) {
        for (int j = 0; j < d; j++) {
            z->child[j] = y->child[j+d];
        }
    }
    // Reduce the number of keys in y
    y->n = d - 1;
    // Since this node is going to have a new child,
    // create space of new child
    for (int j = n; j >= i+1; j--) {
        child[j+1] = child[j];
    }
    // Link the new child to this node
    child[i+1] = z;
    // A key of y will move to this node. Find location of
    // new key and move all greater keys one space ahead
    for (int j = n-1; j >= i; j--) {
        keys[j+1] = keys[j];
    }
    // Copy the middle key of y to this node
    keys[i] = y->keys[d-1];
    // Increment count of keys in this node
    n = n + 1;
}

void TreeNode::insertNonFull(int k) {
    // Initialize index as index of rightmost element
    int i = n-1;
    // If this is a leaf node
    if (leaf == true) {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }
        // Insert the new key at found location
        keys[i+1] = k;
        n = n+1;
    } else {
        // Find the child which is going to have the new key
        while (i >= 0 && keys[i] > k) {
            i--;
        }
        // See if the found child is full
        if (child[i+1]->n == 2*d-1) {
            // If the child is full, then split it
            splitChild(i+1, child[i+1]);
            // After split, the middle key of C[i] goes up and
            // C[i] is splitted into two. See which of the two
            // is going to have the new key
            if (keys[i+1] < k) {
                i++;
            }
        }
        child[i+1]->insertNonFull(k);
    }
}



void BTree::insert(int k) {
    // If tree is empty
    if (root == nullptr) {
        // Allocate memory for root
        root = new TreeNode(d, true);
        root->keys[0] = k; // Insert key
        root->n = 1; // Update number of keys in root
    } else {
        // If root is full, then tree grows in height
        if (root->n == 2*d-1) {
            // Allocate memory for new root
            TreeNode *newRoot = new TreeNode(d, false);
            // Make old root as child of new root
            newRoot->child[0] = root;
            // Split the old root and move 1 key to the new root
            newRoot->splitChild(0, root);
            // New root has two children now. Decide which of the two
            // children is going to have new key
            int i = 0;
            if (newRoot->keys[0] < k) {
                i++;
            }
            newRoot->child[i]->insertNonFull(k);
            // Change root
            root = newRoot;
        } else {
            // If root is not full, call insertNonFull for root
            root->insertNonFull(k);
        }
    }
}
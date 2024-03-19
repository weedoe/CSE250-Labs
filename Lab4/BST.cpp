/****************************************************************************\
 * BST.cpp
 *
 *  Created on: Mar 7 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details: \\TODO
 *  You can add your implementation details here or in the header,
 *  or with the appropriate variable's or function's comments.
 *
\***************************************************************************/

#include "BST.h"
#include <iostream>

using namespace std;

#include <stack>

/** Minimum: Finds and returns the node with the smallest key */
BSTNode *BST::_min(BSTNode *x) {
    //BST Min
    while (x->left != nullptr) {
        x = x->left;
    }
    return x;
}

/**Successor: Returns the node following node x in key order in the whole tree */
BSTNode *BST::_successor(BSTNode *x) {
    //BST Successor
    if (x->right != nullptr) {
        return _min(x->right);
    }
    BSTNode *y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

/** Computes and returns the height of the node x. */
int BST::_height(BSTNode *x) {
    if (x == nullptr) {
        return 0;
    }
    //BST Height
    if (x == nullptr) {
        return -1;
    }
    int leftHeight = _height(x->left);
    int rightHeight = _height(x->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

/** Construct an empty binary search tree. */
BST::BST() {
    //Constructor
    m_root = nullptr;
}

/** Destroy and free up the memory allocated by the binary search tree. */
BST::~BST() {
    //Destructor
    delete m_root;
}

/** Prints all the data from the tree in key order (using _min and _successor).
 *  The output should look like [(3,Hello), (8,RMC), (21,Student)] \n
 */
void BST::printTree() {
    if (m_root == nullptr) {
        cout << "[]";
        return;
    }
    //Prints the tree
    BSTNode *node = _min(m_root);
    while (node != nullptr) {
        cout << "(" << node->key << "," << node->data << "), ";
        node = _successor(node);
    }
}


/** Finds a node with (key) from the tree and returns the associated (data) or NULL if not found. */
BSTNode *BST::search(int key) {
    if (m_root == nullptr) {
        return nullptr;
    }
    //Search tree
    BSTNode *x = m_root;
    while (x != nullptr && key != x->key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

/** Inserts a new node in the tree with given (key, data). */
void BST::insert(int key, const char *data) {
    //Inserts a new node
    auto *z = new BSTNode();
    z->key = key;
    z->data = data;
    BSTNode *y = nullptr;
    BSTNode *x = m_root;
    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        m_root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

/** Deletes a the node with (key) from the tree and returns the associated (data) or NULL if not found. */
const char *BST::remove(int key) {
    //Removes a node
    BSTNode *z = search(key);
    if (z == nullptr) {
        return nullptr;
    }
    if (z->left == nullptr) {
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        transplant(z, z->left);
    } else {
        BSTNode *y = _min(z->right);
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    return reinterpret_cast<const char *>(z);

}


/** Computes and returns the height of the tree. */
int BST::height() {
    //Computes the height of the tree
    return _height(m_root);
}

/** Prints the keys (comma separated) of the tree using an preorder traversal. */
void BST::preOrder() {
    if (m_root == nullptr) {
        cout << "[]";
        return;
    }
    stack<BSTNode *> nodeStack;
    nodeStack.push(m_root);

    while (!nodeStack.empty()) {
        BSTNode *node = nodeStack.top();
        cout << node->key << ", ";
        nodeStack.pop();

        if (node->right) {
            nodeStack.push(node->right);
        }
        if (node->left) {
            nodeStack.push(node->left);
        }
    }
}

/** Prints the keys (comma separated) of the tree using an inorder traversal. */
void BST::inOrder() {
    if (m_root == nullptr) {
        cout << "[]";
        return;
    }
    stack<BSTNode *> nodeStack;
    nodeStack.push(m_root);

    while (!nodeStack.empty()) {
        BSTNode *node = nodeStack.top();
        cout << node->key << ", ";
        nodeStack.pop();

        if (node->right) {
            nodeStack.push(node->right);
        }
        if (node->left) {
            nodeStack.push(node->left);
        }
    }
}

/** Prints the keys (comma separated) of the tree using an postorder traversal. */
void BST::postOrder() {
    if (m_root == nullptr) {
        cout << "[]";
        return;
    }
    stack<BSTNode *> nodeStack;
    nodeStack.push(m_root);

    while (!nodeStack.empty()) {
        BSTNode *node = nodeStack.top();
        cout << node->key << ", ";
        nodeStack.pop();

        if (node->right) {
            nodeStack.push(node->right);
        }
        if (node->left) {
            nodeStack.push(node->left);
        }
    }
}


/** Transplant */
void BST::transplant(BSTNode *u, BSTNode *v) {
    if (u->parent == nullptr) {
        m_root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}



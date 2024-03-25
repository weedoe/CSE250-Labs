/****************************************************************************\
 * BST.cpp
 *
 *  Created on: Mar 7 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details:
 *  BST.cpp contains the implementation of the BST class. It contains the implementation of the methods defined in BST.h
 *  _min: Finds and returns the node with the smallest key
 *  _successor: Returns the node following node x in key order in the whole tree
 *  _height: Computes and returns the height of the node x
 *  BST: Constructor
 *  ~BST: Destructor
 *  printTree: Prints all the data from the tree in key order (using _min and _successor)
 *  search: Finds a node with (key) from the tree and returns the associated (data) or NULL if not found
 *  insert: Inserts a new node in the tree with given (key, data)
 *  remove: Deletes a the node with (key) from the tree and returns the associated (data) or NULL if not found
 *  height: Computes and returns the height of the tree
 *  preOrder: Prints the keys (comma separated) of the tree using an preorder traversal
 *  inOrder: Prints the keys (comma separated) of the tree using an inorder traversal
 *  postOrder: Prints the keys (comma separated) of the tree using an postorder traversal
 *  transplant: Moves a node from one place on the tree to another
 *
\***************************************************************************/

#include "BST.h"
#include <iostream>
#include <cstring>

using namespace std;

#include <stack>

/** Minimum: Finds and returns the node with the smallest key */
BSTNode *BST::_min(BSTNode *x) {
    //BST Min
    while (x->left != nullptr) { // While there is a left child
        x = x->left; // Move to the left child
    }
    return x; // Return the leftmost node
}

/**Successor: Returns the node following node x in key order in the whole tree */
BSTNode *BST::_successor(BSTNode *x) {
    //BST Successor
    if (x->right != nullptr) { // If there is a right child
        return _min(x->right); // Return the leftmost node of the right child
    }
    BSTNode *y = x->parent; // Set y to the parent of x
    while (y != nullptr && x == y->right) { // While y is not null and x is the right child of y
        x = y; // Set x to y
        y = y->parent; // Set y to the parent of y
    }
    return y; // Return y
}

/** Computes and returns the height of the node x. */
int BST::_height(BSTNode *x) {
    if (x == nullptr) { // If x is null
        return 0; // Return 0
    }
    int leftHeight = _height(x->left); // Set leftHeight to the height of the left child
    int rightHeight = _height(x->right); // Set rightHeight to the height of the right child
    if (leftHeight > rightHeight) { // If leftHeight is greater than rightHeight
        return leftHeight + 1; // Return leftHeight + 1
    } else {
        return rightHeight + 1;  // Return rightHeight + 1
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
    if (m_root == nullptr) { // If the root is null
        cout << "[]"; // Print []
        return;
    }
    //Prints the tree
    BSTNode *node = _min(m_root); // Set node to the leftmost node
    while (node != nullptr) { // While node is not null
        cout << "(" << node->key << "," << node->data << "), "; // Print the key and data of the node
        node = _successor(node); // Set node to the successor of node
    }
}


/** Finds a node with (key) from the tree and returns the associated (data) or NULL if not found. */
BSTNode *BST::search(int key) {
    if (m_root == nullptr) { // If the root is null
        return nullptr; // Return null
    }
    //Search tree
    BSTNode *x = m_root; // Set x to the root
    while (x != nullptr && key != x->key) { // While x is not null and the key is not equal to the key of x
        if (key < x->key) { // If the key is less than the key of x
            x = x->left; // Set x to the left child of x
        } else { // If the key is greater than the key of x
            x = x->right; // Set x to the right child of x
        }
    }
    return x; // Return x
}

/** Inserts a new node in the tree with given (key, data). */
void BST::insert(int key, const char *data) {
    //Inserts a new node
    auto *z = new BSTNode(); // Create a new node
    z->key = key; // Set the key of the new node to the given key
    z->data = data; // Set the data of the new node to the given data
    BSTNode *y = nullptr; // Create a new node y and set it to null
    BSTNode *x = m_root; // Set x to the root
    while (x != nullptr) { // While x is not null
        y = x; // Set y to x
        if (z->key < x->key) { // If the key of z is less than the key of x
            x = x->left; // Set x to the left child of x
        } else { // If the key of z is greater than the key of x
            x = x->right;  // Set x to the right child of x
        }
    }
    z->parent = y; // Set the parent of z to y
    if (y == nullptr) { // If y is null
        m_root = z; // Set the root to z
    } else if (z->key < y->key) { // If the key of z is less than the key of y
        y->left = z; // Set the left child of y to z
    } else {   // If the key of z is greater than the key of y
        y->right = z; // Set the right child of y to z
    }
}

/** Deletes a the node with (key) from the tree and returns the associated (data) or NULL if not found. */
const char *BST::remove(int key) {
    //Removes a node
    BSTNode *z = search(key); // Set z to the node with the given key
    if (z == nullptr) { // If z is null
        return nullptr; // Return null
    }
    // Create a copy of the data to return
    char *dataCopy = new char[strlen(z->data) + 1]; // Create a new char array with the length of the data of z + 1
    strcpy(dataCopy, z->data); // Copy the data of z to dataCopy
    if (z->left == nullptr) { // If the left child of z is null
        transplant(z, z->right); // Move the right child of z to the place of z
    } else if (z->right == nullptr) { // If the right child of z is null
        transplant(z, z->left); // Move the left child of z to the place of z
    } else { // If z has two children
        BSTNode *y = _min(z->right); // Set y to the leftmost node of the right child of z
        if (y->parent != z) { // If the parent of y is not z
            transplant(y, y->right); // Move the right child of y to the place of y
            y->right = z->right; // Set the right child of y to the right child of z
            y->right->parent = y; // Set the parent of the right child of y to y
        }
        transplant(z, y); // Move y to the place of z
        y->left = z->left; // Set the left child of y to the left child of z
        y->left->parent = y; // Set the parent of the left child of y to y
    }
    delete z; // Delete z
    return dataCopy; // Return dataCopy
}

/** Computes and returns the height of the tree. */
int BST::height() {
    //Computes the height of the tree
    return _height(m_root);
}

/** Prints the keys (comma separated) of the tree using an preorder traversal. */
void BST::preOrder() {
    if (m_root == nullptr) { // If the root is null
        cout << "[]"; // Print []
        return;
    }

    stack<BSTNode *> nodeStack; // Create a new stack of BSTNode
    nodeStack.push(m_root); // Push the root to the stack

    while (!nodeStack.empty()) { // While the stack is not empty
        BSTNode *node = nodeStack.top(); // Set node to the top of the stack
        cout << node->key << ", "; // Print the key of the node
        nodeStack.pop(); // Pop the top of the stack
        if (node->right) { // If the right child of the node is not null
            nodeStack.push(node->right); // Push the right child of the node to the stack
        }
        if (node->left) { // If the left child of the node is not null
            nodeStack.push(node->left); // Push the left child of the node to the stack
        }
    }
}

/** Prints the keys (comma separated) of the tree using an inorder traversal. */
void BST::inOrder() {
    if (m_root == nullptr) { // If the root is null
        cout << "[]"; // Print []
        return;
    }

    stack<BSTNode *> nodeStack; // Create a new stack of BSTNode
    BSTNode *curr = m_root; // Set curr to the root

    while (curr != nullptr || !nodeStack.empty()) { // While curr is not null or the stack is not empty
        while (curr != nullptr) { // While curr is not null
            nodeStack.push(curr); // Push curr to the stack
            curr = curr->left; // Set curr to the left child of curr
        }
        curr = nodeStack.top(); // Set curr to the top of the stack
        nodeStack.pop(); // Pop the top of the stack
        cout << curr->key << ", "; // Print the key of curr

        curr = curr->right; // Set curr to the right child of curr
    }
}

/** Prints the keys (comma separated) of the tree using an postorder traversal. */
void BST::postOrder() {
    if (m_root == nullptr) { // If the root is null
        cout << "[]"; // Print []
        return;
    }

    stack<BSTNode *> s1, s2; // Create two new stacks of BSTNode
    s1.push(m_root); // Push the root to s1

    while (!s1.empty()) { // While s1 is not empty
        BSTNode *node = s1.top(); // Set node to the top of s1
        s1.pop(); // Pop the top of s1
        s2.push(node); // Push node to s2

        if (node->left) { // If the left child of node is not null
            s1.push(node->left); // Push the left child of node to s1
        }
        if (node->right) { // If the right child of node is not null
            s1.push(node->right); // Push the right child of node to s1
        }
    }

    while (!s2.empty()) { // While s2 is not empty
        BSTNode *node = s2.top(); // Set node to the top of s2
        s2.pop(); // Pop the top of s2
        cout << node->key << ", "; // Print the key of node
    }
}


/** Transplant function */
void BST::transplant(BSTNode *u, BSTNode *v) {
    if (u->parent == nullptr) { // If the parent of u is null
        m_root = v; // Set the root to v
    } else if (u == u->parent->left) { // If u is the left child of its parent
        u->parent->left = v; // Set the left child of the parent of u to v
    } else { // If u is the right child of its parent
        u->parent->right = v; // Set the right child of the parent of u to v
    }
    if (v != nullptr) { // If v is not null
        v->parent = u->parent; // Set the parent of v to the parent of u
    }
}



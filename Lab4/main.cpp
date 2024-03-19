/****************************************************************************\
* main.cpp
*
*  Created on: Mar 7 2024
*      Author: OCdt Paterson
 *
*
*  TODO: Make sure to demonstrate the appropriate functionality of your
*  binary search tree by testing ALL the cases in provided documents.
*  Your output must be EXPLICIT about what is tested and what is the result.
*
\***************************************************************************/

#include <iostream>
#include "BST.h"
using namespace std;

int main() {
	cout << "CSE250 - Lab4 " << endl; // prints CSE/INF250 - Lab4
    cout << "---------------- Question 1 ----------------" << endl;
    //create a new tree
    BST* t = new BST();
    //print functions using empty tree
    cout << "t->preOrder outputs ";
    t->preOrder();
    cout << endl << "t->postOrder outputs ";
    t->postOrder();
    cout << endl << "t->inOrder outputs ";
    t->inOrder();


    cout << endl << "t->search(4) returns ";
    BSTNode* result = (BSTNode *) t->search(4);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl << "t->printTree() outputs ";
    t->printTree();
    cout << endl << "t->height() returns " << t->height();
    cout << endl << "t->remove(4) returns ";
    result = (BSTNode *) t->remove(4);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->key;
    }


    cout << endl << "---------------- Question 2 ----------------" << endl;
    cout << "Removing node key 5... ";
    BSTNode *ret = (BSTNode *) t->remove(5);
    cout << endl << "Printing tree: " << endl;
    t->printTree();
    cout << endl << "Inserting node with key 5 and data 'data5': " << endl;
    t->insert(5, "data5");
    cout << "Printing tree: " << endl;
    t->printTree();
    cout << "Removing node key 5 again... ";
    ret = (BSTNode *) t->remove(5);
    cout << endl << "Adding key 10 and data 'data10'... ";
    t->insert(10, "data10");
    cout << endl << "Printing tree: " << endl;
    t->printTree();
    cout << endl;

    //print functions using empty tree
    cout << "t->preOrder outputs ";
    t->preOrder();
    cout << endl << "t->postOrder outputs ";
    t->postOrder();
    cout << endl << "t->inOrder outputs ";
    t->inOrder();


    cout << endl << "t->search(4) returns ";
    result = (BSTNode *) t->search(4);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl << "t->search(5) returns ";
    result = (BSTNode *) t->search(5);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl << "t->search(10) returns ";
    result = (BSTNode *) t->search(10);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl << "t->printTree() outputs ";
    t->printTree();
    cout << endl << "t->height() returns " << t->height();
    cout << endl << "t->remove(5) returns ";
    result = (BSTNode *) t->remove(5);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->key;
    }
    cout << endl << "t->remove(10) returns ";
    result = (BSTNode *) t->remove(10);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl << "t->remove(10) returns ";
    result = (BSTNode *) t->remove(10);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }



    cout << endl << "---------------- Question 3 ----------------" << endl;
    t->insert(10, "Data10");
    t->insert(5, "Data5");
    t->insert(15, "Data15");
    t->insert(6, "Data6");
    t->insert(3, "Data3");
    t->insert(16, "Data16");
    t->insert(13, "Data13");
    t->insert(2, "Data2");
    t->remove(5);

    cout << "t->preOrder outputs ";
    t->preOrder();
    cout << endl << "t->postOrder outputs ";
    t->postOrder();
    cout << endl << "t->inOrder outputs ";
    t->inOrder();
    cout << endl << "result = t->search(13) returns ";
    result = (BSTNode *) t->search(13);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl <<  "result = t->search(100) returns ";
    result = (BSTNode *) t->search(100);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl << "result = t->search(5) returns ";
    result = (BSTNode *) t->search(5);
    if (result == nullptr) {
        cout << "null";
    } else {
        cout << result->data;
    }
    cout << endl << "t->printTree() outputs ";
    t->printTree();
    cout << endl << "t->height() returns " << t->height();

    cout << endl << "---------------- Question 4 ----------------" << endl;








    return 0;
}

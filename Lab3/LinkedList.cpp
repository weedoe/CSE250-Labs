/****************************************************************************\
 * LinkedList.h
 *
 *  Created on:
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details: ?
 *  \\TODO
 *  You can add your implementation details here or in the header,
 *  or with appropriate variable's or function's comments.
 *
 \***************************************************************************/

#include "LinkedList.h"

#include <iostream>
using namespace std;


/** Constructs an empty list.  */
LinkedList::LinkedList() {
    m_First = nullptr;
};

/** Deletes an empty list by freeing nodes memory. */
LinkedList::~LinkedList() {
	while (Length() > 0) {
		RemoveFirst();
	}
}

/** Returns the length of the list in O(1).
 * Return: Length of the list
 */
int LinkedList::Length() {
    int count = 0;
    Node* current = m_First;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
	return count;
}

/** Prints all the element of the list using cout, on a single line, separated by a comma. eg: [3, 19, 2, 36].*/
void LinkedList::PrintList() {
    if (m_First != nullptr) {
Node* current = m_First;
        cout << "[";
        while (current != nullptr) {
            cout << current->value;
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << "]" << endl;

    } else {
        cout << "[]" << endl;
    }
}

/** Inserts a new string in first position in O(1).
 * Args: new_value is the new string to put in the list
 */
void LinkedList::InsertFirst(const string &new_value){
	Node* newnode = new Node;
    newnode->value = new_value;
    newnode->next = m_First;
    newnode->prev = nullptr;
    if (m_First != nullptr) {
        m_First->prev = newnode;
    }
    m_First = newnode;
}


/** Removes and returns the first element of the list in O(1).
 * Return: The string removed, or "" if empty
 */
string LinkedList::RemoveFirst() {
	if (m_First != nullptr) {
		string ret = m_First->value;
		Node* todel = m_First;
		m_First = m_First->next;
        if (m_First != nullptr) {
            m_First->prev = nullptr;
        }
		delete todel;
		return ret;
	} else {
		return string("");
	}
}

/** Returns the string at a given index (1st node at index 0, 2nd at index 1, etc...) in O(n).
 *  Args: index node position =  1st node at index 0, 2nd at index 1, etc...
 *  Return: "" if the index does not exists */
string LinkedList::GetValueAt(int index) {
	    Node* current = m_First;
    int count = 0;
    while (current != nullptr) {
        if (count == index) {
            return current->value;
        }
        count++;
        current = current->next;
    }
	return "";
}




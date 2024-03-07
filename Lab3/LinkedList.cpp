/****************************************************************************\
 * LinkedList.h
 *
 *  Created on: Mar 6, 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details:
 *  In the header...
 *
 \***************************************************************************/

#include "LinkedList.h"

#include <iostream>

using namespace std;


/** Constructs an empty list.  */
LinkedList::LinkedList() {
    m_First = nullptr; // Set the first node to null
};

/** Deletes an empty list by freeing nodes memory. */
LinkedList::~LinkedList() {
    while (Length() > 0) { // While the list is not empty
        RemoveFirst(); // Remove the first node
    }
}

/** Returns the length of the list in O(1).
 * Return: Length of the list
 */
int LinkedList::Length() {
    int count = 0; // Start the count at 0
    Node *current = m_First; // Start from the first node
    while (current != nullptr) { // Loop through the list
        count++; // Increment the count
        current = current->next; // Move to the next node
    }
    return count; // Return the count
}

/** Prints all the element of the list using cout, on a single line, separated by a comma. eg: [3, 19, 2, 36].*/
void LinkedList::PrintList() {
    if (m_First != nullptr) {
        Node *current = m_First; // Start from the first node
        cout << "["; // Print the opening bracket
        while (current != nullptr) { // Loop through the list
            cout << current->value; // Print the value
            if (current->next != nullptr) { // If there is a next node
                cout << ", "; // Print a comma
            }
            current = current->next; // Move to the next node
        }
        cout << "]" << endl; // Print the closing bracket

    } else {
        cout << "[]" << endl; // If the list is empty, print an empty list
    }
}

/** Inserts a new string in first position in O(1).
 * Args: new_value is the new string to put in the list
 */
void LinkedList::InsertFirst(const string &new_value) {
    Node *newnode = new Node; // Create a new node
    newnode->value = new_value; // Set the value of the new node
    newnode->next = m_First; // Set the next pointer of the new node to the first node
    newnode->prev = nullptr; // Set the previous pointer of the new node to null
    if (m_First != nullptr) { // If the list is not empty
        m_First->prev = newnode; // Set the previous pointer of the first node to the new node
    }
    m_First = newnode; // Set the first node to the new node
}


/** Removes and returns the first element of the list in O(1).
 * Return: The string removed, or "" if empty
 */
string LinkedList::RemoveFirst() {
    if (m_First != nullptr) { // If the list is not empty
        string ret = m_First->value; // Get the value of the first node
        Node *todel = m_First; // Create a pointer to the first node
        m_First = m_First->next; // Set the first node to the next node
        if (m_First != nullptr) { // If the list is not empty
            m_First->prev = nullptr; // Set the previous pointer of the first node to null
        }
        delete todel; // Delete the first node
        return ret; // Return the value of the first node
    } else {
        return string(""); // If the list is empty, return an empty string
    }
}

/** Returns the string at a given index (1st node at index 0, 2nd at index 1, etc...) in O(n).
 *  Args: index node position =  1st node at index 0, 2nd at index 1, etc...
 *  Return: "" if the index does not exists */
string LinkedList::GetValueAt(int index) {
    Node *current = m_First; // Start from the first node
    int count = 0; // Start the count at 0
    while (current != nullptr) { // Loop through the list
        if (count == index) { // If the count is equal to the index
            return current->value; // Return the value of the current node
        }
        count++; // Increment the count
        current = current->next; // Move to the next node
    }
    return ""; // If the index does not exist, return an empty string
}




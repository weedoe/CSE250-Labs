/****************************************************************************\
 * Stack.cpp
 *
 *  Created on: Mar 6, 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details: ?
 *  In header...
 *  You can add your implementation details here or in the header,
 *  or with the appropriate variable's or function's comments.
 *
 \***************************************************************************/

#include "Stack.h"

#include <iostream>

using namespace std;


/** Constructs an empty stack. */
Stack::Stack() {
}

/** Deletes the stack. */
Stack::~Stack() {
}

/** Indicates whether the stack is empty in O(1).
 * Returns: true is empty, false if not
 */
bool Stack::IsEmpty() {
    return m_List.Length() == 0; // Return true if the length of the list is 0, false if not
}

/** Prints all the element of the stack using cout, from top to bottom (1 item per line).
 *  WHAT IS THE O() OF YOUR METHOD? EXPLAIN IN YOUR REPORT (or via couts in the main)
 */
void Stack::PrintStack() {
    m_List.PrintList(); // Print the list
}

/** Adds a string on the top of the stack in O(1).
 * Args: New string to put on top of the stack.
 */
void Stack::Push(const string &new_value) {
    m_List.InsertFirst(new_value); // Insert the new value at the first position
}

/** Removes and returns the string on the top of the stack in O(1).
 * Return: string on top of the stack or "" if empty.
 */
string Stack::Pop() {
    if (!IsEmpty()) { // If the stack is not empty
        string top = Top(); // Get the top of the stack
        m_List.RemoveFirst(); // Remove the first element
        return top; // Return the top of the stack
    }
    return {""}; // Return an empty string
}

/** Returns the string on the top of the stack in O(1).
 * Return: String on top of the stack or "" if empty.
 * */
string Stack::Top() {
    if (!IsEmpty()) { // If the stack is not empty
        return m_List.GetValueAt(0); // Return the first element
    }
    return {""}; // Return an empty string
}




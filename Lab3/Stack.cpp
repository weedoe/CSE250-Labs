/****************************************************************************\
 * Stack.cpp
 *
 *  Created on:
 *      Author: YOUR NAME
 *
 *
 *  Implementation details: ?
 *  \\TODO
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
Stack::~Stack(){
}

/** Indicates whether the stack is empty in O(1).
 * Returns: true is empty, false if not
 */
bool Stack::IsEmpty() {
	return m_List.Length() == 0;
}

/** Prints all the element of the stack using cout, from top to bottom (1 item per line).
 *  WHAT IS THE O() OF YOUR METHOD? EXPLAIN IN YOUR REPORT (or via couts in the main)
 */
void Stack::PrintStack() {
    //TODO
}

/** Adds a string on the top of the stack in O(1).
 * Args: New string to put on top of the stack.
 */
void Stack::Push(const string &new_value) {
	//TODO
}

/** Removes and returns the string on the top of the stack in O(1).
 * Return: string on top of the stack or "" if empty.
 */
string Stack::Pop() {
	//TODO
	return string("");
}

/** Returns the string on the top of the stack in O(1).
 * Return: String on top of the stack or "" if empty.
 * */
string Stack::Top() {
	//TODO
	return string("");
}




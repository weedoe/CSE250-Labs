/****************************************************************************\
 * Stack.h
 *
 *  Created on: Mar 6, 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details:
 *  Creates a stack of strings using a linked list.
 *  The class Stack has a LinkedList variable in private.
 *  The class Stack's public uses the following methods:
 *  - Stack() constructor
 *  - ~Stack() destructor
 *  - IsEmpty() indicates whether the stack is empty in true or false
 *  - PrintStack() prints all the element of the stack
 *  - Push(const string &new_value) adds a string on the top of the stack
 *  - Pop() removes and returns the string on the top of the stack
 *  - Top() returns the string on the top of the stack
 *
 \***************************************************************************/

#ifndef STACK_H_
#define STACK_H_

#include "LinkedList.h"

#include <string>

using namespace std;

/** Stack of strings using linked-list. */
class Stack {
private:
    /** LinkedList variable (not a pointer), therefore enough space is already allocated
     * and the constructor and destructor are automatically called when constructing
     * or destructing the Stack object. */
    LinkedList m_List;

public:
    /** Constructs an empty stack. */
    Stack();

    /** Deletes the stack. */
    virtual ~Stack();

    /** Indicates whether the stack is empty (true) or not (false) in O(1). */
    bool IsEmpty();

    /** Prints all the element of the stack using cout, from top to bottom (1 item per line). */
    void PrintStack();

    /** Adds a string on the top of the stack in O(1).*/
    void Push(const string &new_value);

    /** Removes and returns the string on the top of the stack in O(1). Returns "" if empty. */
    string Pop();

    /** Returns the string on the top of the stack in O(1). Returns "" if empty .*/
    string Top();
};

#endif /* STACK_H_ */

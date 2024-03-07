/****************************************************************************\
 * LinkedList.h
 *
 *  Created on: Mar 6, 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details:
 *  Creates a doubly linked list of strings.
 *  The list is made with a Node struct.
 *  The class LinkedList has a pointer to the first node in private.
 *  The class LinkedList's public uses the following methods:
 *  - LinkedList() constructor
 *  - ~LinkedList() destructor
 *  - Length() returns the length of the list in O(1)
 *  - PrintList() prints all the element of the list
 *  - InsertFirst(const string &new_value) inserts a new string in first position
 *  - RemoveFirst() removes and returns the first element of the list
 *  - GetValueAt(int index) returns the string at a given index
 *
 \***************************************************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
using namespace std;

/** Doubly linked-list node. */
struct Node {
	/** String of data. */
	string value;
	/** Pointer to next node. */
	Node* next;
	/** Pointer to previous node. */
	Node* prev;
};

/** Linked-list of string class. */
class LinkedList
{
	private:
		/** Pointer to the first node. */
		Node* m_First;
		// TODO: Add other instance variables or helper methods if needed

	public:
		/** Constructs an empty list. */
		LinkedList();
		/** Deletes an empty list by freeing nodes memory. */
		virtual ~LinkedList();

		/** Returns the length of the list in O(1). */
		int Length();
		/** Prints all the element of the list using cout, on a single line, separated by a comma. eg: [3, 19, 2, 36].*/
        void PrintList();

		/** Inserts a new string in first position in O(1). */
		void InsertFirst(const string &new_value);
		/** Removes and returns the first element of the list in O(1). Returns "" if empty. */
		string RemoveFirst();

		/** Returns the string at a given index (1st node at index 0, 2nd at index 1, etc...) in O(n).
		 *  Returns "" if the index does not exist. */
		string GetValueAt(int index);
};


#endif /* LINKEDLIST_H_ */

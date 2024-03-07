/****************************************************************************\
 * Queue.cpp
 *
 *  Created on: Mar 6, 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details: ?
 *  In header...
 *
 *
 \***************************************************************************/

#include "Queue.h"
#include <iostream>

using namespace std;

/** Deletes the queue and free up its memory. */
Queue::~Queue() {
    delete[] m_Data;
}

Queue::Queue(int new_max_size) {
    m_MaxSize = new_max_size; // Set the maximum size of the queue
    m_Data = new int[m_MaxSize]; // Create the array to store the queue
    m_First = 0; // Set the first element to 0
    m_Last = 0;
    m_Size = 0;
}

/** Indicates whether of not the queue is empty in O(1), true if empty, false if not. */
bool Queue::IsEmpty() {
    return m_Size == 0; // Return true if the size is 0, false if not
}

/** Indicates whether of not the queue is full in O(1), true if full, false if not. */
bool Queue::IsFull() {
    return m_Size == m_MaxSize; // Return true if the size is equal to the maximum size, false if not
}

/** Prints the content of the queue on a single line, separated by comma, eg: [3, 19, 2, 36]. */

void Queue::PrintQueue() {
    if (IsEmpty()) { // If the queue is empty
        cout << "[]" << endl; // Print an empty list
    } else { // If the queue is not empty
        cout << "["; // Print the opening bracket
        for (int i = 0; i < m_Size; i++) { // Loop through the queue
            cout << m_Data[(m_First + i) % m_MaxSize]; // Print the value
            if (i < m_Size - 1) { // If there is a next element
                cout << ", "; // Print a comma
            }
        }
        cout << "]" << endl; // Print the closing bracket
    }
}

/** Inserts an element at the end of the queue, returns true if succeed, and false if the queue is already full. */
bool Queue::Enqueue(int new_value) {
    if (IsFull()) { // If the queue is full
        return false; // Return false
    } else { // If the queue is not full
        m_Data[m_Last] = new_value; // Add the new value at the end of the queue
        m_Last = (m_Last + 1) % m_MaxSize; // Move the last element to the next position
        m_Size++; // Increment the size
        return true; // Return true
    }
}

/** Removes the element at the front of the queue and returns the element in the argument,
 * returns true if succeed, and false if the queue is already full.  */
bool Queue::Dequeue(int &old_value) {
    if (IsEmpty()) { // If the queue is empty
        return false; // Return false
    } else { // If the queue is not empty
        old_value = m_Data[m_First]; // Set the old value to the first element
        m_First = (m_First + 1) % m_MaxSize; // Move the first element to the next position
        m_Size--; // Decrement the size
        return true; // Return true
    }
}




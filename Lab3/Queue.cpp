/****************************************************************************\
 * Queue.cpp
 *
 *  Created on:
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details: ?
 *  \\TODO
 *  You can add your implementation details here or in the header,
 *  or with the appropriate variable's or function's comments.
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
    m_MaxSize = new_max_size;
    m_Data = new int[m_MaxSize];
    m_First = 0;
    m_Last = 0;
    m_Size = 0;
}

/** Indicates whether of not the queue is empty in O(1), true if empty, false if not. */
bool Queue::IsEmpty() {
    return m_Size == 0;
}

/** Indicates whether of not the queue is full in O(1), true if full, false if not. */
bool Queue::IsFull() {
    return m_Size == m_MaxSize;
}

/** Prints the content of the queue on a single line, separated by comma, eg: [3, 19, 2, 36]. */

void Queue::PrintQueue() {
    if (IsEmpty()) {
        cout << "[]" << endl;
    } else {
        cout << "[";
        for (int i = 0; i < m_Size; i++) {
            cout << m_Data[(m_First + i) % m_MaxSize];
            if (i < m_Size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

/** Inserts an element at the end of the queue, returns true if succeed, and false if the queue is already full. */
bool Queue::Enqueue(int new_value) {
    if (IsFull()) {
        return false;
    } else {
        m_Data[m_Last] = new_value;
        m_Last = (m_Last + 1) % m_MaxSize;
        m_Size++;
        return true;
    }
}

/** Removes the element at the front of the queue and returns the element in the argument,
 * returns true if succeed, and false if the queue is already full.  */
bool Queue::Dequeue(int &old_value) {
    if (IsEmpty()) {
        return false;
    } else {
        old_value = m_Data[m_First];
        m_First = (m_First + 1) % m_MaxSize;
        m_Size--;
        return true;
    }
}




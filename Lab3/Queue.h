/****************************************************************************\
 * Queue.h
 *
 *  Created on: Mar 6, 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details:
 *  Creates a queue of integers using an array. The queue is a circular buffer
 *  and the array is used to store the content of the queue.
 *  The class Queue has a pointer to the first and last element in private.
 *  The class Queue's public uses the following methods:
 *  - Queue(int new_max_size) constructor
 *  - ~Queue() destructor
 *  - IsEmpty() indicates whether the queue is empty in true or false
 *  - IsFull() indicates whether the queue is full in true or false
 *  - PrintQueue() prints the content of the queue on a single line, separated by comma
 *  - Enqueue(int new_value) inserts an element at the end of the queue
 *  - Dequeue(int &old_value) removes the element at the front of the queue
 *
 \***************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

/** Queue of integers using an array. */
class Queue {

private:
    /** Array used as a circular buffer for queue content. */
    int *m_Data;
    /** Size of the circular buffer. */
    int m_MaxSize;
    /** The first in queue **/
    int m_First;
    /** The last in queue */
    int m_Last;
    // Need a size variable to keep track of the number of elements in the queue
    int m_Size;

public:
    /** Constructs an empty queue of maximum size new_max_size */
    Queue(int new_max_size);

    /** Deletes the queue and free up its memory. */
    virtual ~Queue();

    /** Indicates whether of not the queue is empty in O(1), true if empty, false if not. */
    bool IsEmpty();

    /** Indicates whether of not the queue is full in O(1), true if full, false if not. */
    bool IsFull();

    /** Prints the content of the queue on a single line, separated by comma, eg: [3, 19, 2, 36]. */
    void PrintQueue();

    /** Inserts an element at the end of the queue, returns true if succeed, and false if the queue is already full. */
    bool Enqueue(int new_value);

    /** Removes the element at the front of the queue and returns the element in the argument,
     * returns true if succeed, and false if the queue is already full.  */
    bool Dequeue(int &old_value);
};

#endif /* QUEUE_H_ */




#include <iostream>
#include <sstream>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
int main() {
    cout << "---------------- Question 2 ----------------" << endl << endl;
    cout << "Creating an empty queue of size 5" << endl;
    Queue Q1(5);
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl;
    cout << "Adding 1 and 2 to the queue" << endl;
    cout << "Is adding 1 to the queue successful? " <<  Q1.Enqueue(1) << endl;
    cout << "Is adding 2 to the queue successful? " <<  Q1.Enqueue(2) << endl;
    cout << "Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << "Is the queue full? " << Q1.IsFull() << endl;
    cout << "Queue content: "; Q1.PrintQueue(); cout << endl;
    cout << "Adding 3, 4, 5, 6 to the queue" << endl;
    cout << "Is adding 3 to the queue successful? " <<  Q1.Enqueue(3) << endl;
    cout << "Is adding 4 to the queue successful? " <<  Q1.Enqueue(4) << endl;
    cout << "Is adding 5 to the queue successful? " <<  Q1.Enqueue(5) << endl;
    cout << "Is adding 6 to the queue successful? " <<  Q1.Enqueue(6) << endl;
    cout << "Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << "Is the queue full? " << Q1.IsFull() << endl;
    cout << "Queue content: "; Q1.PrintQueue(); cout << endl;
    cout << "Removing 1, 2 from the queue" << endl;
    int old_value;
    cout << "Is removing 1 from the queue successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is removing 2 from the queue successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << "Is the queue full? " << Q1.IsFull() << endl;
    cout << "Queue content: "; Q1.PrintQueue(); cout << endl;
    cout << "Wrapping 7, 8 around the queue" << endl;
    cout << "Is adding 7 to the queue successful? " <<  Q1.Enqueue(7) << endl;
    cout << "Is adding 8 to the queue successful? " <<  Q1.Enqueue(8) << endl;
    cout << "Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << "Is the queue full? " << Q1.IsFull() << endl;
    cout << "Queue content: "; Q1.PrintQueue(); cout << endl;
    cout << "Removing 3 to 7 from the queue" << endl;
    cout << "Is removing successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is removing successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is removing successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is removing successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << "Is the queue full? " << Q1.IsFull() << endl;
    cout << "Queue content: "; Q1.PrintQueue(); cout << endl;
    cout << "Adding 9 to the queue" << endl;
    cout << "Is adding 9 to the queue successful? " <<  Q1.Enqueue(9) << endl;
    cout << "Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << "Is the queue full? " << Q1.IsFull() << endl;
    cout << "Queue content: "; Q1.PrintQueue(); cout << endl;
    cout << "Emptying the queue" << endl;
    cout << "Is removing 8 from the queue successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is removing 9 from the queue successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is removing 9 from the queue successful? " <<  Q1.Dequeue(old_value) << " removed: " << old_value << endl;
    cout << "Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << "Is the queue full? " << Q1.IsFull() << endl;
    cout << "Queue content: "; Q1.PrintQueue(); cout << endl;

    cout << "---------------- Question 3 ----------------" << endl << endl;
    Queue Q2(6);
    int nextNumber = 1;

    // Enqueue the first 5 numbers
    for (int i = 0; i < 5; i++) {
        Q2.Enqueue(nextNumber);
        cout << "Step #" << i << ": Initial arrival #" << nextNumber++ << endl;
        Q2.PrintQueue();
        cout << endl;
    }

    for(int i = 5; i < 18; i++) {
        double randNum = (double)rand() / RAND_MAX; // generate a random number between 0 and 1
        if (randNum > 0.5 && !Q2.IsEmpty() || i == 5) { // dequeue a person
            Q2.Dequeue(old_value);
            cout << "Step #" << i << ": Processing #" << old_value << " successfully" << endl;
        }
        else if (randNum <= 0.5 && !Q2.IsFull()) { // enqueue a new person
            Q2.Enqueue(nextNumber);
            cout << "Step #" << i << ": Arrival #" << nextNumber++ << " inserted" << endl;
        }

        Q2.PrintQueue();
        cout << endl;
    }

    cout << "---------------- Question 4 ----------------" << endl << endl;
    //create linked list
    LinkedList L1;
    cout << "Is the list empty? " << bool(L1.Length() == 0) << endl;
    cout << "Adding 1, 2, 3 to the list" << endl;
    L1.InsertFirst("1");
    L1.InsertFirst("2");
    L1.InsertFirst("3");
    cout << "Is the list empty? " << bool(L1.Length() == 0) << endl;
    cout << "List content: "; L1.PrintList(); cout << endl;
    cout << "Removing index 1 from the list" << endl;
    cout << "Is removing 1 from the list successful? " <<  L1.RemoveFirst() << endl;
    cout << "Is the list empty? " << bool(L1.Length() == 0) << endl;
    cout << "List content: "; L1.PrintList(); cout << endl;
    //get value at
    cout << "Value at index 0: " << L1.GetValueAt(0) << endl;

    cout << "---------------- Question 5 ----------------" << endl << endl;
    //create stack
    Stack S1;
    cout << "Is the stack empty? " << S1.IsEmpty() << endl;
    cout << "Adding 1, 2, 3 to the stack" << endl;
    S1.Push("1");
    S1.Push("2");
    S1.Push("3");
    cout << "Is the stack empty? " << S1.IsEmpty() << endl;
    cout << "Stack content: "; S1.PrintStack(); cout << endl;
    cout << "Popping the stack" << endl;
    cout << "Popping: " <<  S1.Pop() << endl;
    cout << "Is the stack empty? " << S1.IsEmpty() << endl;
    cout << "Stack content: "; S1.PrintStack();
    cout << "Top of stack: " << S1.Top() << endl << endl;
    cout << "Popping the stack" << endl;
    cout << "Is popping the stack successful? " <<  S1.Pop() << endl;
    cout << "Is the stack empty? " << S1.IsEmpty() << endl;
    cout << "Stack content: "; S1.PrintStack();
    cout << "Top of stack: " << S1.Top() << endl << endl;
    cout << "Popping the stack" << endl;
    cout << "Is popping the stack successful? " <<  S1.Pop() << endl;
    cout << "Is the stack empty? " << S1.IsEmpty() << endl;
    cout << "Stack content: "; S1.PrintStack();
    cout << "Top of stack: " << S1.Top() << endl;

    Stack S2;
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);
    stringstream ss(expression);
    string token;
    while(getline(ss, token, ',')){
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = stoi(S2.Pop());
            int operand1 = stoi(S2.Pop());
            if (token == "+") {
                S2.Push(to_string(operand1 + operand2));
            } else if (token == "-") {
                S2.Push(to_string(operand1 - operand2));
            } else if (token == "*") {
                S2.Push(to_string(operand1 * operand2));
            } else if (token == "/") {
                S2.Push(to_string(operand1 / operand2));
            }
        } else {
            S2.Push(token);
        }
        cout << "Result: " << S2.Top() << endl;
    }
    cout << "Final result: " << S2.Top() << endl;
    return 0;
}

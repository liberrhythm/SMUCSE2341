/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Implements functionality for a custom queue data structure
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef QUEUE
#define QUEUE

#include "LinkedList.h"

template<class T>
class Queue
{
    public:
        T dequeue();
        T peek();
        void enqueue(T);
        bool isEmpty();
        int size();

    private:
        LinkedList<T> data;

};

#endif

//removes data from the front of the queue
template<class T>
T Queue<T>::dequeue() {
    return data.removeFromFront();
}

//gets first element of the queue
template<class T>
T Queue<T>::peek() {
    return data.get(0);
}

//adds data at the end of the queue
template<class T>
void Queue<T>::enqueue(T element) {
    data.add(element);
}

//checks to see if there are any elements in queue
template<class T>
bool Queue<T>::isEmpty() {
    if (data.size() == 0) {
        return true;
    }
    return false;
}

//returns number of elements in queue
template<class T>
int Queue<T>::size() {
    return data.size();
}

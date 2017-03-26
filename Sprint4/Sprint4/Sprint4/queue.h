#ifndef QUEUE
#define QUEUE

#include "linkedlist.h"

template<class T>
class Queue
{
    public:
        T dequeue();
        T peek();
        void enqueue(T);
        bool isEmpty();

    private:
        LinkedList<T> data;

};

#endif

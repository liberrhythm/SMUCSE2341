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

    private:
        LinkedList<T> data;

};

#endif

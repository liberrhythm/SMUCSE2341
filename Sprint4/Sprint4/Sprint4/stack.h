#ifndef STACK
#define STACK

#include "linkedlist.h"

template<class T>
class Stack
{
    public:
        T pop();
        T peek();
        void push(T);
        bool isEmpty();

    private:
        LinkedList<T> data;
};

#endif

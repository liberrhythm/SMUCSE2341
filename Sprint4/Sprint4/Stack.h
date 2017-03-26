#ifndef STACK
#define STACK

#include "LInkedLIst.h"

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

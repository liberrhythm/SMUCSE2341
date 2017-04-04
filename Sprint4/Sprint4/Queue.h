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

template<class T>
T Queue<T>::dequeue() {
    return data.removeFromFront();
}

template<class T>
T Queue<T>::peek() {
    return data.get(0);
}

template<class T>
void Queue<T>::enqueue(T element) {
    data.add(element);
}

template<class T>
bool Queue<T>::isEmpty() {
    if (data.size() == 0) {
        return true;
    }
    return false;
}

template<class T>
int Queue<T>::size() {
    return data.size();
}

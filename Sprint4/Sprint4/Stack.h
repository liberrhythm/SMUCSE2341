#ifndef STACK
#define STACK

#include "LinkedList.h"

template<class T>
class Stack
{
    public:
        T pop();
        T peek();
        void push(T);
        bool isEmpty();
        int size();

        bool contains(const T&);
        T get(int);

    private:
        LinkedList<T> data;
};

#endif

template<class T>
T Stack<T>::pop() {
    return data.removeFromBack();
}

template<class T>
T Stack<T>::peek() {
    return data.get(data.size()-1);
}

template<class T>
void Stack<T>::push(T element) {
    data.add(element);
}

template<class T>
bool Stack<T>::isEmpty() {
    if (data.size() == 0) {
        return true;
    }
    return false;
}

template<class T>
int Stack<T>::size() {
    return data.size();
}

template<class T>
bool Stack<T>::contains(const T& element) {
    return data.contains(element);
}

template<class T>
T Stack<T>::get(int index) {
    return data.get(index);
}

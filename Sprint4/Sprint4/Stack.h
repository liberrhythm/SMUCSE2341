/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Implements functionality for a custom stack data structure
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

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

//removes element from top of the stack
template<class T>
T Stack<T>::pop() {
    return data.removeFromBack();
}

//returns element at the top of the stack
template<class T>
T Stack<T>::peek() {
    return data.get(data.size()-1);
}

//adds element at the top of the stack
template<class T>
void Stack<T>::push(T element) {
    data.add(element);
}

//checks to see if there are any elements in stack
template<class T>
bool Stack<T>::isEmpty() {
    if (data.size() == 0) {
        return true;
    }
    return false;
}

//returns number of elements in stack
template<class T>
int Stack<T>::size() {
    return data.size();
}

//checks to see if element exists in stack
template<class T>
bool Stack<T>::contains(const T& element) {
    return data.contains(element);
}

//returns element in stack at a specified index
template<class T>
T Stack<T>::get(int index) {
    return data.get(index);
}

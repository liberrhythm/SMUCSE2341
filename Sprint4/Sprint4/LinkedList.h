/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           3/25/17
Program Number: Sprint4
Purpose:        Implements functionality for a custom doubly linked list class, with the list composed of linked nodes of elements
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

template <class T>
class ListNode
{
    template <class U> friend class LinkedList;

    public:
        ListNode(): next(nullptr), prev(nullptr) {}
        ListNode(T val): next(nullptr), prev(nullptr), data(val) {}
        ListNode(const ListNode<T>& rhs): next(nullptr), prev(nullptr), data(rhs.data) {}

    private:
        ListNode<T>* next;
        ListNode<T>* prev;
        T data;
};

template<class T>
class LinkedList
{
    public:
        LinkedList();
        LinkedList(T);
        LinkedList(const LinkedList<T>&);

        void add(T);
        void addToFront(T);
        T get(int);
        int size();
        T remove(int);

        ~LinkedList();

        T& operator[](int);
        LinkedList<T>& operator=(LinkedList<T>&);

        void print();

    private:
        ListNode<T>* head;
        int numElements;
};

template<class T>
LinkedList<T>::LinkedList() {
    head->next = nullptr;
    numElements = 0;
}

template<class T>
LinkedList<T>::LinkedList(T val) {
    ListNode<T>* element = new ListNode<T>(val);
    head->next = element;
    element->prev = nullptr; //already initalized to nullptr in listnode class?
    numElements++;
}

//copy constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& lst) {
    //iterate through lst and make copies of ListNodes
    ListNode<T>* current = lst.head;
    while (current != nullptr && current->next != nullptr) {
        add(current->data);
    }
    numElements = lst.numElements;
}

template<class T>
void LinkedList<T>::add(T val) {
    if (head == nullptr) {
        head = new ListNode<T>(val);
    }
    else {
        ListNode<T>* current = head;
        while (current->next != nullptr) {
           current = current->next; //advancing to next listnode
        }
        ListNode<T>* temp = new ListNode<T>(val);
        current->next = temp;
        temp->prev = current;
    }
    numElements++;
}

template<class T>
void LinkedList<T>::addToFront(T val) {
    ListNode<T>* temp = new ListNode<T>(val);
    temp->next = head;
    temp->prev = nullptr; //not needed?
    head = temp;
    numElements++;
}

template<class T>
T LinkedList<T>::get(int index) {
    if (index >= numElements || index < 0) {
        throw std::out_of_range("OUT OF RANGE");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<class T>
int LinkedList<T>::size() {
    return numElements;
}

template<class T>
T LinkedList<T>::remove(int index) {
    if (index >= numElements || index < 0) {
        throw std::out_of_range("Index is out of bounds");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    if (head == current && current->next == nullptr) {
        delete current;
    }
    else {
        current->next->prev = current->prev;
        current->prev->next = current->next;
        delete current;
    }
    numElements--;
}

template<class T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* current = head;
    for (int i = 0; i < numElements; i++) { //does this actually do anything...
        delete current;
        current = current->next;
    }
    delete current;
}

template<class T>
T& LinkedList<T>::operator[](int index) {
    if (index >= numElements || index < 0) {
        throw std::out_of_range("Index is out of bounds");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

//assignment operator
template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& lst) {
    ListNode<T>* curr = head;
    ListNode<T>* current = lst.head;
    while (current != nullptr && current->next != nullptr) {
        curr->data = current->data;
        curr = curr->next;
        current = current->next;
    }
    if (numElements > lst.numElements) {
        for (int i = lst.numElements; i < numElements; i++) {
            remove(i);
        }
    }
    else if (numElements < lst.numElements) {
        for (int i = numElements; i < lst.numElements; i++) {
            add(lst[i]->data);
        }
    }
    numElements = lst.numElements;
}

template<class T>
void LinkedList<T>::print() {
    if (head != nullptr) {
        ListNode<T>* current = head;
        while (current->next != nullptr) {
            std::cout << current->data;
            current = current->next;
        }
        std::cout << current->data;
    }
}

#endif

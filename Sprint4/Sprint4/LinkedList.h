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
        //constructors use member initialization syntax
        ListNode(): next(nullptr), prev(nullptr) {} //default constructor
        ListNode(T val): next(nullptr), prev(nullptr), data(val) {}
        ListNode(const ListNode<T>& rhs): next(nullptr), prev(nullptr), data(rhs.data) {}

    private:
        ListNode<T>* next; //pointer to next node
        ListNode<T>* prev; //pointer to previous node
        T data;
};

template<class T>
class LinkedList
{
    public:
        LinkedList(); //default constructor
        LinkedList(T); //constructor accepting a value
        LinkedList(const LinkedList<T>&); //copy constructor

        void add(T); //add to end
        void addToFront(T);
        T get(int);
        int size(); //returns number of elements in linked list
        void remove(int); //removes at index

        ~LinkedList();

        T& operator[](int);
        LinkedList<T>& operator=(const LinkedList<T>&); //assignment operator

        void copyAll(const LinkedList<T>&); //copies all data into this linked list
        void clear(); //clears all data and deallocates memory for nodes
        void print();

    private:
        ListNode<T>* head; //points to first element of linked list
        int numElements;
};

//default constructor
template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    numElements = 0;
}

//constructor that accepts a value to create a one-element linked list
template<class T>
LinkedList<T>::LinkedList(T val) {
    ListNode<T>* element = new ListNode<T>(val);
    head = element; //head now points to first payload-containing node
    element->prev = nullptr; //ensures element does not point to anything previous
    numElements = 1;
}

//copy constructor that sets this linked list equal to linked list parameter
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& lst) {
    if (lst.numElements == 0) { //edge case: if lst is empty, then initialize as if it were default constructor
        head = nullptr;
        numElements = 0;
    }
    else {
        copyAll(lst); //copies all elements from lst to this linked list
        numElements = lst.numElements;
    }
}

//adds value as a payload of a node to the end of this linked list
template<class T>
void LinkedList<T>::add(T val) {
    if (head == nullptr) { //edge case: if the list is empty
        head = new ListNode<T>(val); //head points to newly created node
    }
    else {
        ListNode<T>* current = head;
        while (current->next != nullptr) { //while the end of the linked list has not been reached
           current = current->next; //advancing to next listnode
        }
        ListNode<T>* temp = new ListNode<T>(val);
        current->next = temp; //attaches new node to end of linked list
        temp->prev = current; //connects nodes through backwards pointer
    }
    numElements++;
}

//adds value as payload of node at beginning of this linked list
template<class T>
void LinkedList<T>::addToFront(T val) {
    if (numElements == 0) { //edge case: if list is empty
        add(val);
    }
    else {
        ListNode<T>* temp = new ListNode<T>(val);
        temp->next = head; //sets temp to point at current first element
        temp->next->prev = temp; //sets current first element to point backwards at temp
        temp->prev = nullptr;
        head = temp; //head points to temp as first element
        numElements++;
    }
}

//returns value of element at index parameter
template<class T>
T LinkedList<T>::get(int index) {
    if (index >= numElements || index < 0) { //edge case: if index is not valid (0 to numElements-1)
        throw std::out_of_range("Index is out of bounds");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) { //iterates through linked list until node with index is found
        current = current->next;
    }
    return current->data; //return data payload contained by that node
}

//returns number of elements in this linked list
template<class T>
int LinkedList<T>::size() {
    return numElements;
}

//removes node at a parameter index
template<class T>
void LinkedList<T>::remove(int index) {
    if (index >= numElements || index < 0) { //edge case: if index is not valid (0 to numElements-1)
        throw std::out_of_range("Index is out of bounds");
    }

    if(numElements == 0) { //edge case: if list is empty already
        return;
    }
    else if (numElements == 1) { //edge case: if list has only one element
        delete head; //deletes and releases memory allocated to first and only element
        head = nullptr;
        numElements = 0;
    }
    else if (index == numElements-1) { //edge case: if last element is the one to be deleted
        ListNode<T>* current = head;
        for (int i = 0; i < numElements-1; i++) { //iterates to second to last element
            current = current->next;
        }
        delete current->next; //deletes next (and therefore last) element
        current->next = nullptr; //sets forward looking pointer to null
        numElements--;
    }
    else {
        ListNode<T>* current = head;
        for (int i = 0; i < index; i++) { //iterates to element to be deleted
            current = current->next;
        }
        //reassigns forward pointer of previous node and backward pointer of next node to connect previous and next nodes to each other
        current->next->prev = current->prev;
        current->prev->next = current->next;
        delete current;
        numElements--;
    }
}

//destructor to release memory allocated in creating nodes
template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

//returns reference to element value at a parameter index in this linked list
template<class T>
T& LinkedList<T>::operator[](int index) {
    //identical code to get method
    if (index >= numElements || index < 0) {
        throw std::out_of_range("Index is out of bounds");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

//assignment operator that performs deep copy of nodes and payload
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& lst) {
    clear(); //deallocates all memory and destroys nodes/payloads

    if (lst.numElements == 0) {
        head = nullptr; //default constructor-like code
        numElements = 0;
    }
    else {
        copyAll(lst); //calls method to copy all elements in parameter lst
        numElements = lst.numElements;
    }

    return *this;
}

//copies all data from parameter lst into this linked list
template<class T>
void LinkedList<T>::copyAll(const LinkedList<T>& lst) {
    head = new ListNode<T>(lst.head->data); //head points to newly created first node based on first value of lst
    ListNode<T>* current = lst.head->next; //sets current pointer at second node of lst
    while (current != nullptr) { //iterates until end of the parameter list
        add(current->data); //calls add function to properly allocate memory for new node
        current = current->next; //advances to next node with data to be copied
    }
    numElements = lst.numElements;
}

//releases all memory allocated to nodes and destroys nodes and their payloads
template<class T>
void LinkedList<T>::clear() {
    if (numElements != 0) { //if linked list isn't already empty
        if (numElements == 1) { //edge case: if only contains one element
            delete head;
        }
        else {
            while (head != nullptr) {
                ListNode<T>* current = head; //current points to element pointed to by head before head advances
                head = head->next; //head points to next element
                //current->next = nullptr;
                delete current; //deletes and deallocates pointers of node just vacated by head
            }
        }
    }
    numElements = 0;
}

//prints out all payloads of this linked list
template<class T>
void LinkedList<T>::print() {
    if (head != nullptr) { //if list is not empty
        ListNode<T>* current = head;
        while (current->next != nullptr) { //while there is a valid next element
            std::cout << current->data; //print current payload
            current = current->next; //advance pointer to next element
        }
        std::cout << current->data; //print last node's payload (which did not print through while loop)
    }
}

#endif

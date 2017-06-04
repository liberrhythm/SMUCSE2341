/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/17/17
Program Number: Sprint2
Purpose:        Provides custom templated vector class definition using dynamically allocated memory and overloaded operators
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <iostream>
#include <stdexcept>

//using namespace std;

template<typename T>
class Vector {

    private:
        int length;
        int capacity;
        T* arr;

    public:
        Vector(); //default, non-parameterized constructor
        Vector(const int); //constructor with capacity parameter
        Vector(const Vector<T>&); //copy constructor

        Vector<T>& operator= (const Vector<T>&);

        T& operator[] (const int); //finds element at specified index

        int size();
        int getCapacity();
        void resize();
        void push_back(const T&); //adds element to end of vector
        void pop_back(); //removes element from end of vector
        void remove(int); //removes element at a specified index
        bool empty(); //checks if vector has no items of typename T

        int contains(const T&);

        ~Vector();
};

//No argument (default) constructor
template<typename T>
Vector<T>::Vector() {
    length = 0;
    capacity = 10;
    arr = new T[capacity]; //arr contains no items of typename T yet
}

//Parameterized constructor allowing user to define amount of capacity allotted
template<typename T>
Vector<T>::Vector(int cap) {
    length = 0;
    capacity = cap;
    arr = new T[capacity];
}

//Parameterized constructor taking a Vector object to instantiate this Vector
template<typename T>
Vector<T>::Vector(const Vector<T>& v) {
    length = v.length;
    capacity = v.capacity;
    arr = new T[capacity];
    for (int i = 0; i < length; i++) {
        arr[i] = v.arr[i]; //assigning parameter vector's contents to this Vector
    }
}

//Overloaded assignment operator to assign vectors to other, already-instantiated vectors
template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& v) {
    if (length != v.length || capacity != v.capacity) { //tests to see if data member values are not equal to parameter values
        delete[] arr; //releases memory
        length = v.length;
        capacity = v.capacity;
        arr = new T[capacity]; //dynamically reallocates memory
    }
    for (int i = 0; i < length; i++) {
        arr[i] = v.arr[i]; //assigns parameter vector contents to this vector
    }
    return *this; //returns reference to vector
}

//Overloaded subscript operator that returns element by reference at specified index parameter
template<typename T>
T& Vector<T>::operator[] (const int index) {
    if (index >= length) { //if index is not a location in vector that contains an item of typename T
        throw std::out_of_range("OUT OF RANGE");
    }
    else {
        return arr[index]; //normal searching based on typical 0 to length-1 cases
    }
}

//Returns number of elements in vector
template<typename T>
int Vector<T>::size() {
    return length;
}

//Returns amount of memory blocks dynamically allocated in vector
template<typename T>
int Vector<T>::getCapacity() {
    return capacity;
}

//Releases and reallocates more memory in data member arr for vector's storing of primitives/objects
template<typename T>
void Vector<T>::resize() {
    capacity += 10;
    T* temp = new T[capacity]; //copy elements of arr to a temporary array
    for (int i = 0; i < length; i++) {
        temp[i] = arr[i];
    }
    delete[] arr; //delete elements of and release memory in private data member array

    arr = new T[capacity];
    for (int i = 0; i < length; i++) {
        arr[i] = temp[i]; //copy elements from temp to reallocated memory in arr
    }
    delete[] temp; //delete elements of and release memory in temporary array
}

//Allows addition of item of typename T to end of vector
template<typename T>
void Vector<T>::push_back(const T& item) {
    if (length == capacity) { //allocates more capacity if no space for new item
        resize();
    }
    arr[length] = item;
    length++;
}

//Allows elimination of item of typename T at end of vector
template<typename T>
void Vector<T>::pop_back() {
    if (length-1 == 0) { //if deleting the first item in the vector
        length--;
        delete[] arr;
        arr = new T[capacity]; //dynamically allocate arr with no items
    }
    else {
        T* temp = new T[capacity]; //copy elements of arr to a temporary array
        for (int i = 0; i < length-1; i++) {
            temp[i] = arr[i]; //only copy elements up to second to last element
        }
        delete[] arr; //delete elements of and release memory in private data member array

        length--; //reduces size of vector by one
        arr = new T[capacity];
        for (int i = 0; i < length; i++) {
            arr[i] = temp[i];
        }
        delete[] temp; //release memory in temporary array
    }
}

//Allows elimination of item of typename T at a specified index
template<typename T>
void Vector<T>::remove(int index) {
    if (index == length-1) { //if deleting the last item in the vector
        pop_back();
    }
    else if (index == 0) { //if deleting the first item in the vector
        T* temp = new T[capacity];
        for (int i = 1; i < length; i++) { //copy elements of arr after index 0 to a temporary array
            temp[i-1] = arr[i];
        }

        delete[] arr; //delete elements of and release memory in private data member array
        length--; //reduce size of vector by one

        for (int i = 0; i < length; i++) { //copy elements back into arr from temp
            arr[i] = temp[i];
        }

        delete[] temp; //delete memory allocated to temp
    }
    else {
        T* frontTemp = new T[capacity]; //copy elements of arr before index to a temporary array
        for (int i = 0; i < index; i++) {
            frontTemp[i] = arr[i]; //only copy elements up to element before index
        }

        T* backTemp = new T[capacity]; //copy elements of arr after index to a temporary array
        for (int i = index+1; i < length; i++) {
            backTemp[i+index+1] = arr[i]; //only copy elements after index
        }

        delete[] arr; //delete elements of and release memory in private data member array

        length--; //reduces size of vector by one
        arr = new T[capacity];
        for (int i = 0; i < index; i++) {
            arr[i] = frontTemp[i];
        }

        for (int i = index; i < length; i++) {
            arr[i] = frontTemp[i-index];
        }

        delete[] frontTemp; //release memory in temporary arrays
        delete[] backTemp;
    }
}

//Tests to see if there are any items of typename T in vector
template<typename T>
bool Vector<T>::empty() {
    if (length == 0) {
        return true;
    }
    return false;
}

//Returns index in vector if element is in vector or -1 otherwise
template<typename T>
int Vector<T>::contains(const T& element) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

//Destructor for private data member arr and releases dynamically allocated memory
template<typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

#endif // DSVECTOR_H

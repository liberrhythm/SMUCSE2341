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
        Vector();
        //Vector(const T*);
        Vector(const Vector<T>&); //copy constructor

        //Vector& operator= (const T*);
        Vector<T>& operator= (const Vector<T>&);

        //these depend on if custom classes have ==, >
        //bool operator== (const T*);
        //bool operator== (const Vector&);
        //bool operator> (const Vector&);
        T& operator[] (const int); //finds element at specified index

        int size();
        int capacity();
        void resize();
        void push_back(const T&); //adds element to end of vector
        void pop_back(); //removes element from end of vector
        //void insert(int, T);
        bool empty(); //checks if if length of String is zero

        ~Vector();

};

//No argument constructor
template<typename T>
Vector<T>::Vector() {
    length = 0;
    capacity = 10;
    arr = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v) {
    length = v.length;
    capacity = v.capacity;
    arr = new T[capacity];
    for (int i = 0; i < length; i++) {
        arr[i] = v.arr[i];
    }
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& v) {
    if (length != v.length || capacity != v.capacity) {
        length = v.length;
        capacity = v.capacity;
        arr = new T[capacity];
    }
    for (int i = 0; i < length; i++) {
        arr[i] = v.arr[i];
    }
    return *this;
}

//index could be out of range, negative indices???
template<typename T>
T& Vector<T>::operator[] (const int index) {
    if (index >= length) { //if index is out of normal range or equal to each other
        if (index == 0) { //if index == length == 0
            return arr[index];
        }
        else {
            throw std::out_of_range("OUT OF RANGE");
        }
    }
    else {
        return arr[index]; //normal searching based on typical 0 to length-1 cases
    }
}

template<typename T>
int Vector<T>::size() {
    return length;
}

template<typename T>
int Vector<T>::capacity() {
    return capacity;
}

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
        arr[i] = temp[i];
    }
    //delete[] temp; //delete elements of and release memory in temporary array, needed???
}

//edge cases: if capacity is not big enough, resize!
template<typename T>
void Vector<T>::push_back(const T& item) {
    if (length == capacity) {
        resize();
    }
    arr[length] = item;
    length++;
}

template<typename T>
void Vector<T>::pop_back() {
    //delete arr[length];
    //arr[length] = NULL;
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
}

template<typename T>
bool Vector<T>::empty() {
    if (length == 0) {
        return true;
    }
    return false;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

#endif // DSVECTOR_H

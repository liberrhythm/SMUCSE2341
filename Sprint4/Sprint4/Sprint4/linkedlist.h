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

    private:
        ListNode<T>* head;
        int numElements;
};

template<class T>
LinkedList::LinkedList() {
    head->next = nullptr;
    numElements = 0;
}

template<class T>
LinkedList::LinkedList(T val) {
    ListNode* element = new ListNode(val);
    head->next = element;
    element->prev = nullptr; //already initalized to nullptr in listnode class?
    numElements++;
}

//copy constructor
template<class T>
LinkedList::LinkedList(const LinkedList<T>& lst) {
    head->next = lst.head->next;
    head->prev = lst.head->prev;
    //iterate through lst and make copies of ListNodes
    ListNode* current = lst.head->next;
    while(current != nullptr && current->next != nullptr) { //do we need this: && current != nullptr
        /*
        ListNode temp;
        temp.data = current->data;
        temp.next = current->next;
        temp.prev = current->prev;
        */
        add(current->data);
    }
    numElements = lst.numElements;
}

template<class T>
void LinkedList::add(T val) {
    if (head == nullptr) {
        head = new ListNode(val);
    }
    else {
        ListNode* current = head;
        while (current->next != nullptr) {
           current = current->next; //advancing to next listnode
        }
        ListNode* temp = newListNode(val);
        current->next = temp;
        temp->prev = current;
    }
    numElements++;
}

template<class T>
void LinkedList::addToFront(T val) {
    ListNode* temp = new ListNode(val);
    temp->next = head;
    temp->prev = nullptr; //not needed?
    head = temp;
    numElements++;
}

template<class T>
T LinkedList::get(int index) {
    if (index >= numElements || index < 0) {
        throw std::out_of_range("Index is out of bounds");
    }
    ListNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<class T>
int LinkedList::size() {
    return numElements;
}

template<class T>
T LinkedList::remove(int index) {
    if (index >= numElements || index < 0) {
        throw std::out_of_range("Index is out of bounds");
    }
    ListNode* current = head;
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
LinkedList::~LinkedList() {
    ListNode* current = head;
    for (int i = 0; i < numElements; i++) { //does this actually do anything...
        delete current;
        current = current->next;
    }
    delete current;
}

template<class T>
T& LinkedList::operator[](int index) {
    if (index >= numElements || index < 0) {
        throw std::out_of_range("Index is out of bounds");
    }
    ListNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

//assignment operator
template<class T>
LinkedList<T>& LinkedList::operator=(LinkedList<T>& lst) {

}

#endif

#include "string.h"

String::String() {
    length = 0;
    capacity = 25;
    arr = new char[capacity];
}

String::String(const char*) {

}

String::String(const String&){

}

String& String::operator= (const char*) {

}

String& String::operator= (const String& s) {
    length = s.length;
    capacity = s.capacity;
    arr = new char[capacity];
    for (int i = 0; i < length; i++) {
        arr[i] = s.arr[i];
    }
}

String String::operator+ (const String& s) {
    if (this->capacity > this->length + s.size()) {

    }
    else {

    }
}

bool String::operator== (const char*) {

}

bool String::operator== (const String& s){
    bool b = True;
    if (length == s.length) {
        for (int i = 0; i < length; i++) {
            if (this[i] != s[i]) {
                b = False;
            }
        }
    }
    else {
        b = False;
    }
    return b;
}

bool String::operator> (const String& s) {
    for(int i = 0; i < length; i++) {
        if (this[i] < s[i]) {
            return False;
        }
    }
    return True;
}

char& String::operator[] (const int index) {
    for(int i = 0; i < length; i++) {
        if (i == index) {
            return this[i];
        }
    }
}

int String::size() {
    return length;
}

String String::substring(int start, int end) {

}

char* String::c_str() { //get cstring equivalent
    char* arr = this;
    return arr;
}

char& String::find() {

}

bool String::empty() {
    if (length == 0) {
        return True;
    }
    return False;
}

friend ostream& operator<< (ostream& output, const String& s) {
    for(int i = 0; i < length; i++) {
        output << s[i];
    }
    return output;
}

~String() {
    delete[] arr;
}

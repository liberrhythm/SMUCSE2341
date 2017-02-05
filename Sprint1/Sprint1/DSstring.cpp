#include "dsstring.h"

using namespace std;

String::String() {
    length = 0;
    arr = new char[length];
}

String::String(const char* c) {
    length = static_cast<int>(strlen(c));
    arr = new char[length];
    for (int i = 0; i < length; i++) {
        arr[i] = c[i];
    }
}

//this is like String string2 = string1
String::String(const String& s){
    length = s.length;
    arr = new char[length];
    for (int i = 0; i < length; i++) {
        arr[i] = s.arr[i];
    }
}

//used String constructor with char* parameter
//this is like string2 = string1
String& String::operator= (const char* c) {
    if (length != static_cast<int>(strlen(c))) {
        delete[] arr;
        length = static_cast<int>(strlen(c));
        arr = new char[length];
    }
    for (int i = 0; i < length; i++) {
        arr[i] = c[i];
    }
    return *this;
}

//used String constructor with String parameter
String& String::operator= (const String& s) {
    if (length != s.length) {
        delete[] arr;
        length = s.length;
        arr = new char[length];
    }
    for (int i = 0; i < length; i++) {
        arr[i] = s.arr[i];
    }
    return *this;
}

//NOT FIXED--used String constructor with char* parameter
String String::operator+ (const String& s) {
    int newLength = length + s.length;
    char* temp = new char[newLength];
    for (int i = 0; i < length; i++) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < s.length; i++) {
        temp[i+length] = s.arr[i];
    }
    String newString(temp);
    return newString;
}

bool String::operator== (const char* c) {
    if (length != static_cast<int>(strlen(c))) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (arr[i] != c[i]) {
            return false;
        }
    }
    return true;
}

bool String::operator== (const String& s){
    if (length != s.length) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (arr[i] != s.arr[i]) {
            return false;
        }
    }
    return true;
}

//fixed errors with char by char comparison
bool String::operator> (const String& s) {
    /*
    for(int i = 0; i < length; i++) {
        int x = arr[i];
        int y = s.arr[i];
        if (x > y) {
            return true;
        }
        else if (x < y){
            return false;
        }
        else {
            continue;
        }
    }
    return false;
    */
    int value = strcmp(arr, s.arr);
    if (value > 0) {
        return true;
    }
    else {
        return false;
    }
}

//have to add edge case tests --> negative numbers
char& String::operator[] (const int index) {
    if (index >= length) {
        throw std::out_of_range("OUT OF RANGE");
    }
    else if (index < 0) {
        return arr[index+length];
    }
    else {
        return arr[index];
    }
}

int String::size() {
    return length;
}

//fixing negative indices
String String::substring(int start, int end) {
    if (start >= length || end >= length){
        throw std::invalid_argument("INVALID RANGE");
    }
    else if (start < 0 && end < 0){
        char* temp = new char[end-start];
        for (int i = start+length; i < end+length; i++) {
            temp[i] = arr[i];
        }
        String newString(temp);
        return newString;
    }
    //else if (start )
    else {
        char* temp = new char[end-start];
        for (int i = start; i < end; i++) {
            temp[i] = arr[i];
        }
        String newString(temp);
        return newString;
    }
}

char* String::c_str() { //get cstring equivalent
    char* c = new char[length];
    strcpy(c, arr);
    return c;
}

bool String::empty() {
    if (length == 0) {
        return true;
    }
    return false;
}

ostream& operator<< (ostream& output, const String& s) {
    for(int i = 0; i < s.length; i++) {
        output << s.arr[i];
    }
    return output;
}

String::~String() {
    delete[] arr;
}

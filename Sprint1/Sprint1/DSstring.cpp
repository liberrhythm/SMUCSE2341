#include "DSString.h"

using namespace std;

String::String() {
    length = 0;
    arr = new char[length+1];
    arr[0] = '\0';
}

String::String(const char* c) {
    length = static_cast<int>(strlen(c));
    arr = new char[length+1];
    for (int i = 0; i < length; i++) {
        arr[i] = c[i];
    }
    arr[length] = '\0';
}

//this is like String string2 = string1
String::String(const String& s){
    length = s.length;
    arr = new char[length+1];
    for (int i = 0; i < length; i++) {
        arr[i] = s.arr[i];
    }
    arr[length] = '\0';
}

//used String constructor with char* parameter
//this is like string2 = string1
String& String::operator= (const char* c) {
    if (length != static_cast<int>(strlen(c))) {
        delete[] arr;
        length = static_cast<int>(strlen(c));
        arr = new char[length+1];
        arr[length] = '\0';
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
        arr = new char[length+1];
        arr[length] = '\0';
    }
    for (int i = 0; i < length; i++) {
        arr[i] = s.arr[i];
    }
    return *this;
}

String String::operator+ (const String& s) {
    int newLength = length + s.length;
    char* temp = new char[newLength+1];
    temp[newLength] = '\0';
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
    int value = strcmp(arr, s.arr);
    if (value > 0) {
        return true;
    }
    else {
        return false;
    }
}

char& String::operator[] (const int index) {
    if (index >= length) {
        if (index == 0) {
            return arr[index];
        }
        else {
            throw std::out_of_range("OUT OF RANGE");
        }
    }
    else if (index < 0) {
        return arr[index+length];
    }
    else {
        return arr[index];
    }
}

int String::size() {
    return static_cast<int>(strlen(arr));
}

String String::substring(int start, int end) {
    if (start >= length || end >= length){
        throw std::out_of_range("OUT OF RANGE");
    }
    else if (start < 0 && end < 0){
        int subLength = end-start;
        char* temp = new char[subLength+1];
        temp[subLength] = '\0';
        for (int i = 0; i < subLength; i++) {
            temp[i] = arr[length-abs(start)+i+1];
        }
        String newString(temp);
        return newString;
    }
    else if (abs(start) > abs(end)) {
        throw std::invalid_argument("INVALID RANGE");
    }
    else if (end < 0) {
        int subLength = length-abs(end)+1;
        char* temp = new char[subLength+1];
        temp[subLength] = '\0';
        for (int i = 0; i < subLength; i++) {
            temp[i] = arr[i];
        }
        String newString(temp);
        return newString;
    }
    else {
        int subLength = end-start;
        char* temp = new char[subLength+1];
        temp[subLength] = '\0';
        for (int i = 0; i < subLength; i++) {
            temp[i] = arr[start+i];
        }
        String newString(temp);
        return newString;
    }
}

char* String::c_str() { //get cstring equivalent
    return arr;
}

bool String::empty() {
    if (length == 0) {
        return true;
    }
    return false;
}

ofstream& operator<< (ofstream& output, const String& s) {
    for(int i = 0; i < s.length; i++) {
        output << s.arr[i];
    }
    return output;
}

ifstream& operator>> (std::ifstream& input, String& s) {
    const int sizeOfBuffer = 100;
    char buffer[sizeOfBuffer];
    input.getline(buffer, sizeOfBuffer, '\n');
    s = String(buffer);
    input.clear();
    return input;
}

String::~String() {
    delete[] arr;
}

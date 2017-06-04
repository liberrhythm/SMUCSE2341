/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Defines and provides implementation for custom String class functions
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#include "DSString.h"
using namespace std;

//instantiates String object without parameter as default constructor
String::String() {
    length = 0;
    arr = new char[length+1];
    arr[0] = '\0';
}

//instantiates String object using char* parameter
String::String(const char* c) {
    length = static_cast<int>(strlen(c)); //assigns length of char* to String length private variable
    arr = new char[length+1]; //dynamically allocates memory for arr private variable to store String char data
    for (int i = 0; i < length; i++) {
        arr[i] = c[i];
    }
    arr[length] = '\0'; //adds null character to last space in arr
}

//instantiates String object using String parameter - copy constructor
String::String(const String& s){
    length = s.length;
    arr = new char[length+1];
    for (int i = 0; i < length; i++) {
        arr[i] = s.arr[i];
    }
    arr[length] = '\0'; //adds null character to last space in arr
}

//overloads equality operator with char* parameter (no instantiation)
String& String::operator= (const char* c) {
    if (length != static_cast<int>(strlen(c))) { //if length of String and of new char* are not equal
        delete[] arr; //release memory
        length = static_cast<int>(strlen(c)); //reinstantiate String private data members
        arr = new char[length+1];
        arr[length] = '\0';
    }
    for (int i = 0; i < length; i++) {
        arr[i] = c[i];
    }
    return *this; //return dereferenced this to allow for chaining
}

//overloads equality operator with String reference parameter, as in cases of string1 = string2
String& String::operator= (const String& s) {
    if (length != s.length) { //if lengths of Strings are not equal
        delete[] arr; //release memory
        length = s.length; //reinstantiate String data members
        arr = new char[length+1];
        arr[length] = '\0';
    }
    for (int i = 0; i < length; i++) {
        arr[i] = s.arr[i];
    }
    return *this; //return dereferenced this to allow for string1 = string2 = string3 chaining
}

//returns concatenated String with parameter String attached to end of this String
String String::operator+ (const String& s) {
    int newLength = length + s.length; //establish a new length encompassing both Strings
    char* temp = new char[newLength+1]; //create char array with new length
    temp[newLength] = '\0';
    for (int i = 0; i < length; i++) { //copy first String contents to temporary char array
        temp[i] = arr[i];
    }
    for (int i = 0; i < s.length; i++) { //copy second String contents to temporary char array
        temp[i+length] = s.arr[i]; //starting from where first String left off
    }
    String newString(temp); //create new String based on constructor with char* parameter
    return newString;
}

//returns boolean based on whether a String and a char* have the same contents
bool String::operator== (const char* c) {
    if (length != static_cast<int>(strlen(c))) { //if lengths of String and char array are not equal
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (arr[i] != c[i]) { //if corresponding elements in String and char array are not equal
            return false;
        }
    }
    return true;
}

//returns boolean based on whether two Strings have the same contents
bool String::operator== (const String& s){
    if (length != s.length) { //if lengths of Strings are not equal
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (arr[i] != s.arr[i]) { //if corresponding String elements in data member char arrays are not equal
            return false;
        }
    }
    return true;
}

//compares two Strings to see which one comes later in the alphabet
bool String::operator> (const String& s) {
    int value = strcmp(arr, s.arr); //uses cstring function to compare two char arrays
    if (value > 0) { //String1 is later in the alphabet than String2
        return true;
    }
    else { //String2 is later in the alphabet than String1 or they are the same string
        return false;
    }
}

//overloads subscript operator to get char at a certain index
char& String::operator[] (const int index) {
    if (index >= length) { //if index is out of normal range or equal to each other
        if (index == 0) { //if index == length == 0
            return arr[index];
        }
        else {
            throw std::out_of_range("OUT OF RANGE");
        }
    }
    else if (index < 0) {
        return arr[index+length]; //returns char going backwards from String by index parameter
    }
    else {
        return arr[index]; //normal searching based on typical 0 to length-1 cases
    }
}

//returns number of chars in char array data member, or length
int String::size() {
    return static_cast<int>(strlen(arr));
}

//returns section of String based on beginning and ending indices
String String::substring(int start, int end) {
    if (start >= length || end >= length){ //if indices exceed range of existing char array data member
        throw std::out_of_range("OUT OF RANGE");
    }
    else if (start < 0 && end < 0){ //if both indices are negative
        int subLength = end-start;
        char* temp = new char[subLength+1]; //create new temporary array based on new length
        temp[subLength] = '\0';
        for (int i = 0; i < subLength; i++) {
            temp[i] = arr[length-abs(start)+i+1]; //assigns char from arr based on formula one by one to temp char array
        }
        String newString(temp);
        return newString;
    }
    else if (abs(start) > abs(end)) { //if start > end with no negative numbers
        throw std::invalid_argument("INVALID RANGE");
    }
    else if (end < 0) { //if only end is negative and start == 0
        int subLength = length-abs(end)+1;
        char* temp = new char[subLength+1];
        temp[subLength] = '\0';
        for (int i = 0; i < subLength; i++) { //only adds char to temp array up until negative index ending
            temp[i] = arr[i];
        }
        String newString(temp);
        return newString;
    }
    else { //getting normal 0 to positive or positive to positive substring
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

//returns char array version of String, contained within arr data member
char* String::c_str() { //get cstring equivalent
    return arr;
}

//tests to see if length is 0 or String is empty
bool String::empty() {
    if (length == 0) {
        return true;
    }
    return false;
}

//provides implementation to print out custom String object by overloading stream insertion operator
ostream& operator<< (ostream& output, const String& s) {
    for(int i = 0; i < s.length; i++) {
        output << s.arr[i]; //prints out character by character in char array data member of String
    }
    return output;
}

//destroys and frees dynamically allocated memory
String::~String() {
    delete[] arr;
}

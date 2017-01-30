#include "string.h"

String::String() {

}

String::String(const char*) {

}

String::String(const String&){

}

String& String::operator= (const char*) {

}

String& String::operator= (const String&) {

}

String String::operator+ (const String&) {

}

bool String::operator== (const char*) {

}

bool String::operator== (const String&){

}

bool String::operator> (const String&) {

}

char& String::operator[] (const int) {

}

int String::length() {

}

String String::substring(int, int) {

}

char* String::c_str() { //get cstring equivalent

}

char& String::find() {

}

bool String::empty() {

}

friend ostream& operator<< (ostream&, const String&) {

}

~String() {

}

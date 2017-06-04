/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Provides custom implemented string class definition using cstring functions and overloaded operators
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <fstream>

//using namespace std;

class String {

    friend std::ostream& operator<< (std::ostream&, const String&); //overloaded insertion operator

    private:

        int length;
        char* arr;

    public:

        //constructors for custom String class
        String();
        String(const char*);
        String(const String&); //copy constructor

        String& operator= (const char*);
        String& operator= (const String&);
        String operator+ (const String&);
        bool operator== (const char*);
        bool operator== (const String&);
        bool operator> (const String&);
        char& operator[] (const int);

        int size();
        String substring(int, int);
        char* c_str(); //returns cstring equivalent of String
        bool empty(); //checks if if length of String is zero

        ~String();

};
#endif

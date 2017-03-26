/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           3/25/17
Program Number: Sprint4
Purpose:        Implements functionality for a custom doubly linked list class with a list node struct
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/


#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <LinkedList.h>

using namespace std;

#define TEST true
int runCatchTests(int argc, char* const argv[]) {
    return Catch::Session().run(argc, argv);
}
int main(int argc, char* const argv[]) {
    if(TEST)
    {
        return runCatchTests(argc, argv);
    }
    return 0;
}

/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Represents a flight leg with a specified time and cost for addition into adjacency list
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef AIRPORT_H
#define AIRPORT_H

#include "DSString.h"
#include "DSVector.h"
#include <iostream>

class Airport {
    public:
        Airport();
        Airport(String);
        Airport(String, double, int);
        bool operator==(const Airport&); //overloaded equality operator
        String getName();
        void setName(String);
        double getCost();
        void setCost(double);
        int getTime();
        void setTime(int);

        void print(); //test function to print data contained in Airport object

    private:
        String name;
        double cost;
        int time;
};

#endif // AIRPORT_H

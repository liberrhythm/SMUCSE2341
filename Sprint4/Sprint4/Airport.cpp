/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Defines and provides implementation for data members/functions in Airport header file
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#include "Airport.h"

//default constructor with empty name, cost, and time
Airport::Airport() {
    setName("");
    setCost(0);
    setTime(0);
}

//constructor for head (departure) nodes of linkedlists in adjacency list
Airport::Airport(String name) {
    setName(name);
    setCost(0);
    setTime(0);
}

//constructor for arrival nodes attached to head nodes in linkedlists
Airport::Airport(String name, double cost, int time) {
    setName(name);
    setCost(cost);
    setTime(time);
}

//overloaded equality operator to see if two Airports are equal
bool Airport::operator==(const Airport& a) {
    if (name == a.name) {
        return true;
    }
    return false;
}

//getter for Airport name
String Airport::getName() {
    return name;
}

//setter for Airport name
void Airport::setName(String n) {
    name = n;
}

//getter for Airport cost
double Airport::getCost() {
    return cost;
}

//setter for Airport cost
void Airport::setCost(double c) {
    cost = c;
}

//getter for Airport time
int Airport::getTime() {
    return time;
}

//setter for Airport time
void Airport::setTime(int t) {
    time = t;
}

//prints out Airport private member data
void Airport::print() {
    std::cout << name << " " << cost << " " << time << std::endl;
}

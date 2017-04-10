/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Reads in flight data and requested data and finds possible paths using iterative backtracking
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include "FlightPlan.h"
#include "Airport.h"
#include "Stack.h"
#include "LinkedList.h"
#include "DSString.h"
#include "DSVector.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class FlightPlan {
    public:
        FlightPlan(char*); //constructor to initialize adjacency list
        void addAirport(String, String, double, int); //add arrival node to linkedlist
        int headExists(String);
        bool cityExists(String, int);
        void readRequestedFlights(char*, char*); //reads requested flight data

        Vector<LinkedList<Airport>>& getAdjList();
        void printFlightData(); //prints out adjacency list

        void findPaths(Airport, String); //uses iterative backtracking to find paths
        void outputPaths(ofstream&, char); //outputs paths to file

    private:
        Vector<LinkedList<Airport>> adjList; //contains data from undirected graph created by flight data file
        Stack<Airport> path;
        Vector<Stack<Airport>> allPaths; //contains all possible paths for a requested flight
};

#endif // FLIGHTPLAN_H


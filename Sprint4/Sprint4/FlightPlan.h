#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include "FlightPlan.h"
#include "Airport.h"
#include "LinkedList.h"
#include "Stack.h"
#include "DSString.h"
#include "DSVector.h"
#include <fstream>
#include <iostream>

using namespace std;

class FlightPlan {
    public:
        FlightPlan(char*);
        void addAirport(String, String, int, int);
        int headExists(String);
        bool cityExists(String, int);
        void readRequestedFlights(char*, char*);

        Vector<LinkedList<Airport>>& getAdjList();
        void printFlightData();

        void findPaths(Airport, String);
        void outputPaths(char*);

    private:
        Vector<LinkedList<Airport>> adjList;
        Stack<Airport> path;
        Vector<Stack<Airport>> allPaths;
};

#endif // FLIGHTPLAN_H


#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include "FlightPlan.h"
#include "Airport.h"
#include "Stack.h"
//#include "FlightPath.h"
#include "LinkedList.h"
#include "DSString.h"
#include "DSVector.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class FlightPlan {
    public:
        FlightPlan(char*);
        void addAirport(String, String, double, int);
        int headExists(String);
        bool cityExists(String, int);
        void readRequestedFlights(char*, char*);

        Vector<LinkedList<Airport>>& getAdjList();
        void printFlightData();

        void findPaths(Airport, String);
        void outputPaths(ofstream&, char);

    private:
        Vector<LinkedList<Airport>> adjList;
        Stack<Airport> path;
        //Vector<FlightPath> allPaths;
        Vector<Stack<Airport>> allPaths;
};

#endif // FLIGHTPLAN_H


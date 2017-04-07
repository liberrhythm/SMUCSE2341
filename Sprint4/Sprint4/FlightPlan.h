#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include "DSString.h"
#include "LinkedList.h"
#include "Airport.h"
#include <fstream>
#include <iostream>

using namespace std;

class FlightPlan {
    public:
        FlightPlan(char*);
        void addAirport(String, String, int, int);
        int headExists(String);
        bool cityExists(String, int);
        void readRequestedFlights(char*);

        LinkedList<LinkedList<Airport>>& getAdjList();
        void printFlightData();

    private:
        LinkedList<LinkedList<Airport>> adjList;
};

#endif // FLIGHTPLAN_H


#include "FlightPlan.h"

FlightPlan::FlightPlan(char* flightData) {
    ifstream inFile;
    inFile.open(flightData, ios::in);

    if (!inFile) {
        cerr << "Flight data file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int numConnections;
    inFile >> numConnections;
    char depart[81];
    char arrive[81];
    int cost;
    int time;

    inFile >> depart;

    while (!inFile.eof()) {
        cin.ignore();
        inFile >> arrive;
        cin.ignore();
        inFile >> cost;
        cin.ignore();
        inFile >> time;

        String departure(depart);
        String arrival(arrive);

        addAirport(departure, arrival, cost, time);
        addAirport(arrival, departure, cost, time);

        inFile >> depart;
    }
    inFile.close();
}

void FlightPlan::addAirport(String departure, String arrival, int cost, int time) {
    int indexLoc = headExists(departure);
    if (indexLoc == -1) {
        Airport a(departure);
        LinkedList<Airport> newList(a);
        adjList.add(newList);
    }
    else {
        bool locExists = cityExists(arrival, indexLoc);
        if (locExists == false) {
            Airport dest(arrival, cost, time);
            adjList[indexLoc].add(dest);
        }
    }
}

int FlightPlan::headExists(String city) {
    int indexLoc = -1;
    for (int i = 0; i < adjList.size(); i++) {
        if (adjList[i].get(0).getName() == city) {
            return i;
        }
    }
    return indexLoc;
}

bool FlightPlan::cityExists(String city, int indexLoc) {
    for (int i = 0; i < adjList[indexLoc].size(); i++) {
        if (adjList[indexLoc][i].getName() == city) {
            return true;
        }
    }
    return false;
}

void FlightPlan::readRequestedFlights(char* requestedFlights) {
    ifstream inFile;
    inFile.open(requestedFlights, ios::in);
    if (!inFile) {
        cerr << "Requested flight file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int numFlights;
    inFile >> numFlights;
    char depart[81];
    char arrive[81];
    int metric;

    inFile >> depart;

    while (!inFile.eof()) {
        cin.ignore();
        inFile >> arrive;
        cin.ignore();
        inFile >> metric;

        String departure(depart);
        String arrival(arrive);

        //call findPaths() method

        inFile >> depart;
    }

    inFile.close();
}

LinkedList<LinkedList<Airport>>& FlightPlan::getAdjList() {
    return adjList;
}

void FlightPlan::printFlightData() {
    for (int i = 0; i < adjList.size(); i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            adjList[i][j].print();
        }
    }
}


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
    inFile.ignore();
    char depart[81];
    char arrive[81];
    int cost;
    int time;

    inFile.getline(depart, 81, '|');

    while (!inFile.eof()) {
        inFile.getline(arrive, 81, '|');
        inFile >> cost;
        inFile.ignore();
        inFile >> time;
        inFile.ignore();

        String departure(depart);
        String arrival(arrive);

        addAirport(departure, arrival, cost, time);
        addAirport(arrival, departure, cost, time);

        printFlightData();

        inFile.getline(depart, 81, '|');
    }
    inFile.close();
}

void FlightPlan::addAirport(String departure, String arrival, int cost, int time) {
    int indexLoc = headExists(departure);
    if (indexLoc == -1) {
        Airport orig(departure);
        LinkedList<Airport> newList(orig);
        Airport dest(arrival, cost, time);
        newList.add(dest);
        adjList.push_back(newList);
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

void FlightPlan::readRequestedFlights(char* requestedFlights, char* outputFile) {
    //construct adjList for fun!!!
    Airport one("Dallas", 0, 0);
    Airport two("Austin", 98, 47);
    Airport three("Austin", 0, 0);
    Airport four("Houston", 95, 39);
    Airport six("Dallas", 98, 49);
    Airport seven("Houston", 0, 0);
    Airport eight("Austin", 95, 39);

    LinkedList<Airport> dallas(one);
    dallas.add(two);
    LinkedList<Airport> austin(three);
    austin.add(four);
    austin.add(six);
    LinkedList<Airport> houston(seven);
    houston.add(eight);

    adjList.push_back(dallas);
    adjList.push_back(austin);
    adjList.push_back(houston);

    ifstream inFile;
    inFile.open(requestedFlights, ios::in);
    if (!inFile) {
        cerr << "Requested flight file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream outFile;
    outFile.open(outputFile, ios::out);
    if (!outFile) {
        cerr << "Output file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int numFlights;
    inFile >> numFlights;
    inFile.ignore();
    char depart[81];
    char arrive[81];
    char metric;

    int currentFlight = 0;

    inFile.getline(depart, 81, '|');

    while (!inFile.eof()) {
        currentFlight++;

        inFile.getline(arrive, 81, '|');
        inFile >> metric;
        inFile.ignore();

        String departure(depart);
        String arrival(arrive);

        outFile << "Flight " << currentFlight << ": ";
        outFile << departure.c_str() << ", " << arrival.c_str() << " ";
        outFile << "(";

        if (metric == 'T') {
            outFile << "Time)" << endl;
        }
        else if (metric == 'C') {
            outFile << "Cost)" << endl;
        }

        if (!(departure == arrival)) {
            int aLoc;
            for (int i = 0; i < adjList.size(); i++) {
                if (adjList[i].get(0).getName() == departure) {
                    aLoc = i;
                }
            }
            findPaths(adjList[aLoc].get(0), arrival);
            outputPaths(outFile);
        }
        else {
            outFile << "No paths for same-city flights can be found" << endl;
        }

        inFile.getline(depart, 81, '|');
    }
    inFile.close();
    outFile.close();
}

Vector<LinkedList<Airport>>& FlightPlan::getAdjList() {
    return adjList;
}

//function used to test reading in of all data to adjacency list
void FlightPlan::printFlightData() {
    for (int i = 0; i < adjList.size(); i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            adjList[i][j].print();
        }
        cout << endl;
    }
}

//use iterative backtracking to find all paths starting with airport a and ending at destination b
void FlightPlan::findPaths(Airport a, String b) {
    for (int i = 0; i < adjList.size(); i++) {
        adjList[i].backtrack();
    }

    path.push(a); //add departure airport to path
    Airport temp = path.peek();

    while (!path.isEmpty()) { //while searching for all possible paths has not been finished
        int indexLoc;
        for (int i = 0; i < adjList.size(); i++) { //get index in vector of linkedlist with most recent airport as head
            if (adjList[i].get(0).getName() == temp.getName()) {
                indexLoc = i;
            }
        }

        if (adjList[indexLoc].hasNext()) {
            Airport next = adjList[indexLoc].getNext();
            if (!path.contains(next)) { //check to see if airport is already in the path
                path.push(next); //add next airport to stack
                if (path.peek().getName() == b) { //check to see if most recent airport is destination
                    allPaths.push_back(path); //add path to vector of paths
                    path.pop();
                }
            }
        }
        else { //if iterator has reached end of linkedlist
            adjList[indexLoc].reset(); //put iterator back at head
            adjList[indexLoc].backtrack();
            path.pop();
        }
    }
}

//prints to output file possible paths up to 3 or error message if no possible paths
void FlightPlan::outputPaths(ofstream& outFile) {
    if (allPaths.empty() == true) {
        outFile << "No paths could be found from requested departure city to requested arrival city." << endl;
    }
    else {
        int pathNum = 0;
        int totalCost = 0;
        int totalTime = 0;

        for (int i = 0; i < allPaths.size(); i++) {
            pathNum++;
            totalCost = 0;
            totalTime = 0;

            outFile << "Path " << pathNum << ": ";
            for (int j = 0; j < allPaths[i].size(); j++) {
                if (j == allPaths[i].size()-1) {
                    outFile << allPaths[i].get(j).getName().c_str() << ". ";
                }
                else {
                    outFile << allPaths[i].get(j).getName().c_str() << " -> ";
                }
                totalCost += allPaths[i].get(j).getCost();
                totalTime += allPaths[i].get(j).getTime();
            }
            outFile << "Time: " << totalTime << " ";
            outFile << "Cost: " << totalCost << endl << endl;
        }
    }

    while (allPaths.empty() == false) {
        allPaths.pop_back();
    }
}

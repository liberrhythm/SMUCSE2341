/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Defines and provides implementation for data members/functions in FlightPlan header file
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#include "FlightPlan.h"

//constructor that reads in flight data and initializes adjacency list
FlightPlan::FlightPlan(char* flightData) {

    ifstream inFile;
    inFile.open(flightData, ios::in);

    if (!inFile) {
        cerr << "Flight data file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int numConnections;
    inFile >> numConnections; //read in number of connections between different cities
    inFile.ignore();
    char depart[81];
    char arrive[81];
    double cost;
    int time;

    inFile.getline(depart, 81, '|'); //get departure city

    while (!inFile.eof()) {
        inFile.getline(arrive, 81, '|'); //get arrival city
        inFile >> cost; //get cost associated
        inFile.ignore();
        inFile >> time; //get time associated
        inFile.ignore();

        //create String objects from char arrays
        String departure(depart);
        String arrival(arrive);

        //add Airport data both directions
        addAirport(departure, arrival, cost, time);
        addAirport(arrival, departure, cost, time);

        //printFlightData();

        inFile.getline(depart, 81, '|'); //get next connection
    }
    inFile.close();
}

//adds a connection to the adjacency list, either as a departure node or arrival node
void FlightPlan::addAirport(String departure, String arrival, double cost, int time) {
    int indexLoc = headExists(departure); //checks to see if departure node already exists
    if (indexLoc == -1) { //if departure node does not exist
        Airport orig(departure); //create a departure node with cost and time as zero
        LinkedList<Airport> newList(orig); //create linkedlist with departure node as head
        Airport dest(arrival, cost, time); //create arrival node with associated cost and time
        newList.add(dest); //add to linkedlist with connected departure node
        adjList.push_back(newList); //add to adjacency list
    }
    else { //departure node already exists
        bool locExists = cityExists(arrival, indexLoc); //checks to see if arrival node exists in departure linkedlist
        if (locExists == false) {
            Airport dest(arrival, cost, time); //create new arrival node with associated cost and time
            adjList[indexLoc].add(dest); //add to existing departure linkedlist in adjacency list
        }
    }
}

//checks to see if departure node already exists in adjacency list
int FlightPlan::headExists(String city) {
    int indexLoc = -1;
    for (int i = 0; i < adjList.size(); i++) {
        //if there is a departure node as head of linkedlist with the same name as parameter
        if (adjList[i].get(0).getName() == city) {
            return i;
        }
    }
    return indexLoc;
}

//checks to see if arrival node already exists in departure linkedlist
bool FlightPlan::cityExists(String city, int indexLoc) {
    for (int i = 0; i < adjList[indexLoc].size(); i++) {
        //if there is an arrival node in departure linkedlist with the same name as parameter
        if (adjList[indexLoc][i].getName() == city) {
            return true;
        }
    }
    return false;
}

//reads in requested flight data and calls functions to find possible paths and output them
void FlightPlan::readRequestedFlights(char* requestedFlights, char* outputFile) {
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
    inFile >> numFlights; //reads in number of flights requested
    inFile.ignore();
    char depart[81];
    char arrive[81];
    char metric;

    int currentFlight = 0;

    inFile.getline(depart, 81, '|'); //read in requested departure location name

    while (!inFile.eof()) {
        currentFlight++;

        inFile.getline(arrive, 81, '|'); //read in requested arrival location name
        inFile >> metric; //read in cost or time as parameter for ordering output
        inFile.ignore();

        String departure(depart);
        String arrival(arrive);

        //print flight header
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
            //find departure linkedlist to start from
            for (int i = 0; i < adjList.size(); i++) {
                if (adjList[i].get(0).getName() == departure) {
                    aLoc = i;
                }
            }
            findPaths(adjList[aLoc].get(0), arrival); //calls functions to find paths
            outputPaths(outFile, metric); //calls function to output paths
        }
        else { //if requested flight is to the same city as the departure city
            outFile << "No paths for same-city flights can be found" << endl;
        }

        inFile.getline(depart, 81, '|'); //read in next requested flight
    }
    inFile.close();
    outFile.close();
}

//getter for adjacency list
Vector<LinkedList<Airport>>& FlightPlan::getAdjList() {
    return adjList;
}

//function used to test reading in of all data to adjacency list
void FlightPlan::printFlightData() {
    for (int i = 0; i < adjList.size(); i++) { //for every linkedlist in adjList
        for (int j = 0; j < adjList[i].size(); j++) { //for every Airport node in associated linkedlist
            adjList[i][j].print(); //prints out Airport data
        }
        cout << endl;
    }
}

//use iterative backtracking to find all paths starting with airport a and ending at destination b
void FlightPlan::findPaths(Airport a, String b) {
    for (int i = 0; i < adjList.size(); i++) {
        adjList[i].backtrack(); //resets all iterators to first arrival node in every linkedlist
    }

    path.push(a); //add departure airport to path

    while (!path.isEmpty()) { //while searching for all possible paths has not been finished
        Airport temp = path.peek(); //find most recently visited Airport
        int indexLoc;
        for (int i = 0; i < adjList.size(); i++) { //get index of linkedlist with most recent airport as head
            if (adjList[i].get(0).getName() == temp.getName()) {
                indexLoc = i;
            }
        }

        if (adjList[indexLoc].hasNext()) { //checks to see if iterator has reached end of linkedlist (no more arrival nodes to check)
            Airport next = adjList[indexLoc].getNext();
            if (!path.contains(next)) { //check to see if airport is already in the path
                path.push(next); //add next airport to stack
                if (path.peek().getName() == b) { //check to see if most recent airport is destination
                    allPaths.push_back(path); //add path to vector of paths
                    path.pop(); //go back to last visited airport
                }
            }
        }
        else { //if iterator has reached end of linkedlist
            adjList[indexLoc].reset(); //put iterator back at head of departure linkedlist
            adjList[indexLoc].backtrack(); //move iterator to first arrival node
            path.pop(); //go back to last visited airport
        }
    }
}

//prints to output file possible paths up to 3 or error message if no possible paths
void FlightPlan::outputPaths(ofstream& outFile, char metric) {
    if (allPaths.empty() == true) { //if no paths were found
        outFile << "No paths could be found from requested departure city to requested arrival city." << endl << endl;
    }
    else {
        if (metric == 'C') { //if ordering by cost
            int pathNum = 0;
            double lastLowest = 0; //variable to track the most recently outputted cost
            for (int i = 0; i < 3; i++) {
                if (i > allPaths.size()-1) { //stops for loop iteration if less than three paths exist
                    break;
                }
                pathNum++;
                int index = -1; //variable to track index of path with lowest cost
                double lowest = 100000; //start with large number as lowest
                for (int i = 0; i < allPaths.size(); i++) {
                    double currentCost = 0;
                    for (int j = 0; j < allPaths[i].size(); j++) {
                        currentCost += allPaths[i].get(j).getCost(); //calculates cost of current path
                    }

                    //sets current cost as lowest if it is the next lowest after previous lowest
                    if (currentCost < lowest && currentCost > lastLowest) {
                        lowest = currentCost; //set lowest for this iteration
                        index = i; //save index of lowest
                    }
                }

                lastLowest = lowest; //sets next lowest found as next benchmark for checking lowest cost for next iteration of for loop

                double totalCost = lowest;
                int totalTime = 0;

                //outputs formatted path
                outFile << "Path " << pathNum << ": ";
                for (int i = 0; i < allPaths[index].size(); i++) { //outputs each airport in path
                    if (i == allPaths[index].size()-1) {
                        outFile << allPaths[index].get(i).getName().c_str() << ". ";
                    }
                    else {
                        outFile << allPaths[index].get(i).getName().c_str() << " -> ";
                    }
                    totalTime += allPaths[index].get(i).getTime();
                }
                outFile << "Time: " << totalTime << " "; //outputs total time
                outFile << "Cost: " << fixed << setprecision(2) << totalCost << endl; //outputs total cost
            }
        }
        else if (metric == 'T') { //if ordering by time
            int pathNum = 0;
            int lastLowest = 0; //variable to track the most recently outputted time
            for (int i = 0; i < 3; i++) {
                if (i > allPaths.size()-1) { //stops for loop iteration if less than three paths exist
                    break;
                }
                pathNum++;
                int index = -1; //variable to track index of path with lowest time
                int lowest = 100000; //starts with large number as lowest time
                for (int i = 0; i < allPaths.size(); i++) {
                    int currentTime = 0;
                    for (int j = 0; j < allPaths[i].size(); j++) {
                        currentTime += allPaths[i].get(j).getTime(); //calculates total time of current path
                    }

                    //sets current time as lowest if it is the next lowest after previous lowest
                    if (currentTime < lowest && currentTime > lastLowest) {
                        lowest = currentTime; //sets new lowest for this iteration as it is found
                        index = i; //save index of new lowest
                    }
                }

                lastLowest = lowest; //sets next lowest found as next benchmark for checking lowest time for next iteration of for loop

                int totalTime = lowest;
                double totalCost = 0;

                //outputs formatted path
                outFile << "Path " << pathNum << ": ";
                for (int i = 0; i < allPaths[index].size(); i++) {
                    if (i == allPaths[index].size()-1) {
                        outFile << allPaths[index].get(i).getName().c_str() << ". ";
                    }
                    else {
                        outFile << allPaths[index].get(i).getName().c_str() << " -> ";
                    }
                    totalCost += allPaths[index].get(i).getCost();
                }
                outFile << "Time: " << totalTime << " "; //outputs total time
                outFile << "Cost: " << fixed << setprecision(2) << totalCost << endl; //outputs total cost
            }
        }
        outFile << endl;
    }

    //remove all paths to move on to the next requested flight
    while (allPaths.empty() == false) {
        allPaths.pop_back();
    }
}


//original code for outputting paths, without sorting
/*
//prints to output file possible paths up to 3 or error message if no possible paths
void FlightPlan::outputPaths(ofstream& outFile) {
    if (allPaths.empty() == true) {
        outFile << "No paths could be found from requested departure city to requested arrival city." << endl;
    }
    else {
        int pathNum = 0;
        double totalCost = 0;
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
            outFile << "Cost: " << fixed << setprecision(2) << totalCost << endl;
        }
        outFile << endl;
    }

    while (allPaths.empty() == false) {
        allPaths.pop_back();
    }
}
*/

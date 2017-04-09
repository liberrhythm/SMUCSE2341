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
    double cost;
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

void FlightPlan::addAirport(String departure, String arrival, double cost, int time) {
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
    Airport three("Houston", 101, 51);
    Airport four("Austin", 0, 0);
    Airport five("Houston", 95, 39);
    Airport six("Dallas", 98, 47);
    Airport seven("Chicago", 144, 192);
    Airport newThree("San Francisco", 63, 89);
    Airport eight("Houston", 0, 0);
    Airport nine("Austin", 95, 39);
    Airport ten("Dallas", 101, 51);
    Airport newOne("Chicago", 30, 56);
    Airport eleven("Chicago", 0, 0);
    Airport twelve("Austin", 144, 192);
    Airport newTwo("Houston", 30, 56);
    Airport newFive("Los Angeles", 98, 90);
    Airport thirteen("San Francisco", 0, 0);
    Airport fourteen("Los Angeles", 25, 52);
    Airport newFour("Austin", 63, 89);
    Airport fifteen("Los Angeles", 0, 0);
    Airport sixteen("San Francisco", 25, 52);
    Airport newSix("Chicago", 98, 90);



    LinkedList<Airport> dallas(one);
    dallas.add(two);
    dallas.add(three);
    LinkedList<Airport> austin(four);
    austin.add(five);
    austin.add(six);
    austin.add(seven);
    austin.add(newThree);
    LinkedList<Airport> houston(eight);
    houston.add(nine);
    houston.add(ten);
    houston.add(newOne);
    LinkedList<Airport> chicago(eleven);
    chicago.add(twelve);
    chicago.add(newTwo);
    chicago.add(newFive);
    LinkedList<Airport> sanfran(thirteen);
    sanfran.add(fourteen);
    sanfran.add(newFour);
    LinkedList<Airport> losangeles(fifteen);
    losangeles.add(sixteen);
    losangeles.add(newSix);

    adjList.push_back(dallas);
    adjList.push_back(austin);
    adjList.push_back(houston);
    adjList.push_back(chicago);
    adjList.push_back(sanfran);
    adjList.push_back(losangeles);

    //adjList[1].add(five);
    //adjList[0].add(three);

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
            outputPaths(outFile, metric);
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


    while (!path.isEmpty()) { //while searching for all possible paths has not been finished
        Airport temp = path.peek();
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
void FlightPlan::outputPaths(ofstream& outFile, char metric) {
    if (allPaths.empty() == true) {
        outFile << "No paths could be found from requested departure city to requested arrival city." << endl << endl;
    }
    else {
        if (metric == 'C') {
            int pathNum = 0;
            double lastLowest = 0;
            for (int i = 0; i < 3; i++) {
                if (i > allPaths.size()-1) {
                    break;
                }
                pathNum++;
                int index = -1;
                double lowest = 100000;
                for (int i = 0; i < allPaths.size(); i++) {
                    double currentCost = 0;
                    for (int j = 0; j < allPaths[i].size(); j++) {
                        currentCost += allPaths[i].get(j).getCost();
                    }

                    if (currentCost < lowest && currentCost > lastLowest) {
                        lowest = currentCost;
                        index = i;
                    }
                }

                lastLowest = lowest;

                double totalCost = lowest;
                int totalTime = 0;

                outFile << "Path " << pathNum << ": ";
                for (int i = 0; i < allPaths[index].size(); i++) {
                    if (i == allPaths[index].size()-1) {
                        outFile << allPaths[index].get(i).getName().c_str() << ". ";
                    }
                    else {
                        outFile << allPaths[index].get(i).getName().c_str() << " -> ";
                    }
                    totalTime += allPaths[index].get(i).getTime();
                }
                outFile << "Time: " << totalTime << " ";
                outFile << "Cost: " << fixed << setprecision(2) << totalCost << endl;
            }
        }
        else if (metric == 'T') {
            int pathNum = 0;
            int lastLowest = 0;
            for (int i = 0; i < 3; i++) {
                if (i > allPaths.size()-1) {
                    break;
                }
                pathNum++;
                int index = -1;
                int lowest = 100000;
                for (int i = 0; i < allPaths.size(); i++) {
                    int currentTime = 0;
                    for (int j = 0; j < allPaths[i].size(); j++) {
                        currentTime += allPaths[i].get(j).getTime();
                    }

                    if (currentTime < lowest && currentTime > lastLowest) {
                        lowest = currentTime;
                        index = i;
                    }
                }

                lastLowest = lowest;

                int totalTime = lowest;
                double totalCost = 0;

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
                outFile << "Time: " << totalTime << " ";
                outFile << "Cost: " << fixed << setprecision(2) << totalCost << endl;
            }
        }
        outFile << endl;
    }
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

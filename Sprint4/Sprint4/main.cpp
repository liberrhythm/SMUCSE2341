/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           4/8/17
Program Number: Sprint4
Purpose:        Outputs efficient flight plans based on flight data and requested flights
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "LinkedList.h"
#include "DSString.h"
#include "DSVector.h"
#include "Airport.h"
#include "FlightPlan.h"
#include <fstream>
#include <iostream>

using namespace std;
/*
#define TEST true
int runCatchTests(int argc, char* const argv[]) {
    return Catch::Session().run(argc, argv);
}
int main(int argc, char* const argv[]) {
    if(TEST)
    {
        return runCatchTests(argc, argv);
    }
    return 0;
}
*/

int main(int argc, char * const argv[]) {
    FlightPlan fPlan(argv[1]);
    //fPlan.printFlightData(); //tests accuracy of adjacency list
    fPlan.readRequestedFlights(argv[2], argv[3]);
}

/*
 * sample flightdata and requested flights inputs
 *
4
Dallas|Austin|98|47
Austin|Houston|95|39
Dallas|Houston|101|51
Austin|Chicago|144|192

2
Dallas|Houston|T
Chicago|Dallas|C



8
Dallas|Austin|98|47
Houston|Dallas|101|51
Austin|Houston|95|39
Chicago|Austin|144|192
San Francisco|Austin|63|89
Houston|Chicago|30|56
San Francisco|Los Angeles|25|52
Los Angeles|Chicago|98|90

7
Dallas|Houston|T
Chicago|Dallas|C
Houston|Chicago|C
Austin|Houston|T
Houston|Austin|C
San Francisco|Los Angeles|T
San Francisco|Dallas|C
*/

/*
 * hard coded construction of adjacency list
 *
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
*/

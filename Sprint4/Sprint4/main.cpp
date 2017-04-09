/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           3/25/17
Program Number: Sprint4
Purpose:        Implements functionality for a custom doubly linked list class with a list node struct
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
    fPlan.printFlightData(); //tests accuracy of adjacency list
    fPlan.readRequestedFlights(argv[2], argv[3]);
}

/*
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

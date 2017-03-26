/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint2
Purpose:        Reads in command line arguments to read files and write output to files for laser tag game implementation
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan
Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/


#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <iostream>
#include <fstream>
#include <cstring>

#include "DSString.h"
#include "DSVector.h"
#include "tag.h"
#include "player.h"
#include "team.h"
#include "match.h"

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

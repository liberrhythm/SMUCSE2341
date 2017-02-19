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

#include <iostream>
#include <fstream>
#include <cstring>

#include "catch.hpp"

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

int main(int argc, char* argv[]) {
    Match m(argv[1], argv[2], argv[3]); //instantiates Match object with team and match files

    String verb(argv[5]);
    ofstream outFile(argv[4]);
    if (!outFile) {
        cerr << "Output file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    if (verb == "vlow") { //tests to determine verbosity
        m.outputLowVerbosity(outFile);
    }
    else if (verb == "vmed"){
        m.outputMedVerbosity(outFile);
    }
    else {
        m.outputHighVerbosity(outFile);
    }

    outFile.close();
    return 0;
}


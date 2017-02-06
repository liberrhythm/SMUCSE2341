//#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <fstream>
#include <cstring>

//#include "catch.hpp"

#include "DSString.h"
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
    Match m(argv[2], argv[3], argv[4]);
    if (argv[6] == "vlow") {
        m.outputLowVerbosity(argv[5]);
    }
    else {
        m.outputMedVerbosity(argv[5]);
    }

    return 0;
}

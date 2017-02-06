#define CATCH_CONFIG_RUNNER

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
    Match m(argv[1], argv[2], argv[3]);

}

/*
for (int i = 1; i < argc-1; i++) {
    switch (i) {
        case 1:
            m.readTeamFile(argv[1], m.getTeamOne());
            break;
        case 2:
            m.readTeamFile(argv[i], m.getTeamTwo());
            break;
        case 3:
            m.readMatchFile(argv[i]);
            break;
        case 4:
            if (argv[5] == "vlow") {
                m.outputLowVerbosity(arg[i]);
            }
            else {
                m.outputMedVerbosity(arg[i]);
            }
            break;
    }
}
*/

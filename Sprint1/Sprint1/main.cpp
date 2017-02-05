#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <fstream>
#include <cstring>

#include "catch.hpp"

#include "DSString.h"
#include "tag.h"
#include "player.h"
#include "team.h"
#include "match.h"

using namespace std;

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

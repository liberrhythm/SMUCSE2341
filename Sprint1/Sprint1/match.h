/*
#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "dsstring.h"
#include "team.h"
#include "player.h"

//using namespace std;

class Match {
    private:
        String teamOneFile;
        String teamTwoFile;
        String matchFile;
        String verbosity;

    public:
        Match(String, String, String, String);
        void readTeamFile();
        void readMatchFile();
        void printLowVerbosity(String);
        void printMedVerbosity(String);
        void printHighVerbosity(String);
};

#endif // MATCH_H
*/

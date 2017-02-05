#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "dsstring.h"
#include "team.h"
#include "player.h"
#include "tag.h"

//using namespace std;

class Match {
    private:
        Team teamOne;
        Team teamTwo;

    public:
        Match(String, String, String, String);
        void readTeamOneFile();
        void readTeamTwoFile();
        void readMatchFile();
        void outputLowVerbosity();
        void outputMedVerbosity();
        void outputHighVerbosity();
};

#endif // MATCH_H

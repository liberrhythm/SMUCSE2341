#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "DSString.h"
#include "team.h"
#include "player.h"
#include "tag.h"

//using namespace std;

class Match {

    private:
        Team teamOne;
        Team teamTwo;
        std::vector<Tag> tags;

    public:
        Match(char*, char*, char*);
        void outputLowVerbosity(char*);
        void outputMedVerbosity(char*);
        //void outputHighVerbosity();
};

#endif // MATCH_H

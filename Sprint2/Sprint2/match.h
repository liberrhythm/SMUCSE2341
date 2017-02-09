/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Provides Match class definition in the form of function prototypes and data members
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

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

        //std::vector<Tag> tags; //contains all tags for the match

    public:
        Match(char*, char*, char*); //takes in three parameters (team and match files)
        void orderTeams();
        //void setTeamScores();
        void outputLowVerbosity(char*);
        void outputMedVerbosity(char*);
        //void outputHighVerbosity();
};

#endif // MATCH_H

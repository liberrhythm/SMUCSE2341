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
//#include <vector>
#include "DSString.h"
#include "DSVector.h"
#include "team.h"
#include "player.h"
#include "tag.h"

//using namespace std;

class Match {

    private:
        Team teamOne;
        Team teamTwo;

    public:
        Match(char*, char*, char*); //takes in three parameters (team and match files)
        void outputLowVerbosity(std::ofstream&);
        void outputMedVerbosity(std::ofstream&);
        void outputHighVerbosity(std::ofstream&);
        void outputMatchWinner(std::ofstream&);
        void outputBestScores(std::ofstream&);
        void outputShortTagSummary(std::ofstream&);
        void outputLongTagSummary(std::ofstream&);
};

#endif // MATCH_H

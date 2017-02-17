/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Provides Team class definition in the form of function prototypes and data members
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <cstring>
//#include <vector>
#include <fstream>
#include "DSString.h"
#include "player.h"

//using namespace std;

class Team {

    private:
        String teamName;
        int teamSize;
        int teamScore;
        Vector<Player> players;

    public:
        Team(char*); //accepts parameter of team file name

        String getTeamName() const;
        void setTeamName(String);
        int getTeamSize() const;
        void setTeamSize(int);
        int getTeamScore();
        void setTeamScore(int);
        Vector<Player>& getTeamPlayers();
        void setTeamPlayers(Vector<Player>);

        void addPlayer(Player); //adds Player objects to vector of Player objects
        void addToScore(int);

        //Team& operator= (const Team&);
        //bool operator> (const Team&);
};

#endif // TEAM_H

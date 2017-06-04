/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Provides Player class definition in the form of function prototypes and data members
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "DSString.h"
#include "tag.h"

//using namespace std;

class Player {

    private:
        int id;
        String name;
        int numTags;
        int score;

    public:
        Player(int, String);
        int getID();
        void setID(int);
        String getName();
        void setName(String);
        int getNumTags();
        void setNumTags(int);
        void addTag();
        int getScore();
        void setScore(int);
        void addToScore(int);

};

#endif // PLAYER_H

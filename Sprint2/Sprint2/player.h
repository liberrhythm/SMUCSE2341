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
#include "DSString.h"
#include "DSVector.h"
#include "tag.h"

//using namespace std;

class Player {

    private:
        int id;
        String name;
        int numTags;
        int playerScore;
        Vector<Tag> playerTags;

    public:
        Player();
        Player(int, String);
        int getID() const;
        void setID(int);
        String getName() const;
        void setName(String);
        int getNumTags() const;
        void setNumTags(int);
        int getScore() const;
        void setScore(int);
        Vector<Tag> getPlayerTags() const;
        void setPlayerTags(Vector<Tag>);

        void addTag(Tag);

        //Player& operator= (const Player&);
        //bool operator > (const Player&);
};

#endif // PLAYER_H

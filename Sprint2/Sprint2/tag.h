/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Provides Tag class definition in the form of function prototypes and data members
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <cstring>
#include "DSString.h"

//using namespace std;

class Tag {

    private:
        int taggerID;
        int taggedID;
        int tagType;
        int tagScore;

    public:
        Tag();
        Tag(int, int, int); //takes in taggerID, taggedID, and tagType parameters
        int getTaggerID();
        void setTaggerID(int);
        int getTaggedID();
        void setTaggedID(int);
        int getTagType();
        void setTagType(int);
        int getTagScore();
        void setTagScore(int);

};

#endif // TAG_H


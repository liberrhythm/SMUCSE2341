/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Defines and provides implementation for Tag class member functions
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#include "tag.h"
using namespace std;

//constructor for Tag object using read-in information, tagScore set based on tagType in separate function
Tag::Tag(int taggerID, int taggedID, int tagType) {
    setTaggerID(taggerID);
    setTaggedID(taggedID);
    setTagType(tagType);
    setTagScore();
}

//accessor for tagger ID
int Tag::getTaggerID() {
    return taggerID;
}

//mutator for tagger ID
void Tag::setTaggerID(int tagger) {
    taggerID = tagger;
}

//accessor for tagged ID
int Tag::getTaggedID() {
    return taggedID;
}

//mutator for tagged ID
void Tag::setTaggedID(int tagged) {
    taggedID = tagged;
}

//accessor for tag type/location
int Tag::getTagType() {
    return tagType;
}

//mutator for tag type/location
void Tag::setTagType(int tagNumber) {
    tagType = tagNumber;
}

//accessor for tag value
int Tag::getTagScore() {
    return tagScore;
}

//mutator for tag value
void Tag::setTagScore() {
    switch (tagType) { //assigns tag value based on location hit
        case 1: //back shot
            tagScore = 5;
            break;
        case 2: //chest shot
            tagScore = 8;
            break;
        case 3: //shoulder shot
            tagScore = 10;
            break;
        case 4: //laser gun shot
            tagScore = 15;
            break;
    }
}

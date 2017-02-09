/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Defines and provides implementation for Player class member functions
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#include "player.h"
using namespace std;

//Player constructor with parameters of read-in information
Player::Player(int id, String name) {
    setID(id);
    setName(name);
    numTags = 0; //number of tags and score originally zero, updated in setTeamScores() in Match class
    score = 0;
}

//accessor for player ID
int Player::getID() {
    return id;
}

//mutator for player ID
void Player::setID(int playerID) {
    id = playerID;
}

//accessor for player name
String Player::getName() {
    return name;
}

//mutator for player name
void Player::setName(String playerName) {
    name = playerName;
}

//accessor for number of tags made by player
int Player::getNumTags() {
    return numTags;
}

//mutator for number of tags made by player
void Player::setNumTags(int num) {
    numTags = num;
}

//increments number of tags made by player
void Player::addTag() {
    numTags++;
}

//accessor for player score
int Player::getScore() {
    return score;
}

//mutator for player score
void Player::setScore(int playerScore) {
    score = playerScore;
}

//adds value of tag by player to player's existing score
void Player::addToScore(int tagValue) {
    score += tagValue;
}

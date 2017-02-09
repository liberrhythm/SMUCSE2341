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
    playerScore = 0;
}

//accessor for player ID
int Player::getID() const {
    return id;
}

//mutator for player ID
void Player::setID(int playerID) {
    id = playerID;
}

//accessor for player name
String Player::getName() const {
    return name;
}

//mutator for player name
void Player::setName(String playerName) {
    name = playerName;
}

//accessor for number of tags made by player
int Player::getNumTags() const {
    return numTags;
}

//mutator for number of tags made by player
void Player::setNumTags(int num) {
    numTags = num;
}

//accessor for player score
int Player::getScore() const {
    return playerScore;
}

//mutator for player score
void Player::setScore(int pScore) {
    playerScore = pScore;
}

//accessor for player's vector of tags
std::vector<Tag> Player::getPlayerTags() const {
    return playerTags;
}

//mutator for player's vector of tags
void Player::setPlayerTags(std::vector<Tag> tags) {
    for (Tag t: tags) {
        playerTags.push_back(t);
    }
}

//adds a Tag object to player (player is the tagger)
//increments number of tags made by player and updates player score based on tag score
void Player::addTag(Tag t) {
    playerTags.push_back(t);
    numTags++;
    playerScore += t.getTagScore();
}

//overloaded assignment operator to avoid default memberwise copy when assigning player objects
//to other player objects
Player& Player::operator= (const Player& p) {
    id = p.getID();
    name = p.getName();
    numTags = p.getNumTags();
    playerScore = p.getScore();
    for (Tag t: p.getPlayerTags()) {
        playerTags.push_back(t);
    }
    return *this;
}

//overloaded greater than operator to determine precedence of player objects
//returns true if this player has more successful tags than parameter player
bool Player::operator> (const Player& p) {
    if (numTags > p.getNumTags()) {
        return true;
    }
    return false;
}

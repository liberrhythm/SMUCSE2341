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

//Non-parameterized Player default constructor
Player::Player() {
    id = 0;
    name = "";
}

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

//accessor for player's vector of tags, returns by reference
Vector<Tag> Player::getPlayerTags() const {
    return playerTags;
}

//mutator for player's vector of tags
void Player::setPlayerTags(Vector<Tag> tags) {
    for (int i = 0; i < tags.size(); i++) {
        playerTags.push_back(tags[i]);
    }
}

//adds a Tag object to player (player is the tagger)
//increments number of tags made by player and updates player score based on tag score
void Player::addTag(Tag t) {
    playerTags.push_back(t);
    numTags++;
    playerScore += t.getTagScore();
}

/*
//overloaded assignment operator to avoid default memberwise copy when assigning player objects
//to other player objects
Player& Player::operator= (const Player& p) {
    id = p.getID();
    name = p.getName();
    numTags = p.getNumTags();
    playerScore = p.getScore();
    for (int i = 0; i < p.getPlayerTags().size(); i++) { //iterates through parameter's vector of Tag objects
        playerTags.push_back(p.getPlayerTags()[i]); //copies tag objects to this player's tag vector
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
*/

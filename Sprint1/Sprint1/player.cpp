#include "player.h"

Player::Player(int id, String name) {
    setID(id);
    setName(name);
    numTags = 0;
    score = 0;
}

int Player::getID() {
    return id;
}

void Player::setID(int playerID) {
    id = playerID;
}

String Player::getName() {
    return name;
}

void Player::setName(String playerName) {
    name = playerName;
}

int Player::getNumTags() {
    return numTags;
}

void Player::setNumTags(int num) {
    numTags = num;
}

void Player::addTag() {
    numTags++;
}

int Player::getScore() {
    return score;
}

void Player::setScore(int playerScore) {
    score = playerScore;
}

void Player::addToScore(int tagValue) {
    score += tagValue;
}

/*
std::vector<Tag> Player::getPlayerTags() {
    return tags;
}

void Player::setPlayerTags(std::vector<Tag> playerTags) {
    for (Tag t: playerTags) {
        tags.push_back(t);
    }
}

void Player::addTag(Tag tag) {
    tags.push_back(tag);
}

int Player::calculateNumTags() {
    return tags.size();
}

int Player::calculatePlayerScore() {
    int playerTotal = 0;
    for (Tag t: tags) {
        playerTotal += t.getTagScore();
    }
    return playerTotal;
}
*/

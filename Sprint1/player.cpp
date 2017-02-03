#include "player.h"

Player::Player(int id, DSString name, Tag* tags) {
    setID(id);
    setName(name);
    setTagArray(tags);
}

int Player::getID() {
    return id;
}

void Player::setID(int playerID) {
    id = playerID;
}

DSString Player::getName() {
    return name;
}

void Player::setName(DSString playerName) {
    name = playerName;
}

vector<Tag> Player::getAllTags() {
    return tags;
}

void Player::setAllTags(vector<Tag> allTags) {
    for (Tag t: allTags) {
        tags.push_back(tag);
    }
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

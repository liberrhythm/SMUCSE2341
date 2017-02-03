/*
#include "tag.h"

backScore = 5;
chestScore = 8;
shoulderScore = 10;
gunScore = 15;

Tag::Tag(int taggerID, int taggedID, int tagType) {
    setTaggerID(taggerID);
    setTaggedID(taggedID);
    setTagType(tagType);
    setTagScore();
}

int Tag::getTaggerID() {
    return taggerID;
}

void Tag::setTaggerID(int tagger) {
    taggerID = tagger;
}

int Tag::getTaggedID() {
    return taggedID;
}

void Tag::setTaggedID(int tagged) {
    taggedID = tagged;
}

int Tag::getTagType() {
    return tagType;
}

void Tag::setTagType(int tagNumber) {
    tagType = tagNumber;
}

int Tag::getTagScore() {
    return tagScore;
}

void Tag::setTagScore() {
    switch (tagType) {
        case 1:
            tagScore = backScore;
        case 2:
            tagScore = chestScore;
        case 3:
            tagScore = shoulderScore;
        case 4:
            tagScore = gunScore;
    }
}
*/

#include "tag.h"
using namespace std;

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
            tagScore = 5;
        case 2:
            tagScore = 8;
        case 3:
            tagScore = 10;
        case 4:
            tagScore = 15;
    }
}

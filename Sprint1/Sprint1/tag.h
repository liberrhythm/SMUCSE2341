#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <cstring>
#include "dsstring.h"

//using namespace std;

class Tag {

    private:
        int taggerID;
        int taggedID;
        int tagType;
        int tagScore;

    public:
        Tag(int, int, int);
        int getTaggerID();
        void setTaggerID(int);
        int getTaggedID();
        void setTaggedID(int);
        int getTagType();
        void setTagType(int);
        int getTagScore();
        void setTagScore();

};

#endif // TAG_H


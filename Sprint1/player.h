#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include "DSString.h"
using namespace std;

class Player {

    private:
        int id;
        DSString name;
        vector<Tag> tags;

    public:
        Player(int, DSString, Tag*);
        int getID();
        void setID(int);
        DSString getName();
        void setName(DSString);
        vector<Tag> getAllTags();
        void setAllTags(vector<Tag>);
        int calculateNumTags();
        int calculatePlayerScore();

};

#endif // PLAYER_H

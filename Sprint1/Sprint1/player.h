#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "DSString.h"
#include "tag.h"

//using namespace std;

class Player {

    private:
        int id;
        String name;
        std::vector<Tag> tags;

    public:
        Player(int, String);
        int getID();
        void setID(int);
        String getName();
        void setName(String);
        std::vector<Tag> getPlayerTags();
        void setPlayerTags(std::vector<Tag>);
        void addTag(Tag);
        int calculateNumTags();
        int calculatePlayerScore();

};

#endif // PLAYER_H

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
        Team team;
        int numTags;
        int score;

    public:
        Player(int, String);
        int getID();
        void setID(int);
        String getName();
        void setName(String);
        Team getTeam();
        void setTeam(Team);
        int getNumTags();
        void setNumTags(int);
        void addTag();
        int getScore();
        void setScore(int);
        void addToScore(int);
        /*
        std::vector<Tag> getPlayerTags();
        void setPlayerTags(std::vector<Tag>);
        void addTag(Tag);
        int calculateNumTags();
        int calculatePlayerScore();
        */

};

#endif // PLAYER_H

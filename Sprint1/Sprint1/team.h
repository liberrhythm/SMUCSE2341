#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "DSString.h"
#include "player.h"

//using namespace std;

class Team {

    private:
        String teamName;
        int teamSize;
        int teamScore;
        std::vector<Player> players;

    public:
        Team(char*);
        String getTeamName();
        void setTeamName(String);
        int getTeamSize();
        void setTeamSize(int);
        int getTeamScore();
        void setTeamScore(int);
        std::vector<Player> getTeamPlayers();
        void setTeamPlayers(std::vector<Player>);
        void addPlayer(Player);
        void calculateTeamScore();
};

#endif // TEAM_H

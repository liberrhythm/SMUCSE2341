#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <cstring>
#include <vector>
#include "DSString.h"
#include "player.h"

//using namespace std;

class Team {

    private:
        String teamName;
        int teamSize;
        std::vector<Player> players;

    public:
        Team(String, int);
        String getTeamName();
        void setTeamName(String);
        int getTeamSize();
        void setTeamSize(int);
        std::vector<Player> getTeamPlayers();
        void setTeamPlayers(std::vector<Player>);
        void addPlayer(Player);
        int calculateTeamScore();

};

#endif // TEAM_H

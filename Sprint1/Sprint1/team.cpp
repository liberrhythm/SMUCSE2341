#include "team.h"

Team::Team() {
    teamName = "";
    teamSize = 0;
}

Team::Team(String teamName, int teamSize) {
    setTeamName(teamName);
    setTeamSize(teamSize);
    setTeamPlayers(players);
}

String Team::getTeamName() {
    return teamName;
}

void Team::setTeamName(String tName) {
    teamName = tName;
}

int Team::getTeamSize() {
    return teamSize;
}

void Team::setTeamSize(int tSize) {
    teamSize = tSize;
}

std::vector<Player> Team::getTeamPlayers() {
    return players;
}

void Team::addPlayer(Player player) {
    players.push_back(player);
}

void Team::setTeamPlayers(std::vector<Player> tPlayers) {
    for (Player p: tPlayers) {
        players.push_back(p);
    }
}

int Team::calculateTeamScore() {
    int teamScore = 0;
    for (Player p: players) {
        teamScore += p.calculatePlayerScore();
    }
    return teamScore;
}

#include "team.h"
using namespace std;

Team::Team(char* teamFileName) {
    teamScore = 0;
    ifstream inFile(teamFileName, ios::in);
    if (!inFile) {
        cerr << "Team file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    String teamName;
    int teamSize;
    inFile >> teamName >> teamSize;
    setTeamName(teamName);
    setTeamSize(teamSize);

    int playerID;
    String playerName;
    inFile >> playerID;
    inFile >> playerName;
    while(!inFile.eof()) {
        Player p(playerID, playerName);
        addPlayer(p);
        inFile >> playerID;
        inFile >> playerName;
    }

    inFile.close();
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

int Team::getTeamScore() {
    return teamScore;
}

void Team::setTeamScore(int score) {
    teamScore = score;
}

std::vector<Player> Team::getTeamPlayers() {
    return players;
}

void Team::setTeamPlayers(std::vector<Player> tPlayers) {
    for (Player p: tPlayers) {
        players.push_back(p);
    }
}

void Team::addPlayer(Player player) {
    players.push_back(player);
}

void Team::calculateTeamScore() {
    for (Player p: players) {
        teamScore += p.getScore();
    }
}

/*
Team& Team::operator= (const Team& team) {
    teamName = team.teamName;
    teamSize = team.teamSize;
    for (Player p: team.players) {
        players.push_back(p);
    }
    return *this;
}
*/

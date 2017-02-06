#include "team.h"

Team::Team(char* teamFileName) {
    readTeamFile(teamFileName);
}

void Team::readTeamFile(char* teamFileName) {
    ifstream inFile;
    inFile.open(teamFileName, ios::in);
    if (!inFile) {
        cerr << "Team file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    inFile >> teamName >> teamSize;
    setTeamName(teamName);
    setTeamSize(teamSize);

    int playerID;
    String playerName;
    inFile >> playerID;
    inFile >> playerName;
    while(!inFile.eof()) {
        Player p(playerID, playerName);
        t.addPlayer(p);
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

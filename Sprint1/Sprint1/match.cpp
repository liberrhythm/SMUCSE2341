/*
#include "match.h"

Match(String teamOne, String teamTwo, String match, String verb) {
    teamOneFile = teamOne;
    teamTwoFile = teamTwo;
    matchFile = match;
    verbosity = verb;
}

void Match::readTeamFile() {
    ifstream inFile;
    inFile.open(teamOneFile, ios::in);
    if (!inFile) {
        cerr << "File 1 could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    String teamName;
    int teamSize;
    inFile >> teamName >> teamSize;
    Team teamOne(teamName, teamSize);

    int playerID;
    String playerName;
    inFile >> playerID >> playerName;
    while(!inFile.eof()) {
        inFile >> playerID >> playerName;
        Player p(playerID, playerName);
        teamOne.addPlayer(p);
    }

    inFile.close();

    inFile.open(teamTwoFile, ios::in);
    if (!inFile) {
        cerr << "File 2 could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    inFile.close();
}

void Match::readMatchFile() {

}

void Match::printLowVerbosity(String vlow) {

}

void Match::printMedVerbosity(String vmed) {

}

void Match::printHighVerbosity(String vhigh) {

}
*/

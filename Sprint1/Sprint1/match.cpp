#include "match.h"

Match::Match() {
    
}

void Match::readTeamOneFile(String teamFileName) {
    ifstream inFile;
    inFile.open(teamFileName, ios::in);
    if (!inFile) {
        cerr << "File 1 could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    String teamName;
    int teamSize;
    inFile.getline(teamName, 100);
    inFile >> teamSize;
    teamOne(teamName, teamSize);

    int playerID;
    String playerName;
    inFile >> playerID;
    inFile.getline(playerName, 100);
    while(!inFile.eof()) {
        Player p(playerID, playerName);
        teamOne.addPlayer(p);
        inFile >> playerID;
        inFile.getline(playerName, 100);
    }

    inFile.close();
}

void Match::readTeamTwoFile(String teamFileName) {
    ifstream inFile;
    inFile.open(teamFileName, ios::in);
    if (!inFile) {
        cerr << "File 2 could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    String teamName;
    int teamSize;
    inFile.getline(teamName, 100);
    inFile >> teamSize;
    teamTwo(teamName, teamSize);

    int playerID;
    String playerName;
    inFile >> playerID;
    inFile.getline(playerName, 100);
    while(!inFile.eof()) {
        Player p(playerID, playerName);
        teamTwo.addPlayer(p);
        inFile >> playerID;
        inFile.getline(playerName, 100);
    }

    inFile.close();
}

void Match::readMatchFile(String matchFile) {
    ifstream inFile;
    inFile.open(matchFile, ios::in);
    if (!inFile) {
        cerr << "Match file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int totalTags;
    inFile >> totalTags;

    int tagger;
    int tagged;
    int tagTime;
    int tagLocation;
    inFile >> tagger >> tagged >> tagTime >> tagLocation;
    while(!inFile.eof()) {
        Tag t(tagger, tagged, tagLocation);
        for (Player p: teamOne.getTeamPlayers()) {
	    if (p.getID() == tagger) {
		p.addTag(t);
	    }
	}
        for (Player p: teamTwo.getTeamPlayers()) {
	    if (p.getID() == tagger) {
		p.addTag(t);
	    }
	}
	inFile >> tagger >> tagged >> tagTime >> tagLocation;
    }

    inFile.close();
}

void Match::outputLowVerbosity() {
    ofstream outFile("vlow.txt", ios::out);
    if (!outFile) {
        cerr << "Vlow file could not be created" << endl;
        exit(EXIT_FAILURE);
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) {
        outFile << teamTwo.getTeamName() << ": " << teamTwo.calculateTeamScore() << " points" << endl;
        outFile << teamOne.getTeamName() << ": " << teamOne.calculateTeamScore() << " points" << endl;
    }
    else {
        outFile << teamOne.getTeamName() << ": " << teamOne.calculateTeamScore() << " points" << endl;
        outFile << teamTwo.getTeamName() << ": " << teamTwo.calculateTeamScore() << " points" << endl;
    }

    if (teamOne.calculateTeamScore() > teamTwo.calculateTeamScore()){
        outFile << "Overall Winners: " << teamOne.getTeamName() << endl;
    }
    else if (teamOne.calculateTeamScore() < teamTwo.calculateTeamScore()) {
        outFile << "Overall Winners: " << teamTwo.getTeamName() << endl;
    }
    else {
        outFile << "Overall Winners: Teams Tied" << endl;
    }
}

void Match::outputMedVerbosity() {
    ofstream outFile("vmed.txt", ios::out);
    if (!outFile) {
        cerr << "Vmed file could not be created" << endl;
        exit(EXIT_FAILURE);
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) {
        outFile << teamTwo.getTeamName() << endl;
        int mostTags = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.calculateNumTags() > mostTags) {
                mostTags = p.calculateNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamTwo.getTeamPlayers()) {
                if (p.calculateNumTags() == mostTags) {
                    for (Tag t: p.getPlayerTags()) {
                        output << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
                    }
                    teamTwo.getTeamPlayers().pop_back(p);
                }
            }
        }
        outFile << endl;

        outFile << teamOne.getTeamName() << endl;
        mostTags = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.calculateNumTags() > mostTags) {
                mostTags = p.calculateNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamOne.getTeamPlayers()) {
                if (p.calculateNumTags() == mostTags) {
                    for (Tag t: p.getPlayerTags()) {
                        output << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
                    }
                    teamOne.getTeamPlayers().pop_back(p);
                }
            }
        }
        outFile << endl;
    }
    else {
        outFile << teamOne.getTeamName() << endl;
        int mostTags = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.calculateNumTags() > mostTags) {
                mostTags = p.calculateNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamOne.getTeamPlayers()) {
                if (p.calculateNumTags() == mostTags) {
                    for (Tag t: p.getPlayerTags()) {
                        output << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
                    }
                    teamOne.getTeamPlayers().pop_back(p);
                }
            }
        }
        outFile << endl;

        outFile << teamTwo.getTeamName() << endl;
        mostTags = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.calculateNumTags() > mostTags) {
                mostTags = p.calculateNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamTwo.getTeamPlayers()) {
                if (p.calculateNumTags() == mostTags) {
                    for (Tag t: p.getPlayerTags()) {
                        output << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
                    }
                    teamTwo.getTeamPlayers().pop_back(p);
                }
            }
        }
        outFile << endl;
    }

    output << "Best score from " << teamOne.getTeamName() << ": ";

    output << "Best score from " << teamTwo.getTeamName() << ": ";
}

void Match::outputHighVerbosity() {

}


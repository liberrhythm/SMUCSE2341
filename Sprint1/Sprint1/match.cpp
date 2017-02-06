#include "match.h"
using namespace std;

Match::Match() {

}

Team Match::getTeamOne() {
    return teamOne;
}

Team Match::getTeamTwo() {
    return teamTwo;
}

void Match::readTeamFile(char* teamFileName, Team t) {
    ifstream inFile;
    inFile.open(teamFileName, ios::in);
    if (!inFile) {
        cerr << "Team file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    String teamName;
    int teamSize;
    inFile >> teamName;;
    inFile >> teamSize;
    t.setTeamName(teamName);
    t.setTeamSize(teamSize);

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

void Match::readMatchFile(char* matchFile) {
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
        Tag tag(tagger, tagged, tagLocation);
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getID() == tagger) {
                p.addTag(tag);
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getID() == tagger) {
                p.addTag(tag);
            }
        }
        inFile >> tagger >> tagged >> tagTime >> tagLocation;
    }

    inFile.close();
}

void Match::outputLowVerbosity(char* outputFile) {
    ofstream outFile(outputFile, ios::out);
    if (!outFile) {
        cerr << "Output file could not be opened" << endl;
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

void Match::outputMedVerbosity(char* outputFile) {
    ofstream outFile(outputFile, ios::out);
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
                if (p.calculateNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
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
                if (p.calculateNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
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
                if (p.calculateNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
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
                if (p.calculateNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.calculateNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) {
        outFile << "Best score from " << teamTwo.getTeamName() << ": ";
        int highestScore = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.calculatePlayerScore() > highestScore) {
                highestScore = p.calculatePlayerScore();
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.calculatePlayerScore() == highestScore) {
                outFile << p.getName() << " (" << p.calculatePlayerScore() << " points)" << endl;
            }
        }

        outFile << "Best score from " << teamOne.getTeamName() << ": ";
        highestScore = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.calculatePlayerScore() > highestScore) {
                highestScore = p.calculatePlayerScore();
            }
        }
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.calculatePlayerScore() == highestScore) {
                outFile << p.getName() << " (" << p.calculatePlayerScore() << " points)" << endl;
            }
        }
    }
    else {
        outFile << "Best score from " << teamOne.getTeamName() << ": ";
        int highestScore = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.calculatePlayerScore() > highestScore) {
                highestScore = p.calculatePlayerScore();
            }
        }
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.calculatePlayerScore() == highestScore) {
                outFile << p.getName() << " (" << p.calculatePlayerScore() << " points)" << endl;
            }
        }

        outFile << "Best score from " << teamTwo.getTeamName() << ": ";
        highestScore = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.calculatePlayerScore() > highestScore) {
                highestScore = p.calculatePlayerScore();
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.calculatePlayerScore() == highestScore) {
                outFile << p.getName() << " (" << p.calculatePlayerScore() << " points)" << endl;
            }
        }
    }

    outputLowVerbosity();
}

/*
void Match::outputHighVerbosity() {

}
*/

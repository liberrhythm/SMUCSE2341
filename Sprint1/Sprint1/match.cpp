#include "match.h"
using namespace std;

Match::Match(char* teamOneFile, char* teamTwoFile, char* matchFile) {
    teamOne(teamOneFile);
    teamTwo(teamTwoFile);
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
        tags.push_back(tag);
    }
    inFile.close();

    /*
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
    */
}

void Match::setTeamScores() {
    for (Tag tag: tags) {
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getID() == tag.getTaggerID()) {
                p.addTag();
                p.addToScore(tag.getTagScore());
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getID() == tag.getTaggerID()) {
                p.addTag();
                p.addToScore(tag.getTagScore());
            }
        }
    }
    teamOne.calculateTeamScore();
    teamTwo.calculateTeamScore();
}

void Match::outputLowVerbosity(char* outputFile) {
    ofstream outFile(outputFile, ios::out);
    if (!outFile) {
        cerr << "Output file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) {
        outFile << teamTwo.getTeamName() << ": " << teamTwo.getTeamScore() << " points" << endl;
        outFile << teamOne.getTeamName() << ": " << teamOne.getTeamScore() << " points" << endl;
    }
    else {
        outFile << teamOne.getTeamName() << ": " << teamOne.getTeamScore() << " points" << endl;
        outFile << teamTwo.getTeamName() << ": " << teamTwo.getTeamScore() << " points" << endl;
    }

    if (teamOne.getTeamScore() > teamTwo.getTeamScore()){
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
            if (p.getNumTags() > mostTags) {
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamTwo.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;

        outFile << teamOne.getTeamName() << endl;
        mostTags = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getNumTags() > mostTags) {
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamOne.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;
    }
    else {
        outFile << teamOne.getTeamName() << endl;
        int mostTags = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getNumTags() > mostTags) {
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamOne.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;

        outFile << teamTwo.getTeamName() << endl;
        mostTags = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getNumTags() > mostTags) {
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamTwo.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) {
        outFile << "Best score from " << teamTwo.getTeamName() << ": ";
        int highestScore = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getScore() == highestScore) {
                outFile << p.getName() << " (" << p.getScore() << " points)" << endl;
            }
        }

        outFile << "Best score from " << teamOne.getTeamName() << ": ";
        highestScore = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() == highestScore) {
                outFile << p.getName() << " (" << p.getScore() << " points)" << endl;
            }
        }
    }
    else {
        outFile << "Best score from " << teamOne.getTeamName() << ": ";
        int highestScore = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() == highestScore) {
                outFile << p.getName() << " (" << p.getScore() << " points)" << endl;
            }
        }

        outFile << "Best score from " << teamTwo.getTeamName() << ": ";
        highestScore = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getScore() == highestScore) {
                outFile << p.getName() << " (" << p.getScore() << " points)" << endl;
            }
        }
    }

    outputLowVerbosity();
}

/*
void Match::outputHighVerbosity() {

}
*/

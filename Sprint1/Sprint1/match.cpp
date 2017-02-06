/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Defines and provides implementation for Match class member functions
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#include "match.h"
using namespace std;

//instantiates private Team data members based on team file parameters and creates tags from match file
Match::Match(char* teamOneFile, char* teamTwoFile, char* matchFile) : teamOne(teamOneFile), teamTwo(teamTwoFile) {
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
    inFile >> tagger >> tagged >> tagTime >> tagLocation; //primes while loop by reading in line of information

    while(!inFile.eof()) {
        Tag tag(tagger, tagged, tagLocation); //create a Tag object based on read-in information
        tags.push_back(tag); //add created tag into Match object vector of tags
        inFile >> tagger >> tagged >> tagTime >> tagLocation; //continue reading
    }
    inFile.close();
}

//determines and sets scores for players and teams based on Tag object information
void Match::setTeamScores() {
    for (Tag tag: tags) {
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getID() == tag.getTaggerID()) { //if tagger ID in the Tag object is the same as a Player in Team 1
                p.addTag(); //add 1 to number of tags player has made
                p.addToScore(tag.getTagScore()); //adds tag's point value to player's score
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) { //same for if tagger is in Team Two
            if (p.getID() == tag.getTaggerID()) {
                p.addTag();
                p.addToScore(tag.getTagScore());
            }
        }
    }
    teamOne.setTeamScore(teamOne.calculateTeamScore()); //update team scores based on players' combined scores
    teamTwo.setTeamScore(teamTwo.calculateTeamScore());
}

//outputs points for each time and winner
void Match::outputLowVerbosity(char* outputFile) {
    ofstream outFile(outputFile, ios::out);
    if (!outFile) {
        cerr << "Output file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) { //if Team Two name comes before Team One in the alphabet
        outFile << teamTwo.getTeamName().c_str() << ": " << teamTwo.getTeamScore() << " points" << endl; //writes to file using << for char array
        outFile << teamOne.getTeamName().c_str() << ": " << teamOne.getTeamScore() << " points" << endl;
    }
    else { //if Team One name comes before Team Two name in the alphabet
        outFile << teamOne.getTeamName().c_str() << ": " << teamOne.getTeamScore() << " points" << endl;
        outFile << teamTwo.getTeamName().c_str() << ": " << teamTwo.getTeamScore() << " points" << endl;
    }

    if (teamOne.getTeamScore() > teamTwo.getTeamScore()){
        outFile << "Overall Winners: " << teamOne.getTeamName().c_str() << endl;
    }
    else if (teamOne.getTeamScore() > teamTwo.getTeamScore()) {
        outFile << "Overall Winners: " << teamTwo.getTeamName().c_str() << endl;
    }
    else { //if team scores are the same
        outFile << "Overall Winners: Teams Tied" << endl;
    }
}

//outputs low verbosity information along with detailed information about total tags for each player
void Match::outputMedVerbosity(char* outputFile) {
    ofstream outFile(outputFile, ios::out);
    if (!outFile) {
        cerr << "Vmed file could not be created" << endl;
        exit(EXIT_FAILURE);
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) {
        outFile << teamTwo.getTeamName().c_str() << endl;
        int mostTags = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getNumTags() > mostTags) { //finds most tags made by a player on team
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) { //prints player tag information from most successful to least
            for (Player p: teamTwo.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName().c_str() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;

        //do the same detailed player tag total printing for other team
        outFile << teamOne.getTeamName().c_str() << endl;
        mostTags = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getNumTags() > mostTags) {
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamOne.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName().c_str() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;
    }
    else { //if Team One name is earlier in alphabet than Team Two name
        outFile << teamOne.getTeamName().c_str() << endl; //repeat above code but in reverse order (Team One first, then Team Two)
        int mostTags = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getNumTags() > mostTags) {
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamOne.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName().c_str() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;

        outFile << teamTwo.getTeamName().c_str() << endl;
        mostTags = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getNumTags() > mostTags) {
                mostTags = p.getNumTags();
            }
        }
        for (int i = mostTags; i > -1; i++) {
            for (Player p: teamTwo.getTeamPlayers()) {
                if (p.getNumTags() == i) {
                    outFile << setw(10)<< p.getName().c_str() << " had a total of " << p.getNumTags() << "tags" << endl;
                }
            }
        }
        outFile << endl;
    }

    if (teamOne.getTeamName() > teamTwo.getTeamName()) {
        outFile << "Best score from " << teamTwo.getTeamName().c_str() << ": ";
        int highestScore = 0;
        for (Player p: teamTwo.getTeamPlayers()) { //finds highest score by player on team
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getScore() == highestScore) { //prints highest score
                outFile << p.getName().c_str() << " (" << p.getScore() << " points)" << endl;
            }
        }

        //finds highest score by player for other team
        outFile << "Best score from " << teamOne.getTeamName().c_str() << ": ";
        highestScore = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() == highestScore) {
                outFile << p.getName().c_str() << " (" << p.getScore() << " points)" << endl;
            }
        }
    }
    else { //repeats code for highest score in reverse order
        outFile << "Best score from " << teamOne.getTeamName().c_str() << ": ";
        int highestScore = 0;
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getScore() == highestScore) {
                outFile << p.getName().c_str() << " (" << p.getScore() << " points)" << endl;
            }
        }

        outFile << "Best score from " << teamTwo.getTeamName().c_str() << ": ";
        highestScore = 0;
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getScore() > highestScore) {
                highestScore = p.getScore();
            }
        }
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getScore() == highestScore) {
                outFile << p.getName().c_str() << " (" << p.getScore() << " points)" << endl;
            }
        }
    }

    outputLowVerbosity(outputFile); //outputs low verbosity summary
}

/*
void Match::outputHighVerbosity() {

}
*/

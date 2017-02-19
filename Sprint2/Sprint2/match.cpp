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
    inFile >> tagger; //primes while loop by reading in line of information
    while(!inFile.eof()) {
        inFile >> tagged >> tagTime >> tagLocation;
        Tag tag(tagger, tagged, tagLocation); //create a Tag object based on read-in information
        for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) { //Player& p: teamOne.getTeamPlayers()) { //cycles through team one's team players
            if (teamOne.getTeamPlayers()[i].getID() == tag.getTaggerID()) { //tests to see if player's id matches tagger's id
                teamOne.getTeamPlayers()[i].addTag(tag); //if true, adds tag to player's vector of tags and updates player's information
            }
        }
        for (int i = 0; i < teamTwo.getTeamPlayers().size(); i++) { //Player& p: teamTwo.getTeamPlayers()) { //does same thing for team two as for team one above
            if (teamTwo.getTeamPlayers()[i].getID() == tag.getTaggerID()) {
                teamTwo.getTeamPlayers()[i].addTag(tag);
            }
        }
        //tags.push_back(tag); //add created tag into Match object vector of tags
        inFile >> tagger; //continue reading
    }

    inFile.close();
    //orderTeams();
}

/*
void Match::orderTeams() {
    if (teamOne > teamTwo) {
        Team temp = teamTwo;
        teamTwo = teamOne;
        teamOne = temp;
    }
}
*/

//outputs points for each time and winner
void Match::outputLowVerbosity(ofstream& outFile) {

    outFile << teamOne.getTeamName().c_str() << ": " << teamOne.getTeamScore() << " points" << endl;
    outFile << teamTwo.getTeamName().c_str() << ": " << teamTwo.getTeamScore() << " points" << endl;

    if (teamOne.getTeamScore() > teamTwo.getTeamScore()){
        outFile << "Overall Winners: " << teamOne.getTeamName().c_str() << endl;
    }
    else if (teamTwo.getTeamScore() > teamOne.getTeamScore()) {
        outFile << "Overall Winners: " << teamTwo.getTeamName().c_str() << endl;
    }
    else { //if team scores are the same
        outFile << "Overall Winners: Teams Tied" << endl;
    }
}

//outputs low verbosity information along with detailed information about total tags for each player
void Match::outputMedVerbosity(ofstream& outFile) {

    outFile << teamOne.getTeamName().c_str() << endl; //repeat above code but in reverse order (Team One first, then Team Two)
    int mostTags = 0;
    for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) {
        if (teamOne.getTeamPlayers()[i].getNumTags() > mostTags) {
            mostTags = teamOne.getTeamPlayers()[i].getNumTags();
        }
    }
    for (int n = mostTags; n > -1; n--) {
        for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) {
            if (teamOne.getTeamPlayers()[i].getNumTags() == n) {
                outFile << '\t' << teamOne.getTeamPlayers()[i].getName().c_str() << " had a total of " << teamOne.getTeamPlayers()[i].getNumTags() << " tags" << endl;
            }
        }
    }
    outFile << endl;

    outFile << teamTwo.getTeamName().c_str() << endl;
    mostTags = 0;
    for (int i = 0; i < teamTwo.getTeamPlayers().size(); i++) {
        if (teamTwo.getTeamPlayers()[i].getNumTags() > mostTags) {
            mostTags = teamTwo.getTeamPlayers()[i].getNumTags();
        }
    }
    for (int n = mostTags; n > -1; n--) {
        for (int i = 0; i < teamTwo.getTeamPlayers().size(); i++) {
            if (teamTwo.getTeamPlayers()[i].getNumTags() == n) {
                outFile << '\t' << teamTwo.getTeamPlayers()[i].getName().c_str() << " had a total of " << teamTwo.getTeamPlayers()[i].getNumTags() << " tags" << endl;
            }
        }
    }
    outFile << endl;

    outFile << "Best score from " << teamOne.getTeamName().c_str() << ": ";
    int highestScore = 0;
    for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) {
        if (teamOne.getTeamPlayers()[i].getScore() > highestScore) {
            highestScore = teamOne.getTeamPlayers()[i].getScore();
        }
    }
    for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) {
        if (teamOne.getTeamPlayers()[i].getScore() == highestScore) {
            outFile << teamOne.getTeamPlayers()[i].getName().c_str() << " (" << teamOne.getTeamPlayers()[i].getScore() << " points)" << endl;
        }
    }

    outFile << "Best score from " << teamTwo.getTeamName().c_str() << ": ";
    highestScore = 0;
    for (int i = 0; i < teamTwo.getTeamPlayers().size(); i++) {
        if (teamTwo.getTeamPlayers()[i].getScore() > highestScore) {
            highestScore = teamTwo.getTeamPlayers()[i].getScore();
        }
    }
    for (int i = 0; i < teamTwo.getTeamPlayers().size(); i++) {
        if (teamTwo.getTeamPlayers()[i].getScore() == highestScore) {
            outFile << teamTwo.getTeamPlayers()[i].getName().c_str() << " (" << teamTwo.getTeamPlayers()[i].getScore() << " points)" << endl;
        }
    }
    outputLowVerbosity(outFile); //outputs low verbosity summary at end
}

void Match::outputHighVerbosity(ofstream& outFile) {
    outFile << teamOne.getTeamName().c_str() << endl;
    int mostTags = 0;
    for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) {
        if (teamOne.getTeamPlayers()[i].getNumTags() > mostTags) {
            mostTags = teamOne.getTeamPlayers()[i].getNumTags();
        }
    }
    for (int n = mostTags; n > -1; n--) {
        for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) {
            if (teamOne.getTeamPlayers()[i].getNumTags() == n) {
                for (int j = 0; j < teamTwo.getTeamPlayers().size(); j++) {
                    outFile << '\t' << teamOne.getTeamPlayers()[i].getName().c_str() << " tagged " << teamTwo.getTeamPlayers()[j].getName().c_str();
                    int totalTags = 0;
                    for (int t = 0; t < teamOne.getTeamPlayers()[i].getPlayerTags().size(); t++) {
                        if (teamOne.getTeamPlayers()[i].getPlayerTags()[t].getTaggedID() == teamTwo.getTeamPlayers()[j].getID()) {
                            totalTags++;
                        }
                    }
                    outFile << " " << totalTags << " times" << endl;
                }
                outFile << '\t' << teamOne.getTeamPlayers()[i].getName().c_str() << " had a total of " << teamOne.getTeamPlayers()[i].getNumTags() << " tags" << endl;
            }
        }
    }
    outFile << '\t' << teamOne.getTeamName().c_str() << ": " << teamOne.getTeamScore() << " points" << endl << endl;


    outFile << teamTwo.getTeamName().c_str() << endl;
    mostTags = 0;
    for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) {
        if (teamOne.getTeamPlayers()[i].getNumTags() > mostTags) {
            mostTags = teamOne.getTeamPlayers()[i].getNumTags();
        }
    }
    for (int n = mostTags; n > -1; n--) {
        for (int i = 0; i < teamTwo.getTeamPlayers().size(); i++) {
            if (teamTwo.getTeamPlayers()[i].getNumTags() == n) {
                for (int j = 0; j < teamOne.getTeamPlayers().size(); j++) {
                    outFile << '\t' << teamTwo.getTeamPlayers()[i].getName().c_str() << " tagged " << teamOne.getTeamPlayers()[j].getName().c_str();
                    int totalTags = 0;
                    for (int t = 0; t < teamTwo.getTeamPlayers()[i].getPlayerTags().size(); t++) {
                        if (teamTwo.getTeamPlayers()[i].getPlayerTags()[t].getTaggedID() == teamOne.getTeamPlayers()[j].getID()) {
                            totalTags++;
                        }
                    }
                    outFile << " " << totalTags << " times" << endl;
                }
                outFile << '\t' << teamTwo.getTeamPlayers()[i].getName().c_str() << " had a total of " << teamTwo.getTeamPlayers()[i].getNumTags() << " tags" << endl;
            }
        }
    }
    outFile << '\t' << teamTwo.getTeamName().c_str() << ": " << teamTwo.getTeamScore() << " points" << endl << endl;


    if (teamOne.getTeamScore() > teamTwo.getTeamScore()){
        outFile << "Winners: " << teamOne.getTeamName().c_str() << endl;
    }
    else if (teamTwo.getTeamScore() > teamOne.getTeamScore()) {
        outFile << "Winners: " << teamTwo.getTeamName().c_str() << endl;
    }
    else { //if team scores are the same
        outFile << "Winners: Teams Tied" << endl;
    }
}

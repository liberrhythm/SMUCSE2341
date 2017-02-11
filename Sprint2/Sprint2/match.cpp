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
        for (Player& p: teamOne.getTeamPlayers()) { //cycles through team one's team players
            if (p.getID() == tag.getTaggerID()) { //tests to see if player's id matches tagger's id
                p.addTag(tag); //if true, adds tag to player's vector of tags and updates player's information
            }
        }
        for (Player& p: teamTwo.getTeamPlayers()) { //does same thing for team two as for team one above
            if (p.getID() == tag.getTaggerID()) {
                p.addTag(tag);
            }
        }
        //tags.push_back(tag); //add created tag into Match object vector of tags
        inFile >> tagger;; //continue reading
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
    for (Player p: teamOne.getTeamPlayers()) { //will call sort in match constructor,
        if (p.getNumTags() > mostTags) {
            mostTags = p.getNumTags();
        }
    }
    for (int i = mostTags; i > -1; i--) {
        for (Player p: teamOne.getTeamPlayers()) {
            if (p.getNumTags() == i) {
                outFile << '\t' << p.getName().c_str() << " had a total of " << p.getNumTags() << " tags" << endl;
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
    for (int i = mostTags; i > -1; i--) {
        for (Player p: teamTwo.getTeamPlayers()) {
            if (p.getNumTags() == i) {
                outFile << '\t' << p.getName().c_str() << " had a total of " << p.getNumTags() << " tags" << endl;
            }
        }
    }
    outFile << endl;


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
    outputLowVerbosity(outFile); //outputs low verbosity summary at end
}

/*
void Match::outputHighVerbosity() {

}
*/

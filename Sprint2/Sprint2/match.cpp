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
        for (int i = 0; i < teamOne.getTeamPlayers().size(); i++) { //cycles through team one's players
            if (teamOne.getTeamPlayers()[i].getID() == tag.getTaggerID()) { //tests to see if player's id matches tagger's id
                teamOne.getTeamPlayers()[i].addTag(tag); //if true, adds tag to player's vector of tags
            }
        }
        for (int i = 0; i < teamTwo.getTeamPlayers().size(); i++) { //cycles through team two's players
            if (teamTwo.getTeamPlayers()[i].getID() == tag.getTaggerID()) {
                teamTwo.getTeamPlayers()[i].addTag(tag);
            }
        }
        inFile >> tagger; //continue reading
    }

    inFile.close(); //closes input file
}

//outputs points for each team and winner
void Match::outputLowVerbosity(ofstream& outFile) {
    if (teamTwo > teamOne) { //if team one name is before team two name in alphabet
        outputTeamScore(teamOne, outFile);
        outputTeamScore(teamTwo, outFile);
    }
    else {
        outputTeamScore(teamTwo, outFile);
        outputTeamScore(teamOne, outFile);
    }
    outputMatchWinner(outFile);
}

//outputs low verbosity information along with detailed information about total tags for each player
void Match::outputMedVerbosity(ofstream& outFile) {
    if (teamTwo > teamOne) { //if team one name is before team two name in alphabet
        //output team one name and short tag summary first, then team two
        outFile << teamOne.getTeamName().c_str() << endl;
        outputShortTagSummary(teamOne, outFile);
        outFile << teamTwo.getTeamName().c_str() << endl;
        outputShortTagSummary(teamTwo, outFile);
    }
    else {
        //output team two name and short tag summary first, then team one
        outFile << teamTwo.getTeamName().c_str() << endl;
        outputShortTagSummary(teamTwo, outFile);
        outFile << teamOne.getTeamName().c_str() << endl;
        outputShortTagSummary(teamOne, outFile);
    }

    if (teamTwo > teamOne) {
        outputBestScores(teamOne, outFile); //output formatted best score from team one
        outputBestScores(teamTwo, outFile); //same for team two
    }
    else {
        outputBestScores(teamTwo, outFile);
        outputBestScores(teamOne, outFile);
    }

    outputLowVerbosity(outFile); //outputs low verbosity summary at end
}

//outputs detailed information about each player's tags, total tags, team scores, and match winner
void Match::outputHighVerbosity(ofstream& outFile) {
    if (teamTwo > teamOne) { //if team one name is before team two name in alphabet
        //output team one name and long tag summary first, then team two
        outFile << teamOne.getTeamName().c_str() << endl;
        outputLongTagSummary(teamOne, teamTwo, outFile);
        outFile << endl;
        outFile << teamTwo.getTeamName().c_str() << endl;
        outputLongTagSummary(teamTwo, teamOne, outFile);
        outFile << endl;
    }
    else {
        //output team two name and long tag summary first, then team one
        outFile << teamTwo.getTeamName().c_str() << endl;
        outputLongTagSummary(teamTwo, teamOne, outFile);
        outFile << endl;
        outFile << teamOne.getTeamName().c_str() << endl;
        outputLongTagSummary(teamOne, teamTwo, outFile);
        outFile << endl;
    }

    outputMatchWinner(outFile);
}

//Write to output file formatted team name and score
void Match::outputTeamScore(Team t, ofstream& outFile) {
    outFile << t.getTeamName().c_str() << ": " << t.getTeamScore() << " points" << endl;
}

//Write to output file overall winners based on team score comparison
void Match::outputMatchWinner(ofstream& outFile) {
    if (teamOne.getTeamScore() > teamTwo.getTeamScore()){ //if team one score is greater than team two score
        outFile << "Winners: " << teamOne.getTeamName().c_str() << endl;
    }
    else if (teamTwo.getTeamScore() > teamOne.getTeamScore()) {
        outFile << "Winners: " << teamTwo.getTeamName().c_str() << endl;
    }
    else { //if team scores are the same
        outFile << "Winners: Teams Tied" << endl;
    }
}

//Write to output file best scoring players and their scores for each team
void Match::outputBestScores(Team t, ofstream& outFile) {
    outFile << "Best score from " << t.getTeamName().c_str() << ": ";
    int highestScore = 0;
    for (int i = 0; i < t.getTeamPlayers().size(); i++) {
        if (t.getTeamPlayers()[i].getScore() > highestScore) { //find highest score on team
            highestScore = t.getTeamPlayers()[i].getScore();
        }
    }
    for (int i = 0; i < t.getTeamPlayers().size(); i++) { //loop through players
        if (t.getTeamPlayers()[i].getScore() == highestScore) { //output formatted information about player with highest score
            outFile << t.getTeamPlayers()[i].getName().c_str();
            outFile << " (" << t.getTeamPlayers()[i].getScore() << " points)" << endl;
        }
    }
}

//Write to output file players' total of tags for each team by decreasing number of tags
void Match::outputShortTagSummary(Team t, ofstream& outFile) {
    int mostTags = 0;
    for (int i = 0; i < t.getTeamPlayers().size(); i++) {
        if (t.getTeamPlayers()[i].getNumTags() > mostTags) { //find most tags for one player on team
            mostTags = t.getTeamPlayers()[i].getNumTags();
        }
    }
    for (int n = mostTags; n > -1; n--) { //loop through most tags to least
        for (int i = 0; i < t.getTeamPlayers().size(); i++) { //loop through players
            if (t.getTeamPlayers()[i].getNumTags() == n) { //tests to see if current player has number of tags specified
                //outputs information about player and total tags
                outFile << '\t' << t.getTeamPlayers()[i].getName().c_str();
                outFile << " had a total of " << t.getTeamPlayers()[i].getNumTags() << " tags" << endl;
            }
        }
    }
    outFile << endl;
}

//Write to output file description of each tag for each player on each team as well as player totals
void Match::outputLongTagSummary(Team t1, Team t2, ofstream& outFile) {
    int mostTags = 0;
    for (int i = 0; i < t1.getTeamPlayers().size(); i++) {
        if (t1.getTeamPlayers()[i].getNumTags() > mostTags) { //find most tags for one player on team
            mostTags = t1.getTeamPlayers()[i].getNumTags();
        }
    }
    for (int n = mostTags; n > -1; n--) { //loop through most tags to least
        for (int i = 0; i < t1.getTeamPlayers().size(); i++) { //loop through players
            if (t1.getTeamPlayers()[i].getNumTags() == n) { //tests to see if current player has number of tags specified
                for (int j = 0; j < t2.getTeamPlayers().size(); j++) { //loops through other team's players
                    //outputs information about tagger and tagged players
                    outFile << '\t' << t1.getTeamPlayers()[i].getName().c_str();
                    outFile << " tagged " << t2.getTeamPlayers()[j].getName().c_str();
                    int totalTags = 0;
                    for (int t = 0; t < t1.getTeamPlayers()[i].getPlayerTags().size(); t++) { //counting total tags made by each tagger to each tagged
                        if (t1.getTeamPlayers()[i].getPlayerTags()[t].getTaggedID() == t2.getTeamPlayers()[j].getID()) {
                            totalTags++;
                        }
                    }
                    outFile << " " << totalTags << " times" << endl; //outputs total tags for a specific tagger-tagged pairing
                }
                outFile << '\t' << t1.getTeamPlayers()[i].getName().c_str();
                outFile << " had a total of " << t1.getTeamPlayers()[i].getNumTags() << " tags" << endl; //outputs total tags for player
            }
        }
    }
    outFile << '\t';
    outputTeamScore(t1, outFile); //calls function to output total team score
}

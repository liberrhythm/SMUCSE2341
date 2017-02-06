/*
Course Number:  CSE 2341
Programmer:     Sabrina Peng
Date:           2/5/17
Program Number: Sprint1
Purpose:        Defines and provides implementation for Team class member functions
Instructor: 	Mark Fontenot
TA:             Chris Henk, Kevin Queenan

Sources Consulted: Stack Overflow, C++ How to Program by Deitel, Deitel
*/

#include "team.h"
using namespace std;

//takes in command line argument for team file name to read in information
Team::Team(char* teamFileName) {
    ifstream inFile(teamFileName, ios::in);
    if (!inFile) {
        cerr << "Team file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    char tName[100]; //creates temporary char array for construction of String
    int teamSize;
    inFile.getline(tName, 100); //reads in characters including whitespace until newline delimiter reached or more than 100 chars read
    String teamName(tName); //creates String using char array as parameter
    inFile >> teamSize;

    setTeamName(teamName); //setting team information
    setTeamSize(teamSize);

    //primes read-in of player information for team
    int playerID;
    char pName[100];
    inFile >> playerID;

    while(!inFile.eof()) {
        inFile.getline(pName, 100);
        String playerName(pName);
        Player p(playerID, playerName); //instantiates Player objects using read-in information
        addPlayer(p); //adds Player objects to Team vector of Players

        inFile >> playerID;
    }

    teamScore = 0; //initializes team score to zero, updated in setTeamScores() function in Match class

    inFile.close();
}

//accessor for team name
String Team::getTeamName() {
    return teamName;
}

//mutator for team name
void Team::setTeamName(String tName) {
    teamName = tName;
}

//accessor for team size
int Team::getTeamSize() {
    return teamSize;
}

//mutator for team size
void Team::setTeamSize(int tSize) {
    teamSize = tSize;
}

//accessor for team score
int Team::getTeamScore() {
    return teamScore;
}

//mutator for team score
void Team::setTeamScore(int score) {
    teamScore = score;
}

//accessor for team vector of player objects
std::vector<Player> Team::getTeamPlayers() {
    return players;
}

//mutator for team vector of player objects based on parameter vector
void Team::setTeamPlayers(std::vector<Player> tPlayers) {
    for (Player p: tPlayers) {
        players.push_back(p);
    }
}

//adds players to team vector of player objects
void Team::addPlayer(Player player) {
    players.push_back(player);
}

//adds together total team score based on individual player scores
void Team::addTeamScore(int tagValue) {
    teamScore += tagValue;
}

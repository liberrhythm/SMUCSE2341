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

    teamScore = 0; //initializes team score to zero, updated when addPlayer function is called

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
    inFile >> ws;

    while(!inFile.eof()) {
        inFile.getline(pName, 100);
        String playerName(pName);
        Player p(playerID, playerName); //instantiates Player objects using read-in information
        addPlayer(p); //adds Player objects to Team vector of Players

        inFile >> playerID;
        inFile >> ws;
    }

    inFile.close();
}

//accessor for team name
String Team::getTeamName() const {
    return teamName;
}

//mutator for team name
void Team::setTeamName(String tName) {
    teamName = tName;
}

//accessor for team size
int Team::getTeamSize() const {
    return teamSize;
}

//mutator for team size
void Team::setTeamSize(int tSize) {
    teamSize = tSize;
}

//accessor for team score
int Team::getTeamScore() {
    int total = 0;
    for (int i = 0; i < players.size(); i++) {
        total += players[i].getScore();
    }
    return total;
}

//mutator for team score
void Team::setTeamScore(int score) {
    teamScore = score;
}

//accessor for team vector of player objects
Vector<Player>& Team::getTeamPlayers() {
    return players;
}

//mutator for team vector of player objects based on parameter vector
void Team::setTeamPlayers(Vector<Player> tPlayers) {
    for (int i = 0; i < tPlayers.size(); i++) {
        players.push_back(tPlayers[i]);
    }
}

//adds players to team vector of player objects
//increments team size and adds player's score to overall team score
void Team::addPlayer(Player p) {
    players.push_back(p);
}

void Team::addToScore(int tagScore) {
    teamScore += tagScore;
}

/*
//overloaded assignment operator to avoid default memberwise copy when assigning team objects to each other
Team& Team::operator= (const Team& team) {
    teamName = team.getTeamName();
    teamSize = team.getTeamSize();
    teamScore = team.getTeamScore();
    for (Player p: team.getTeamPlayers()) {
        players.push_back(p);
    }
    return *this;
}

//overloaded greater than operator to determine alphabetic order of team names
//returns true if later in alphabet than parameter
bool Team::operator> (const Team& team) {
    if (teamName > team.getTeamName()) {
        return true;
    }
    return false;
}
*/

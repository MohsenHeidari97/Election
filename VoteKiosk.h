#ifndef ELECTIONMAIN_VOTEKIOSK_H
#define ELECTIONMAIN_VOTEKIOSK_H


#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <unistd.h>
#include "Vote.h"
#include "DateTime.h"
#include "Candidate.h"
#include "Person.h"
#include "VoteBranch.h"


using namespace std;

class VoteKiosk {
public:
    VoteKiosk();

    ~VoteKiosk();

    VoteKiosk(int , int , string , int , int);

    void setVKId(int);

    void setVBId(int);

    void setKioskName(string);

    void setSumOfVotes(int);

    void setMaxCap(int);

    void searchById(int);

    int getVBId();

    int getVKId();

    string getKioskName();

    int getSumOfVotes();

    int getMaxCap();

    void setCandidates(Candidate *candidates);
    Candidate * getCandidates();

    void showVotePaper();

    void showCountOfVotesOfVoteKiosk();

    void chooseKiosk(int);

    int getKiosk();

    void showResults();


private:
    DateTime dt;
    Candidate *candidates;
    int vKId;
    int vBId;
    string kioskName;
    int sumOfVotes;
    int maxCap;
    int selectedId;

};

#endif //ELECTIONMAIN_VOTEKIOSK_H

#ifndef ELECTIONMAIN_VOTEBRANCH_H
#define ELECTIONMAIN_VOTEBRANCH_H

#include <iostream>
#include "VoteKiosk.h"
#include "Ministry.h"

using namespace std;

class VoteBranch  {
public:
    VoteBranch();

    ~VoteBranch();

    void setVBId(int);

    void setName(string);

    void setVKNumber(int);

    int getVKNumber();

    int getVBId();

    string getName();

    void showVoteKiosk();

    void setCandidates(Candidate *candidates);

    Candidate * getCandidates();

private:
    int vKNumber;
    int vBId;
    string name;
    Candidate *candidates;
};

#endif //ELECTIONMAIN_VOTEBRANCH_H

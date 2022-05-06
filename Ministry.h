#ifndef ELECTIONMAIN_MINISTRY_H
#define ELECTIONMAIN_MINISTRY_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Candidate.h"
#include "VoteBranch.h"

using namespace std;

class Ministry {
public:
    enum State {
        confirm, fail
    };
    State state;

    Ministry();

    ~Ministry();

    void setName(string);

    string getName();

    void showVoteBranch();

    void authenticateCandidate(Candidate *candidates, int, State);

    void countVotes();

    Candidate *getCandidates();

private:
    int cId;
    int vBNumber;
    string name;
    Candidate *candidates;


};

#endif //ELECTIONMAIN_MINISTRY_H

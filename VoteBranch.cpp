#include "VoteBranch.h"

VoteBranch::VoteBranch() {
    ;
}

VoteBranch::~VoteBranch() {
    ;
}

void VoteBranch::setVKNumber(int vKNumber) {
    this->vKNumber = vKNumber;
}

void VoteBranch::setVBId(int vBId) {
    this->vBId = vBId;
}

void VoteBranch::setName(string name) {
    this->name = name;
}

int VoteBranch::getVKNumber() {
    return vKNumber;
}

int VoteBranch::getVBId() {
    return vBId;
}

string VoteBranch::getName() {
    return name;
}

void VoteBranch::showVoteKiosk() {

    cout << "   *************  You are voting in ... branch  *************" << endl;

    fstream myFileRead;
    VoteKiosk votekiosks[getVKNumber()];
    int selectedId, counter = 0;

    myFileRead.open("voteKiosks.txt", ios::in);
    if (myFileRead.is_open()) {
        string nameOfVoteKiosk;
        int id, voteBranchId, sumOfVotes, maxCap;
        while (!myFileRead.eof()) {
            myFileRead >> id >> voteBranchId >> nameOfVoteKiosk >> sumOfVotes >> maxCap;
            if (vBId == voteBranchId) {
                cout << nameOfVoteKiosk << "   " << id << endl;
                votekiosks[counter].setVKId(id);
                votekiosks[counter].setVBId(voteBranchId);
                votekiosks[counter].setKioskName(nameOfVoteKiosk);
                votekiosks[counter].setSumOfVotes(sumOfVotes);
                votekiosks[counter].setMaxCap(maxCap);
                counter++;
            }
        }
        myFileRead.close();
    }

    bool flag = false;
    for (;;) {
        cout << "Enter the id of the kiosk : " << endl;
        cin >> selectedId;
        cout << endl;
        int i = 0;
        for ( ; i < getVKNumber(); i++) {
            if (selectedId == votekiosks[i].getVKId()) {
                if (votekiosks[i].getSumOfVotes() <= votekiosks[i].getMaxCap()) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            votekiosks[i].setCandidates(getCandidates());
            votekiosks[i].chooseKiosk(selectedId);
            votekiosks[i].showVotePaper();
            break;
        }
        system("cls");
        cout << "vote kiosk capacity is full !" << endl;
        cout << "please choose another vote kiosk ." << endl;

    }
}

void VoteBranch::setCandidates(Candidate candidates[]) {
    this->candidates = candidates;
}

Candidate *VoteBranch::getCandidates() {
    return candidates;
}
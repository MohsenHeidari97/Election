#include "VoteKiosk.h"

VoteKiosk::VoteKiosk() {
    ;
}

VoteKiosk::~VoteKiosk() {
    ;
}

VoteKiosk::VoteKiosk(int vKId, int vBId, string kioskName, int sumOfVotes, int maxCap) {
    this->vKId = vKId;
    this->vBId = vBId;
    this->kioskName = kioskName;
    this->sumOfVotes = sumOfVotes;
    this->maxCap = maxCap;
}

void VoteKiosk::searchById(int choosenCId) {
//    fstream myFile;
//    myFile.open("candidatesInfo.txt", ios::in);
//    int j = 0;
//
//    if (myFile.is_open()) {
//        while (!myFile.eof()) {
//            string fName, lName, tempFatherName, NCode, Lic;
//            int tempId, tempAge, k;
//
//
//            myFile >> fName >> lName >> tempFatherName >> NCode >> tempAge >> Lic >> tempId;
//
//            candidates[k].getFirstName();
//            candidates[k].getLastName();
//            candidates[k].getFatherName();
//            candidates[k].getNationalCode();
//            candidates[k].getAge();
//            candidates[k].getLicense();
//            candidates[k].getCId();
//            k++;
//        }
//    }
//
//
//    int cId;
//    for (int i = 0; i < 3; i++) {
//        cout << "teeeeeeeeeeeest33333";
//        cId = candidates[i].getAge();
//        if (cId == choosenCId) {
//            cout << "teeeeeeeeeeeest";
//            cout << endl << "Candidate is available : " << candidates[i].getFirstName() << " "
//                 << candidates[i].getLastName() << " " << candidates[i].getAge() << endl;
//        }
//    }
}

void VoteKiosk::setVKId(int vKId) {
    this->vKId = vKId;
}

void VoteKiosk::setVBId(int vBId) {
    this->vBId = vBId;
}

void VoteKiosk::setKioskName(string kioskName) {
    this->kioskName = kioskName;
}

void VoteKiosk::setSumOfVotes(int sumOfVotes) {
    this->sumOfVotes = sumOfVotes;
}

void VoteKiosk::setMaxCap(int maxCap) {
    this->maxCap = maxCap;
}

int VoteKiosk::getVBId() {
    return vBId;
}

int VoteKiosk::getVKId() {
    return vKId;
}

string VoteKiosk::getKioskName() {
    return kioskName;
}

int VoteKiosk::getMaxCap() {
    return maxCap;
}

int VoteKiosk::getSumOfVotes() {
    return sumOfVotes;
}

void VoteKiosk::showVotePaper() {
    string nationalCode, firstName, lastName;
    cout << "   ==>  Enter your national code  :" << endl;
    cin >> nationalCode;
    cout << nationalCode << endl;
    cout << "*************************************************" << endl;
    cout << "xxx   List of candidates you can vote :    xxx " << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Name : " << candidates[i].getFirstName() << "  " << candidates[i].getLastName() << " | "
             << candidates[i].getCId() << endl;
    }
            cout << endl;
            int CID;
            char n;
            cout << "Enter ID of the Candidate : ";
            cin >> CID;
            cout << "Enter the first name of the candidate : ";
            cin >> firstName;
            cout << "Enter the last name of the candidate : ";
            cin >> lastName;
            cout << "enter number 0 to confirm your vote : ";
            cin >> n;
            if (int(n) == 48) {

                cout << "Your vote registered successfully !" << endl;
                fstream writeFile;
                writeFile.open("votePaper.txt", ios::app);
                if (writeFile.is_open()) {
                    writeFile << nationalCode << " " << CID << " " << getVBId() << " " << getVKId() << " "
                              << dt.getCurrentDateTime() << endl;
                }
                writeFile.close();

                VoteKiosk vk[4];
                string nameOfVoteKiosk;
                int id, voteBranchId, sumOfVotes, maxCap, counter = 0;
                fstream readFile, writeFile2;
                readFile.open("voteKiosks.txt", ios::in);
                if (readFile.is_open()) {
                    while (!readFile.eof()) {
                        readFile >> id >> voteBranchId >> nameOfVoteKiosk >> sumOfVotes >> maxCap;
                        vk[counter].setVKId(id);
                        vk[counter].setVBId(voteBranchId);
                        vk[counter].setKioskName(nameOfVoteKiosk);
                        vk[counter].setSumOfVotes(sumOfVotes);
                        vk[counter].setMaxCap(maxCap);
                        counter++;
                    }
                    readFile.close();
                }
                counter = 0;
                writeFile2.open("voteKiosks.txt", ios::out);
                if (writeFile2.is_open()) {
                    for (; counter < 4; counter++) {
                        if (selectedId == vk[counter].getVKId()) {
                            vk[counter].sumOfVotes += 1;
                        }
                        if (counter == 3) {
                            writeFile2 << vk[counter].getVKId() << " " << vk[counter].getVBId() << " "
                                       << vk[counter].getKioskName() << " " << vk[counter].getSumOfVotes() << " "
                                       << vk[counter].getMaxCap();
                        } else
                            writeFile2 << vk[counter].getVKId() << " " << vk[counter].getVBId() << " "
                                       << vk[counter].getKioskName() << " " << vk[counter].getSumOfVotes() << " "
                                       << vk[counter].getMaxCap() << endl;
                    }
                    writeFile2.close();
                }
            } else {
                cout << "Try again!! Registration Failed .";
            }
            cout << "***********" << "the results will shown in 5 seconds : " << "*********" << endl;
            sleep(5);
            showResults();

}

void VoteKiosk::setCandidates(Candidate candidates[]) {
    this->candidates = candidates;
}

Candidate *VoteKiosk::getCandidates() {
    return candidates;
}

void VoteKiosk::showCountOfVotesOfVoteKiosk() {
    int vBid, vKid, tempVBId, tempVKId, CID, vKCounter;;
    string nationalCode, date;
    cout << " Enter the id of the vote branch : ";
    cin >> tempVBId;
    cout << " Enter the id of the vote branch : ";
    cin >> tempVKId;
    fstream readFile;
    readFile.open("votePaper.txt", ios::in);
    if (readFile.is_open()) {
        while (!readFile.eof()) {
            readFile >> nationalCode >> CID >> vBid >> vKid >> date;
            if ((tempVBId == vBid) && tempVKId == vKid) {
                vKCounter++;
            }
        }
        cout << "the votes of kiosk " << tempVKId << "of branch " << tempVBId << " : " << vKCounter;
    }
    readFile.close();
}

void VoteKiosk::chooseKiosk(int selectedId) {
    this->selectedId = selectedId;
}

int VoteKiosk::getKiosk() {
    return selectedId;
}

void VoteKiosk::showResults() {
    int vKId, vBId, sumOfVotes, maxCap, counter = 0;
    string vKName;
    VoteKiosk vk[4];
    fstream readFile2;
    readFile2.open("voteKiosks.txt", ios::in);
    if (readFile2.is_open()) {
        while (!readFile2.eof()) {
            readFile2 >> vKId >> vBId >> vKName >> sumOfVotes >> maxCap;
            vk[counter].setVKId(vKId);
            vk[counter].setVBId(vBId);
            vk[counter].setKioskName(vKName);
            vk[counter].setSumOfVotes(sumOfVotes);
            vk[counter].setMaxCap(maxCap);
            counter++;
        }
        readFile2.close();
    }
    int i = 0, sum1 = 0, sum2 = 0, sumOfAll;
    for (int i = 0; i < 4; i++) {
        if (vk[i].getVBId() == 1) {
            sum1 += vk[i].getSumOfVotes();

        } else if (vk[i].getVBId() == 2) {
            sum2 += vk[i].getSumOfVotes();
        }
    }
    sumOfAll = sum1 + sum2;
    cout << "sum of the branch Sabalan is : " << sum1 << endl;
    cout << "sum of the branch TehranPars is : " << sum2 << endl;
    cout << "sum of the all branches is : " << sumOfAll << endl;

}
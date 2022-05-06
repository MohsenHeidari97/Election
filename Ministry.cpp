#include "Ministry.h"

Ministry::Ministry() {
    ;
}

Ministry::~Ministry() {
    ;
}

void Ministry::setName(string name) {
    this->name = name;
}

string Ministry::getName() {
    return name;
}

void Ministry::showVoteBranch() {
    for (int j = 0; j < 2; j++) {

        cout << "   ************   Welcome to the Election   ************   " << endl;
        fstream myFileRead;
        string nameOfVoteBranch;
        int id, numberOfVoteKiosks, counter = 0;
        int selectedId;
        VoteBranch voteBranches[2];

        myFileRead.open("voteBranches.txt", ios::in);
        if (myFileRead.is_open()) {
            while (!myFileRead.eof()) {
                myFileRead >> nameOfVoteBranch >> id >> numberOfVoteKiosks;
                voteBranches[counter].setVBId(id);
                voteBranches[counter].setVKNumber(numberOfVoteKiosks);
                voteBranches[counter].setName(nameOfVoteBranch);
                cout << nameOfVoteBranch << "   " << id << endl;
                counter++;
            }

            myFileRead.close();
        }

        bool flag = false;
        for (;;) {
            cout << "Enter the id of the vote branch : " << endl;
            cin >> selectedId;
            cout << endl;
            int i = 0;
            for (; i < 2; i++) {
                if (selectedId == voteBranches[i].getVBId()) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                voteBranches[i].setCandidates(getCandidates());
                voteBranches[i].showVoteKiosk();
                cout << "The Final results will shown in 10 seconds : " << endl;
                sleep(10);
                cout << "*x*x*x**x*" << "The Final Results : " << "*x*x*x*x*x*x*" << endl;
                countVotes();
                break;
            }
            system("cls");
            cout << "selected Id is not correct !" << endl;
            cout << "please try again ." << endl;
        }
    }
}

void Ministry::authenticateCandidate(Candidate candidate[], int arraySize, State candidateState) {

    bool flag = false;
    fstream myFileRead, myFileWrite;

    for (int i = 0; i < arraySize; i++) {
        int candidateId;
        candidateId = i + 100;
        candidate[i].setCId(candidateId);
        cout << endl << "test of id : " << candidate[i].getCId();

        myFileRead.open("candidatesInfo.txt", ios::in);
        if (myFileRead.is_open()) {
            while (!myFileRead.eof()) {
                string fName, lName, tempFatherName, NCode, Lic;
                int tempId, tempAge;

                myFileRead >> fName >> lName >> tempFatherName >> NCode >> tempAge >> Lic >> tempId;
                if (NCode == candidate[i].getNationalCode()) {
                    flag = true;
                    break;
                }
            }
            myFileRead.close();
        }

        myFileWrite.open("candidatesInfo.txt", ios::app);
        if (myFileWrite.is_open()) {
            if (flag) {
                cout << endl << candidate[i].getFirstName() << candidate[i].getLastName() << ": You can not register"
                     << endl;
            } else {
                myFileWrite << candidate[i].getFirstName() << " ";
                myFileWrite << candidate[i].getLastName() << " ";
                myFileWrite << candidate[i].getFatherName() << " ";
                myFileWrite << candidate[i].getNationalCode() << " ";
                myFileWrite << candidate[i].getAge() << " ";
                myFileWrite << candidate[i].getLicense() << " ";
                myFileWrite << candidate[i].getCId() << " ";   // id
                cout << endl << candidate[i].getFirstName() << " " << candidate[i].getLastName() << "  "
                     << "Registered Successfully !" << endl;

            }
            candidates[i] = candidate[i];
            myFileWrite.close();
        }
    }
}

void Ministry::countVotes() {
    int sumOfC1 = 0;
    int sumOfC2 = 0;
    int sumOfC3 = 0;
    int sumOfC4 = 0;
    int invalidVotes = 0;
    int allVotes = 0;
    int validVotes = 0;
    string nationalCode, dateTime;
    int cId, vBId, vKId;

    fstream readFile;
    readFile.open("votePaper.txt", ios::in);
    if (readFile.is_open()) {
        while (!readFile.eof()) {
            readFile >> nationalCode >> cId >> vBId >> vKId >> dateTime;

            if (cId == 100) {
                sumOfC1 += 1;
            } else if (cId == 101) {
                sumOfC2 += 1;
            } else if (cId == 102) {
                sumOfC3 += 1;
            } else if (cId == 103) {
                sumOfC4 += 1;
            } else {
                invalidVotes += 1;
            }
        }
        validVotes = sumOfC1 + sumOfC2 + sumOfC3 + sumOfC4;
        allVotes = sumOfC1 + sumOfC2 + sumOfC3 + sumOfC4 + invalidVotes;
        cout << "number of all votes : " << allVotes << endl;
        cout << "number of valid votes : " << validVotes << endl;
        cout << "Number of invalid votes  : " << invalidVotes << endl;
        cout << "Votes of candidate * Mohsen H * : " << sumOfC1 << endl;
        cout << "Votes of candidate * Mohamad S * : " << sumOfC2 << endl;
        cout << "Votes of candidate * AmirAli j * : " << sumOfC3 << endl;
        cout << "Votes of candidate * Hasan Ab * : " << sumOfC4 << endl;
    }
}

Candidate *Ministry::getCandidates() {
    fstream myFileRead, myFileWrite;
    string firstName, lastName, fatherName, nationalCode, license;
    int age, id;
    candidates = new Candidate[4];
    int counter = 0;
    myFileRead.open("candidatesInfo.txt", ios::in);
    if (myFileRead.is_open()) {
        while (!myFileRead.eof()) {
            myFileRead >> firstName >> lastName >> fatherName >> nationalCode >> age >> license >> id;
            candidates[counter].setFirstName(firstName);
            candidates[counter].setLastName(lastName);
            candidates[counter].setFatherName(fatherName);
            candidates[counter].setNationalCode(nationalCode);
            candidates[counter].setAge(age);
            candidates[counter].setLicense(license);
            candidates[counter].setCId(id);
            counter++;

        }
        myFileRead.close();
    }

    return candidates;
}

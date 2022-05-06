#include "Vote.h"

Vote::Vote() {
    ;
}

Vote::Vote(string firstName , string lastName , string fatherName , string nationalCode , int age) : Person(firstName , lastName , fatherName , nationalCode , age) {
    ;
};

Vote::~Vote() {
    ;
}

void Vote::setCId(int cId) {
    this -> cId = cId;
}

void Vote::setVBId(int vBId) {
    this -> vBId = vBId;
}

void Vote::setVKId(int vKId) {
    this -> vKId = vKId;
}

void Vote::setVoterId(int voterId) {
    this -> voterId = voterId;
}

void Vote::setDate(Date date) {
    this -> date = date;
}

void Vote::setTime(Time time) {
    this -> time = time;
}

void Vote::saveVotePaper(string nationalCode , int voterId , int cId , int vKId , int vBId) {
    bool flag = false;
    fstream myFile;
    fstream myFile2;
    myFile.open("votePaper.txt",ios::in );
    if (myFile.is_open()) {

        while (!myFile.eof()) {
            string tempNCode;
            int tempVoterId , tempCId , tempVKId , tempVBId ;
            myFile >> tempNCode >> tempVoterId >> tempCId >> tempVKId >> tempVBId ;
            // cout<<fName;
            if (tempNCode == nationalCode) {
                flag = true;
                break;
            }
        }
        myFile.close();
    }

    myFile2.open("votePaper.txt" , ios:: app);
    if (myFile2.is_open()){
        if (flag) {
            cout <<endl  << "This national code already exists!!" << endl;
        }
        else {

            myFile2 << nationalCode<< " ";
            myFile2 << voterId << " ";
            myFile2 << cId << " ";
            myFile2 << vKId << " ";
            myFile2 << vBId << " ";

            cout << endl << "Vote Paper Registered Successfully !" <<endl;
        }
        myFile2.close();
    }
}

int Vote::getCId() {
    return cId;
}

int Vote::getVBId() {
    return vBId;
}

int Vote::getVKId() {
    return vKId;
}

int Vote::getVoterId() {
    return voterId;
}

Date Vote::getDate() {
    return date;
}

Time Vote::getTime() {
    return time;
}

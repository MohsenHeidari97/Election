#include "Candidate.h"
#include <fstream>
#include <ostream>
#include <stdio.h>

//Candidate::Candidate()  {
//
//}

Candidate::Candidate() : Person() {

}

Candidate::Candidate(string firstName, string lastName, string fatherName, string nationalCode,
                     int age, string license) : Person(firstName, lastName, fatherName,
                                                       nationalCode , age) {

    this ->license = license;
}

Candidate::~Candidate() {
    ;
}

void Candidate::setCId(int cId) {
    this-> cId = cId;
}

int Candidate::getCId() {
    return cId;
}

string Candidate::getLicense() {
    return license;
}
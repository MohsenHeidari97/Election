#ifndef ELECTIONMAIN_CANDIDATE_H
#define ELECTIONMAIN_CANDIDATE_H

#include <iostream>
#include <fstream>
#include <ostream>
#include "Person.h"

using namespace std;

class Candidate : public Person {
public:
    Candidate();
    Candidate(string);

    Candidate(string , string , string , string , int , string);

    ~Candidate();

    string getLicense();

    void setCId(int);

    int getCId();

private:
    string license;
    int cId;
};


#endif //ELECTIONMAIN_CANDIDATE_H

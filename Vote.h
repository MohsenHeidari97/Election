#ifndef ELECTIONMAIN_VOTE_H
#define ELECTIONMAIN_VOTE_H

#include <iostream>
#include <fstream>
#include "Time.h"
#include "Date.h"
#include "Person.h"

using namespace std;

class Vote : public Person {
public:

    Vote();

    Vote(string, string, string, string , int);

    ~Vote();

    void setCId(int);

    void setVBId(int);

    void setVKId(int);

    void setVoterId(int);

    void setDate(Date);

    void setTime(Time);

    void saveVotePaper(string ,int,int, int, int);

    int getCId();

    int getVBId();

    int getVKId();

    int getVoterId();

    Date getDate();

    Time getTime();

private:
    int voterId;
    int cId;
    int vBId;
    int vKId;
    string nationalCode;
    Time time;
    Date date;

};
#endif //ELECTIONMAIN_VOTE_H

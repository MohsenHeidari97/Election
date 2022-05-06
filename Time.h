#ifndef ELECTIONMAIN_TIME_H
#define ELECTIONMAIN_TIME_H

#include <iostream>
#include <ctime>

using namespace std;

class Time{
public:

    Time();

    ~Time();

    void setTime(int , int ,int );

    int getTime(string);

    int getAutoTime(string);

    void display();

    void displayAutoTime();

private:
    int hour , minute , second , h , m , s;
};

#endif //ELECTIONMAIN_TIME_H

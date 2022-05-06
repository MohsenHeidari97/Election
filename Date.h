#ifndef ELECTIONMAIN_DATE_H
#define ELECTIONMAIN_DATE_H

#include <iostream>
#include <ctime>

using namespace std;

class Date{
public:
    Date();

    ~Date();

    void displayAutoDate();

    void setDate(int , int , int);

    int getDate(string);

    int getAutoDate(string);

    void display();

private:
    int year , month , day ;
    int y, m , d ;
    void gregorianToJalali(int * , int * , int * , int , int , int);
};


#endif //ELECTIONMAIN_DATE_H
